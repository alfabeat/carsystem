//***********************************************************
//
//  File:        TxtFileLogger.h  
//  Description: header file 
//  Rev:         1
//  Created:     10 Nov 2020
//  Author:      Janusz Kulon, University of South Wales
//  email:       j.kulon@southwales.ac.uk 
//  web:         http://staff.southwales.ac.uk/users/1032-jkulon
//  Tel:         +44 (0) 1443 654136
//
//
//***********************************************************
#pragma once
#include "Logger.h" 
#include <fstream>

class TxtFileLogger : public Logger {

	std::ofstream outputstream;
public:

	~TxtFileLogger();
	void log(std::string msg);
};

