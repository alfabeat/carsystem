#pragma once
#include "Model.h"
#include "View.h"

class Controller {
	Model model;
	View view;
	
public:
	void configureSensor(void);
	void readData(void);
	void accelatorstate(const int speed, const double breakdist);
	void Changelimit(void);
	void Retreave(void);
	void error_log(void);
	void run(void);
};

