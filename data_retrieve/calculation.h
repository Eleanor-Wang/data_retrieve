//
//  calculation.h
//  FP
//
//  Created by 汪念怡 on 4/23/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#ifndef calculation_h
#define calculation_h

#include <vector>
#include <iostream>
using namespace std;

class calculation{
private:
    //Initialization
    int index_minus = 0; // The # of firms that missed the estimate.
    int index_meet = 0;
    int index_plus = 0;
    
    vector<double> AAR_1; // The AAR for firms that missed.
    vector<double> AAR_2;
    vector<double> AAR_3;
    
    vector<double> CAAR_1; // The CAAR for firms that missed.
    vector<double> CAAR_2;
    vector<double> CAAR_3;
    
public:
    void ini_AAR(int Num); // Initialization of AAR
    void set_AAR(int flag_, vector<double> ab_return_);
    void set_CAAR();
    vector<double> get_CAAR1();
    vector<double> get_CAAR2();
    vector<double> get_CAAR3();
    
};


#endif /* calculation_h */
