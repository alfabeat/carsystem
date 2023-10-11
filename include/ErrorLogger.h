#pragma once

#include "Logger.h" 
#include <fstream>

class ErrorLogger : public Logger {

	std::ofstream outputstream;
public:

	~ErrorLogger();
	void log(std::string msg);
};

