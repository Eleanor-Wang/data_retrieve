//
//  calculation.cpp
//  FP
//
//  Created by 汪念怡 on 4/23/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#include "calculation.h"
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

void calculation::ini_AAR(int num){
    for (int i=0;i<num;i++){
        AAR_1.push_back(0);
        AAR_2.push_back(0);
        AAR_3.push_back(0);
    }
}

void calculation::set_AAR(int flag_, vector<double> ab_return_){
    int num = int(AAR_1.size()); // The dates# of the period
    switch (flag_) {
        case -1:
            for (int i=0; i<num; i++)
            {
                AAR_1[i] = AAR_1[i]*index_minus/(1+index_minus)+ab_return_[i]/(1+index_minus);
            }
            index_minus++;
            break;

        case 0:
            for (int i=0; i<num; i++)
    {
        AAR_2[i] = AAR_2[i]*index_meet/(1+index_meet)+ab_return_[i]/(1+index_meet);
    }
    index_meet++;
    break;
            
        case 1:
            for (int i=0; i<num; i++)
            {
                AAR_3[i] = AAR_3[i]*index_plus/(1+index_plus)+ab_return_[i]/(1+index_plus);
            }
            index_plus++;
            break;
}

    
    
    