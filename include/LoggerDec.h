#pragma once
#include "Logger.h"
#include <iostream>
#include <fstream>
using namespace std;

class LoggerDec : public Logger {
	uint16_t formatType;
	unique_ptr<Logger> contents;
	void log(string msg);
	string encryptDecypt(string toEncrypt);
public:
	LoggerDec(unique_ptr<Logger> contents, uint16_t formatType);
	virtual string formatMessage(string msg);
};
