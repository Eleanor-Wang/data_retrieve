//
//  Handler.hpp
//  MarketData
//
//  Created by 汪念怡 on 17/04/16.
//  Copyright (c) 2016 汪念怡. All rights reserved.
//

#ifndef __MarketData__Handler__
#define __MarketData__Handler__

#include <stdio.h>
#include <iostream>
#include "curl.h"
#include <string>
#include "StockGroup.h"
#include "Stock.h"
#include <map>

class Handler
{
private:
    CURL * handle;
    std::string content;
    size_t filter_(char * data, size_t size, size_t n_memb);
public:
    ~Handler() {curl_easy_cleanup(handle); curl_global_cleanup();}
    void setup();
    static size_t filter(char * data, size_t size, size_t n_memb, void * f);
    void downloadData(std::string url);
    void clear() {content.clear();}
    std::string & get_content() {return content;}
	static void fillStock(std::map<std::string, Stock>& stocks, std::string ticker);
	static void fetchDataFromDatabase(StockGroup* g);
};

#endif /* defined(__MarketData__Handler__) */
