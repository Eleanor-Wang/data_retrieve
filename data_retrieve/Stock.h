//
//  Stock.hpp
//  MarketData
//
//  Created by 汪念怡 on 17/04/16.
//  Copyright (c) 2016 汪念怡. All rights reserved.
//

#pragma once
#include <string>
#include <stack>
#include <vector>
#include <queue>

class Stock
{
	std::string ticker;
	std::string name;
	std::string date;
	double EPSReal;
	double EPSEstimated;
	std::stack<double> price;
	std::stack<double> AR;

public:
	Stock() {}
	Stock(std::string ticker, std::string date, double epsReal, double epsEstimated, std::string name)
		:ticker(ticker), date(date), EPSReal(epsReal), EPSEstimated(epsEstimated), name(name) {}
	std::string getTicker() { return ticker; }
	std::string getName() { return name; }
	std::string getDate() { return date; }
	double getEPSReal() { return EPSReal; }
	double getEPSEstimated() { return EPSEstimated; }
	std::stack<double>& getPrice() { return price; }
	std::stack<double>& getAR() { return AR; }
};

