//
//  download.cpp
//  FP
//
//  Created by 汪念怡 on 4/23/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#include "download.h"
#include <stdio.h>
#include <vector>
#include <iostream>

void download::set_date_price(){
    CURL *handle;     // create pointer of curl operation
    curl_global_init(CURL_GLOBAL_ALL);
    CURLcode result; // indiactor that can be used to judge if opening url success or not
//    const char *URL_SPY="http://ichart.yahoo.com/table.csv?s=spy&a=10&b=3&c=2014&d=04&e=29&f=2015&g=d&ignore=.csv";
    handle=curl_easy_init();  //returns a CURL easy handle for reuse in other easy functions
    
    if(handle)
    {
        curl_easy_setopt(handle, CURLOPT_URL, "http://ichart.yahoo.com/table.csv?s=spy&a=10&b=3&c=2014&d=04&e=29&f=2015&g=d&ignore=.csv"); // string to char
        result = curl_easy_perform(handle);
        string date;
        double pricevalue;
        date_price.push_back(make_pair(date, pricevalue)); // add into vector
    } // end of if(handel)
    
    if (result == CURLE_OK) {
        curl_easy_cleanup(handle);
        curl_global_cleanup();
    }
}

void download::set_date_return(){
    if (index>1){
        for (int i=1;i<index-1;i++){
            daily_return.push_back((date_price[i].second-date_price[i+1].second)/date_price[i+1].second);
        }
    }
}
