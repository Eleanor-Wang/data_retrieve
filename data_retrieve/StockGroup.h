#pragma once
#include <map>
#include <string>
#include "Stock.h"

class StockGroup
{
	std::map<std::string, Stock> group1;
	std::map<std::string, Stock> group2;
	std::map<std::string, Stock> group3;
	
public:
	std::vector<std::vector<double>> matrix;
	void setData(int groupNum, std::string name, Stock stock) {
		if (groupNum == 1)
			this->group1[name] = stock;
		else if (groupNum == 2)
			this->group2[name] = stock;
		else if (groupNum == 3)
			this->group3[name] = stock;
	}
	std::map<std::string, Stock>& getGroup(int groupNum) {
		if (groupNum == 1)
			return group1;
		else if (groupNum == 2)
			return group2;
		else if (groupNum == 3)
			return group3;
	}

};

