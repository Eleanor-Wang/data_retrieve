//
//  stock.h
//  FP
//
//  Created by 汪念怡 on 4/23/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#ifndef stock_h
#define stock_h

#include <vector>
#include <iostream>
#include "download.h"

class stock{
private:
    string date_0;
    double Ac_EPS;
    double Es_EPS;
    vector<double> stock_price;
    vector<double> daily_return;
    vector<double> SPY_return;
    vector<double> ab_return;
    int flag;
    
public:
    void set_date_0(string date_0_){date_0=date_0_;};
    string get_date_0(){return date_0;};
    void set_Ac_EPS(double Ac_EPS_){Ac_EPS=Ac_EPS_;};
    double get_Ac_EPS(){return Ac_EPS;};
    void set_Es_EPS(double Es_EPS_){Es_EPS=Es_EPS_;};
    double get_Es_EPS(){return Es_EPS;};
    void set_stock_price(string &URL);
    void set_daily_return();
    
    void set_SPY_Return(download spy,stock stock_);
    
    void set_ab_return();
    vector<double> get_ab_Return();
    
    void set_flag();
    int get_flag(){return flag;};
    
};





#endif /* stock_hpp */
