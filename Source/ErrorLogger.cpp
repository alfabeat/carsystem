

#include <iostream>
#include <fstream>
#include "ErrorLogger.h" 



ErrorLogger::~ErrorLogger() {
	outputstream.close();
}

void ErrorLogger::log(std::string msg) {
	outputstream.open("error.txt", std::ios::app);
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
		//	std::streamsize bytesWritten = outputstream.tellp();
		//	if (bytesWritten != sizeof(msg))
		//	{
		//		std::cout << "Could not read expected number of bytes" << std::endl;
		//	}
		//	else
		//	{
				// Displaying data
		outputstream << std::endl << msg <<  std::flush;
		ErrorLogger::~ErrorLogger();
		//		}
		//	}
	}

}