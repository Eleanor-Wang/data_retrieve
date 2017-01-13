#pragma once
#include <map>
#include <vector>
#include <string>
#include "curl.h"
#include "StockGroup.h"

class FetchData
{
	std::string content;
	static size_t FetchData::fetch(char * data, size_t size, size_t nmemb, void * p);
	size_t FetchData::fetch_impl(char* data, size_t size, size_t nmemb);
	int FetchData::progress_func(void* ptr, double TotalToDownload, double NowDownloaded, double TotalToUpload, double NowUploaded);
public:
	int downloadData(std::map<std::string, Stock>& g, std::string ticker, std::string sDate, std::string eDate);
	void fetchDataFromDatabase(StockGroup* g);
};

