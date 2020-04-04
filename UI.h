#pragma once
#include"Service.h"
#include<string>
#include<time.h>
#include"WatchList.h"
using namespace std;

class UI
{
private:
	WatchList myWl;
	Service service;
	std::string Mode;
	bool err; //true when input data is not valid,false after handeling the data

public:
	UI(const Service& s) : service(s), Mode(""), err(false) {}

	void run();
	void setMode(const std::string& m) { Mode = m; }

private:
	void init();
	void printMenu();
	const std::string readTitle();
	const std::string readSection();
	const Date readDate();
	const std::string readSource();
	const unsigned int readAccess();

};

