//
//  FetchData.cpp
//  MarketData
//
//  Created by 汪念怡 on 17/04/16.
//  Copyright (c) 2016 汪念怡. All rights reserved.
//

#include "FetchData.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <Windows.h>

using namespace std;

size_t FetchData::fetch(char * data, size_t size, size_t nmemb, void * p)
{
	return static_cast<FetchData*>(p)->fetch_impl(data, size, nmemb);
}

size_t FetchData::fetch_impl(char* data, size_t size, size_t nmemb)
{
	this->content.append(data, size * nmemb);
	return size * nmemb;
}

int FetchData::progress_func(void* ptr, double TotalToDownload, double NowDownloaded, double TotalToUpload, double NowUploaded)
{
	return 0;
}


void FetchData::fetchDataFromDatabase(StockGroup* g) {
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

void storePrice(std::map<std::string, Stock>& g, string ticker, string rawData, string type);
void storeSPY(stack<double>& v, string rawData, string type);

int FetchData::downloadData(std::map<std::string, Stock>& g, string ticker, string sDate, string eDate)
{
	CURL* handle;
	CURLcode result;
	curl_global_init(CURL_GLOBAL_ALL);
	handle = curl_easy_init();

	stack<double> SPY;
	vector<string> startDate(0);
	vector<string> endDate(0);
	stringstream ss(sDate);
	string sTemp{};
	while (getline(ss, sTemp, '/'))
		startDate.push_back(sTemp);
	stringstream ss2(g[ticker].getDate());
	while (getline(ss2, sTemp, '/'))
		endDate.push_back(sTemp);

	string link{ "http://ichart.yahoo.com/table.csv?s=" };
	string link2{ "http://ichart.yahoo.com/table.csv?s=" };
	if (handle)
	{
		link += ticker + "&a=" + to_string(stoi(startDate[0]) - 1) + "&b=" + startDate[1] + "&c=" + startDate[2] +
			"&d=" + to_string(stoi(endDate[0]) - 1) +
			"&e=" + endDate[1] + "&f=" + endDate[2] + "&g=d&ignore=.csv";
		link2 += "SPY&a=" + to_string(stoi(startDate[0]) - 1) + "&b=" + startDate[1] + "&c=" + startDate[2] +
			"&d=" + to_string(stoi(endDate[0]) - 1) +
			"&e=" + endDate[1] + "&f=" + endDate[2] + "&g=d&ignore=.csv";

		curl_easy_setopt(handle, CURLOPT_URL, link.c_str());

		/* but in that case we also tell libcurl to follow redirection */
		//curl_easy_setopt(handle, CURLOPT_FOLLOWLOCATION, 1L);
		curl_easy_setopt(handle, CURLOPT_WRITEDATA, this);
		curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, &FetchData::fetch);
		//curl_easy_setopt(handle, CURLOPT_PROGRESSFUNCTION, progress_func);

		result = curl_easy_perform(handle);

		/* Check for errors */
		if (result != CURLE_OK)
		{
			/* if errors have occured, tell us wath's wrong with 'result'*/
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(result));

			return 1;
		}
	}
	/* if something's gone wrong with curl at the beginning, we'll appriciate that piece of code */
	else
	{
		fprintf(stderr, "Curl init failed!\n");

		return 1;
	}

	storePrice(g, ticker, content, "b");
	content = "";

	curl_easy_setopt(handle, CURLOPT_URL, link2.c_str());
	result = curl_easy_perform(handle);
	storeSPY(SPY, content, "b");

	startDate.clear();
	endDate.clear();
	stringstream ss3(g[ticker].getDate());
	while (getline(ss3, sTemp, '/'))
		startDate.push_back(sTemp);
	stringstream ss4(eDate);
	while (getline(ss4, sTemp, '/'))
		endDate.push_back(sTemp);
	link = "http://ichart.yahoo.com/table.csv?s=";
	link2 = "http://ichart.yahoo.com/table.csv?s=";
	link += ticker + "&a=" + to_string(stoi(startDate[0]) - 1) + "&b=" + startDate[1] + "&c=" + startDate[2] +
		"&d=" + to_string(stoi(endDate[0]) - 1) +
		"&e=" + endDate[1] + "&f=" + endDate[2] + "&g=d&ignore=.csv";
	link2 += "SPY&a=" + to_string(stoi(startDate[0]) - 1) + "&b=" + startDate[1] + "&c=" + startDate[2] +
		"&d=" + to_string(stoi(endDate[0]) - 1) +
		"&e=" + endDate[1] + "&f=" + endDate[2] + "&g=d&ignore=.csv";

	curl_easy_setopt(handle, CURLOPT_URL, link.c_str());
	result = curl_easy_perform(handle);

	storePrice(g, ticker, content, "f");
	content = "";


	curl_easy_setopt(handle, CURLOPT_URL, link2.c_str());
	result = curl_easy_perform(handle);
	storeSPY(SPY, content, "f");

	

	//------- Calculate AAR -------
	stack<double> stockReturn;
	stack<double> SPYReturn;
	stack<double> sPrice(g[ticker].getPrice());

	double sr1{ sPrice.top() };
	sPrice.pop();
	double SPYr1{ SPY.top() };
	SPY.pop();
	while (!sPrice.empty()) {
		double sr2{ sPrice.top() };
		stockReturn.push((sr1 - sr2) / sr2);
		sr1 = sPrice.top();
		sPrice.pop();


		double SPYr2{ SPY.top() };
		SPYReturn.push((SPYr1 - SPYr2) / SPYr2);
		SPYr1 = SPY.top();
		SPY.pop();
	}

	while (stockReturn.size() != 0) {
		g[ticker].getAR().push(stockReturn.top() - SPYReturn.top());
		stockReturn.pop();
		SPYReturn.pop();
	}

	/* cleanup since you've used curl_easy_init */
	curl_easy_cleanup(handle);

	/* this function releases resources acquired by curl_global_init() */
	curl_global_cleanup();
}

void storePrice(map<string, Stock>& g, string ticker, string rawData, string type) {
	stringstream data(rawData);
	string line{};

	vector<double> price(0);
	while (getline(data, line))
	{
		stringstream lineStream(line);

		string cell{};
		vector<string> s(0);
		while (getline(lineStream, cell, ','))
		{
			s.push_back(cell);
		}

		if (s[6] != "Adj Close")
			price.push_back(stod(s[6]));
	}

	// top is newest
	if (type == "b") {
		for (int i = 30; i >= 0; i--)
			g[ticker].getPrice().push(price[i]);

	}
	else if (type == "f") {
		for (int i = price.size() - 2; i >= price.size() - 31; i--)
			g[ticker].getPrice().push(price[i]);
	}
}

void storeSPY(stack<double>& v, string rawData, string type) {
	stringstream data(rawData);
	string line{};

	vector<double> price(0);
	while (getline(data, line))
	{
		stringstream lineStream(line);

		string cell{};
		vector<string> s(0);
		while (getline(lineStream, cell, ','))
		{
			s.push_back(cell);
		}

		if (s[6] != "Adj Close")
			price.push_back(stod(s[6]));
	}

	if (type == "b") {
		for (int i = 30; i >= 0; i--)
			v.push(price[i]);

	}
	else if (type == "f") {
		for (int i = price.size() - 2; i >= price.size() - 31; i--)
			v.push(price[i]);	
	}
	
}
