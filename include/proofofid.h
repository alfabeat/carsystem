#pragma once
#include <utility>
#include <sstream>
#include <string>
class proofofid {
	std::string proofid;
public:
	proofofid(void) {};
	proofofid(std::string);
	std::string getproof(void);
	void setfproof(std::string);

};