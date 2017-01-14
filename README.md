
##Project Objective
* Earning research: select stocks from S & P 500 based on their earnings and EPS Estimate from Bloomberg terminal. 
* Retrieve historical price data from Yahoo Finance.
* Project Design: create classes and data structure such as vectors, matrix and maps. 
* Divide the project into modules and assign team members working on each module.
* Module Integration and Testing


##Project Explaination
* Prepare database containing information of 120 stocks including actual EPS, EPS estimate, earnings surprise, company’s name, and earning release date via Bloomberg Terminal, and divide them into 3 groups based on earnings surprise.
* Use libcurl library to download historical prices of each stock from yahoo finance.
* Calculate daily return of each stock and daily return of SPY to find abnormal return of each stock.
* Calculate Average Abnormal Returns (AAR) and Cumulative Average Abnormal Returns (CAAR) of each group of 40 stocks.
*Use gnuplot-cpp library to generate graphs of historical prices of each stock, of AAR and CAAR of each group, and of CAAR of all three groups.

##How to use
Build a project and Configure Microsoft Visual Studio for Using LibCurl(details in the advice part).

## While Processing 
* Actually after we start the demo, it starts fetch data from our database. 
* Then the program downloads historic prices from yahoo finance, calculates AAR and CAAR.
* While when user select the menu, it shows graphs(AAR&CAAR) of that stock.


##Additional Advices
### Dealing with LibCurl

* Download the latest version of LibCurl:
http://curl.haxx.se/latest.cgi?curl=win32-ssl-devel-msvc

* Create a new C++ project. Assume that solutions are built in Debug mode.

* Go to Properties > Configuration Properties > VC++ Directories > Include directories. Add the curl directory to be found in the include directory of the unzipped Libcurl file (Y:\NYU\Academic\6883 C++\lecture 6\libcurl\include\curl).

* Go to VC++ Directories > Library directories. Add the Debug directory containing curllib_static.lib, curllib.dll and curllib.lib (Y:\NYU\Academic\6883 C++\lecture 6\libcurl\lib\Debug).

* Go to Linker > General> Additional Library Directoris. Add the same Debug directory in previous step (Y:\NYU\Academic\6883 C++\lecture 6\libcurl\lib\Debug)..

* Go to Linker > Input> Additional Dependencies. Here, you have to add the curllib.lib file (Y:\NYU\Academic\6883 C++\lecture 6\libcurl\lib\Debug\curllib.lib). 

* Adding curllib.dll, libeay32.dll, openldap.dll, and ssleay32.dll in the Debug directory of your project. There all are to be found in the root directory of Libcurl. You also have to add libsasl.dll in this directory. Google for it.

* Open the curl.h file. Replace the line #include “curl/curlbuild.h” with #include “curlbuild.h”



##Acknowledge

* BackgroundWorker Class Sample for Beginners, 
http://www.codeproject.com/Articles/99143/BackgroundWorker-Class-Sample-for-Beginners
* C++ Example gnuplot 1, https://sites.google.com/site/bettereaclone/introduction/gnuplot/c-example-gnuplot-1


