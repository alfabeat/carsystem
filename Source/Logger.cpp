//***********************************************************
//
//  File:        Logger.cpp  
//  Description: source code file 
//  Rev:         1
//  Created:     5 Jan 2019
//  Author:      Janusz Kulon, University of South Wales
//  email:       j.kulon@southwales.ac.uk 
//  web:         http://staff.glam.ac.uk/users/1032-jkulon
//  Tel:         +44 (0) 1443 654136
//
//
//***********************************************************


#include "Logger.h" 
#include <iostream>
#include <fstream>
using namespace std;


// constructor

class TxtFileLogger : public Logger {

	std::ofstream outputstream;
public:

	~TxtFileLogger();
	void log(std::string msg);
};

class ErrorLogger : public Logger {

	std::ofstream outputstream;
public:

	~ErrorLogger();
	void log(std::string msg);
};



class ConsoleLogger : public Logger {

	std::ofstream outputstream;
public:

	~ConsoleLogger();
	void log(std::string msg);
};



class LoggerDec : public Logger {
	uint16_t formatType;
	unique_ptr<Logger> contents;
	void log(string msg);
	string encryptDecypt(string toEncrypt);
public:
	LoggerDec(unique_ptr<Logger> contents, uint16_t formatType);
	virtual string formatMessage(string msg);
};
