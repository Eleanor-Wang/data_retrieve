//
//  stock.cpp
//  FP
//
//  Created by 汪念怡 on 4/23/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#include "stock.h"
#include <stdio.h>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

void stock::set_stock_price(string &URL){
    CURL *handle;
    curl_global_init(CURL_GLOBAL_ALL);
    CURLcode result;
    handle=curl_easy_init();  //returns a CURL easy handle for reuse in other easy functions
    
    if(handle)
    {
        curl_easy_setopt(handle, CURLOPT_URL, "http://ichart.yahoo.com/table.csv?s=spy&a=10&b=3&c=2014&d=04&e=29&f=2015&g=d&ignore=.csv"); // string to char
        result = curl_easy_perform(handle);
        double pricevalue;
        stock_price.push_back(pricevalue);
    }
    
    if (result == CURLE_OK) {
        curl_easy_cleanup(handle);
        curl_global_cleanup();
    }
}

void Stock::setAdj_Close_Stock_Price(string &URL) {
    struct MemoryStruct data;
    data.memory=NULL;
    data.size = 0;
    CURL *curl; // create pointer of curl operation
    curl_global_init(CURL_GLOBAL_ALL);
    CURLcode res; // indiactor that can be used to judge if opening url success or not
    //   const char *url2="http://ichart.yahoo.com/table.csv?s=goog&a=00&b=1&c=2010&d=03&e=25&f=2015&g=d&ignore=.csv"; //name of url
    curl=curl_easy_init();//init
    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, URL.c_str()); // string to char*
        curl_easy_setopt(curl, CURLOPT_ENCODING, "");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data2);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&data);
        res = curl_easy_perform(curl);
        stringstream sData;
        sData.str(data.memory);
        string Date;
        string sValue;
        double dValue = 0;
        string line;
        getline(sData, line);
        for (; getline(sData, line); ) {
            Date = line.substr (0,10); // Date (position,length)
            sValue = line.substr(line.find_last_of(',')+1); // adj_close
            dValue = strtod (sValue.c_str(), NULL); // string to double
            Adj_Close_Stock_Price.push_back(dValue); // add into vector
        }
    } // end of if(curl)
    if (res == CURLE_OK) {
        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }
}


void stock::set_daily_return(){
    int a = int(stock_price.size());
    for (int i = 0; i < a-1; i++)
    {
        daily_return.push_back((stock_price[i]-stock_price[i+1])/stock_price[i+1]);
    }
}

void stock::set_SPY_Return(download spy, stock stock_){
    spy.set_indexdate(int(spy.get_date_price().size()));
    int a = int(stock_price.size());
    for (int i = 0;i<spy.get_indexdate(); i++) {
        if (spy.get_date_price()[i].first == stock_.get_date_0()) {
            for(int j = 0; j<a-1; j++){
                SPY_return.push_back(spy.get_date_return()[i-30+j]);
            }
        }
    }

}

void stock::set_ab_return()
{
    int a = int(stock_price.size());
    for (int i = 0; i < a-1; i++)
    {
        ab_return.push_back((daily_return[i]-SPY_return[i]));
    }
}

void stock::set_flag(){
    double temp=(Ac_EPS-Es_EPS)/fabs(Es_EPS);
    if (temp>0.5) flag=1;
    else if (temp<-0.5) flag=-1;
    flag=0;
}    // how to rank the stocks?????




