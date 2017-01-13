//
//  download.hpp
//  FP
//
//  Created by 汪念怡 on 4/23/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#ifndef download_h
#define download_h

#include <vector>
#include <iostream>
#include "curl/curl.h"
#include <memory.h>
using namespace std;

class download{
private:
    int index;
    vector<pair<string,double>> date_price;
    vector<double> daily_return;
public:
    int get_indexdate(){return index;}
    void set_indexdate(int index_){index=index_;}
    vector<pair<string,double>> get_date_price(){return date_price;}
    void set_date_price();
    vector<double> get_date_return(){return daily_return;};
    void set_date_return();
};



#endif /* download_h */
