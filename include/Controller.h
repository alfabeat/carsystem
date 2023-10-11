#pragma once
#include "Model.h"
#include "View.h"


enum LoggerType { L_TEXT_FILE = 1, L_BIN_FILE, L_CONSOLE };
enum formatType { NO_FORMAT = 1, HTML_FORMAT, ENC_FORMAT };

class Controller {
	Model model;
	View view;

public:
	void configureSensor(void);
	void readData(void);
	void Changelimit(void);
	void Retreave(void);	
	void run(void);
};

