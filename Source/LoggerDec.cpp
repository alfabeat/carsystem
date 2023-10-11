#include "LoggerDec.h"
#include <memory>
#include <iostream>
#include <fstream>

LoggerDec::LoggerDec(std::unique_ptr<Logger> logger, uint16_t aformatType)
	: contents{std::move(logger)}, formatType(aformatType) {
}

void LoggerDec::log(std::string msg) {
	msg = formatMessage(msg);
	contents->log(msg);
}

std::string LoggerDec::encryptDecypt(std::string toenrypt) {
	char key = 'A';
	std::string output = toenrypt;
	for (uint16_t i = 0; i < toenrypt.size(); i++) {
		output[i] = toenrypt[i] ^ key;
	}
	return output;
}

std::string LoggerDec::formatMessage(std::string msg) {
	std::cout << " Formatting: ";
	switch (formatType)
	{
	case 1:
		std::cout << " No format!" << std::endl;
		return msg;
		break;
	case 2: {
		std::cout << " HTML" << std::endl;
		return "<HTML><BODY> <b>"+ msg+"</b> </BODY></HTML>";
	}	
	break;
	case 3: {
		std::cout << " ENCRYPT" << std::endl;
		return encryptDecypt(msg) ;
	}
	break;
	default:
		std::cout << " Unknown format:" << std::endl;
		return msg;
		break;
	}
}
