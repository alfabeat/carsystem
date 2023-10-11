//***********************************************************
//
//  File:        TxtFileLogger.cpp
//  Description: source code file 
//  Rev:         1
//  Created:     10 Nov 2020
//  Author:      Janusz Kulon, University of South Wales
//  email:       j.kulon@southwales.ac.uk 
//  web:         http://staff.southwales.ac.uk/users/1032-jkulon
//  Tel:         +44 (0) 1443 654136
//
//
//***********************************************************


#include <iostream>
#include <fstream>
#include "TxtFileLogger.h" 



TxtFileLogger::~TxtFileLogger() {
	outputstream.close();
}

void TxtFileLogger::log(std::string msg) {
	outputstream.open("txtfile.data", std::ios::app);
	if (outputstream.fail())
	{
		std::cout << "Could not open file" << std::endl;
	}
	else
	{
		//if (!outputstream.write((char*)&msg, sizeof(msg)))
		//{
		//	std::cout << "Could not read file" << std::endl;
		//}
		//else
		//{
			//std::streamsize bytesWritten = outputstream.tellp();
			//if (bytesWritten != sizeof(msg))
			//{
			//	std::cout << "Could not read expected number of bytes" << std::endl;
			//}
			//else
			//{
				// Displaying data
				outputstream << std::endl << msg   << std::flush;
				TxtFileLogger::~TxtFileLogger();
			//}
		//}
	}


}