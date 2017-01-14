//
//  Handler.cpp
//  MarketData
//
//  Created by 汪念怡 on 17/04/16.
//  Copyright (c) 2016 汪念怡. All rights reserved.
//
#include "Handler.h"
#include "Stock.h"
#include <numeric>
#include <fstream>
#include <sstream>

using namespace std;

void Handler::fetchDataFromDatabase(StockGroup* g) {
	ifstream data("database.csv");
	string line;
	int groupNumber{ 1 }, count{ 1 };
	while (getline(data, line))
	{
		stringstream lineStream(line);
		string cell;
		vector<string> s;
		while (getline(lineStream, cell, ','))
		{
			s.push_back(cell);
		}

		Stock stock(s[0], s[1], stod(s[2]), stod(s[3]), s[4]);
		g->setData(groupNumber, s[0], stock);
		if (count % 40 == 0) groupNumber++;
		count++;
	}
}

void Handler::setup()
{
    curl_global_init(CURL_GLOBAL_ALL);
    handle = curl_easy_init();
    curl_easy_setopt(handle, CURLOPT_WRITEDATA, this);
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, &Handler::filter);
}

size_t Handler::filter(char * data, size_t size, size_t n_memb, void * f)
{
    return static_cast<Handler*>(f)->filter_(data, size, n_memb);
}

size_t Handler::filter_(char * data, size_t size, size_t n_memb)
{
    content.append(data, size * n_memb);
    return size * n_memb;
}

void Handler::downloadData(std::string url)
{
    // result of the whole process
    CURLcode result;
    
    // if everything's all right with the easy handle...
    if(handle)
    {		//  point to Yahoo Finance Web page for APPL historical prices
        curl_easy_setopt(handle, CURLOPT_URL, url.c_str());
        
        // perform, then store the expected code in 'result'
        result = curl_easy_perform(handle);
        
        // Check for errors
        if(result != CURLE_OK)
        {	// if errors have occurred, tell us what is wrong with 'result'
            fprintf(stderr, "curl_easy_perform() failed: %s", curl_easy_strerror(result));
        }
    }
    else // if something's gone wrong with curl at the beginning
    {
        fprintf(stderr, "Curl init failed!\n");
    }
    
}


vector<string> split(string str, char del)
{
    vector<string> internal;
    stringstream ss(str);
    string item;
    
    while(getline(ss, item, del)) {
        internal.push_back(item);
    }
    
    return internal;
}

string createUrl(string name, string date)
{
    string url = "http://ichart.yahoo.com/table.csv?s=" + name;
    stringstream ss(date);  // i assume a YYYY-MM-DD format of the date string
    string start_dates[3], middle_dates[3], end_dates[3];
    string item;
    int i = 0;
    while(getline(ss, item, '/'))
    {
        if (item[0] == '0'){
            item = item[1];
        }
        middle_dates[i] = item;
        i++;
    }
    
    end_dates[2] = middle_dates[2];
    start_dates[2] = middle_dates[2];
	end_dates[1] = "01";
	start_dates[1] = "01";
    
    if(stoi(middle_dates[0])<=2)
    {
		start_dates[0] = "10";
		start_dates[2] = "2015";
    } else {
        start_dates[0] = to_string(stoi(middle_dates[0]) - 3);
    }
    
    if(stoi(middle_dates[0])>=10)
    {
		end_dates[0] = "02";
		end_dates[2] = "2016";
    } else {
        end_dates[0] = to_string(stoi(middle_dates[0]) + 4);
    }
    
    
    url += "&a=" + start_dates[0] + "&b=" + start_dates[1] + "&c=" + start_dates[2] +
    "&d=" + end_dates[0] + "&e=" + end_dates[1] + "&f=" + end_dates[2] + "&g=d&ignore=.csv";
    return url;
}

vector<double> getPrices(Handler & handler, string date)
{
    stringstream ss(handler.get_content());
    string item;
    vector<string> stock_dates;
    vector<double> stock_prices;
    getline(ss, item, '\n'); //get rid of the header
    
	int i = 0;
    while (getline(ss, item, '\n'))
    {
        vector<string> temp = split(item, ',');
        try {
			string t = to_string(stoi(temp[0].substr(5, 2))) + "/" + to_string(stoi(temp[0].substr(8, 2))) + "/" + temp[0].substr(0, 4);
            stock_dates.push_back(t);
            stock_prices.push_back(stod(temp[6]));
			i++;
        } catch (exception& e) {
            cout << item << endl;
            cout << e.what();
        }
        
    }
    int pos = (int) (find(stock_dates.begin(), stock_dates.end(), date) - stock_dates.begin());
    vector<double> new_prices;
    
    for (int i=pos-30; i<=pos+30; i++)
    {
        new_prices.push_back(stock_prices[i]);
    }
    
    
    return new_prices;
}

void Handler::fillStock(map<string, Stock>& stocks, string ticker)
{
	Stock& stock = stocks[ticker];
    Handler handler;
    handler.setup();
    string url;
    map<string, Stock>::iterator it; 
    url = createUrl(ticker, stock.getDate());
    handler.downloadData(url);
    stack<double>& sorted_prices = stock.getPrice();
    stack<double>& AR = stock.getAR();
        
    vector<double> prices = getPrices(handler, stock.getDate());
        
    for (int i= prices.size() - 1; i>=0; i--)
    {
        sorted_prices.push(prices[i]); // top is newest
    }
        
    handler.clear();
        
    url = createUrl("SPY", stock.getDate());
    handler.downloadData(url);
        
    vector<double> spy_prices = getPrices(handler, stock.getDate());
        
    for (int i= spy_prices.size()-2; i>=0; i--)
    {
		AR.push((prices[i] - prices[i + 1]) / prices[i + 1] - (spy_prices[i] - spy_prices[i + 1]) / spy_prices[i + 1]);
    }

        
    handler.clear();
}
