#pragma once
#include <string>
#include "Model.h"
#include "Choice.h" 
#include <fstream>

class View {
public:
	void printModelDetails(const Model &m) const;
	Choice mainMenu(void);
	void displayData(int hour, int speed, int road, double breakdis, state accelor);
	void displayHeader(void);
	void error_log();
	void message(std::string s);
};