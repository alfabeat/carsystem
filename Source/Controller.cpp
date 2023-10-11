
#include <string>
#include <iostream>
#include <thread>         // std::this_thread::sleep_for
#include <iomanip>
#include "Controller.h"
#include "Choice.h"
#include "Authenticator.h" 
#include "ErrorLogger.h" 
#include <fstream>
//#include "sec.h"


using namespace std;

void Controller::run(void) {
	Subject subject;
	Authenticator authenticator;
	proofofid Proofofid;
	Choice choice = Choice::Login;
	while (choice != Choice::Quit) {
		choice = view.mainMenu();
		switch (choice) {
		case Choice::Information: //Model deatils
			view.printModelDetails(model);
			break;
		case Choice::Login: 	

			subject.enterrole();

			cout << "Hello " << subject.getrole() << endl;

			Proofofid = authenticator.authenticateUser(subject);
			break;
		case Choice::Read: 
			readData();
			break;
		case Choice::Configure:
			if ((!Proofofid.getproof().empty()) & (Proofofid.getproof() == subject.getproofofid())) {
			configureSensor();
				
			}
			else
				cout << "\nSorry you need to be authenticated to access this content" << endl;			
			break;
		case Choice::Change_speed:
			if ((!Proofofid.getproof().empty()) & (Proofofid.getproof() == subject.getproofofid())) {
				Changelimit();

			}
			else
				cout << "\nSorry you need to be authenticated to access this content" << endl;
		
			break;
		case Choice::Retreave:
			
			if ((!Proofofid.getproof().empty()) & (Proofofid.getproof() == subject.getproofofid())) {
				Retreave();

			}
			else
				cout << "\nSorry you need to be authenticated to access this content" << endl;
			break;
		case Choice::error_log:
			
			if ((!Proofofid.getproof().empty()) & (Proofofid.getproof() == subject.getproofofid()) & subject.getrole()=="man") {
				view.error_log();

			}
			else
				cout << "\nSorry you need to be manufacturer to access this content" << endl;
			break;
		
		//
		//continue with menu options...
		//.............................
		default:

			cout << "\nSorry you have to enter a number in range" << endl;
			break;
		}
	}
}

void Controller::Changelimit(void){
	int lim = model.getspeedlim();
	view.message("\Current speed limit [KPM]:");
	view.message(std::to_string(lim));
	
	while (!(cout << "\nEnter new speed limit [KPH]:" && std::cin >> lim))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	
	model.setSampling(lim);
}

void Controller::Retreave(void) {
	char buffer[20];
	std::string msg;
	unique_ptr< Logger> loggerformatted;
	loggerformatted = make_unique<ErrorLogger>();
	view.displayHeader();
	try
	{
		ifstream myfile("txtfile.data"); // open a text file for reading
		// ifstream does not have exceptions by default. Let’s register 3 of them to the stream:
		myfile.exceptions(ifstream::eofbit | ifstream::failbit | ifstream::badbit);
	
			while (myfile)
			{
				myfile.getline(buffer, 20);
				cout << buffer << endl;
			}

		

		myfile.close();
	}
	catch (exception e)
	{
		if (strstr(e.what(), "eofbit") != NULL)
		{
			cout << buffer << endl;
			cout << "END OF FILE REACHED" << endl;
		}
		else {
	cout << "There was an error: " << e.what() << endl;
		msg = "There was an error on retrieve ";
		loggerformatted->log(msg);
		}
	
	}
}




void Controller::readData(void) {
	srand(time(0));
	int speed = model.getspeed();
	int roadcon = model.getroadcondion();
	double breakdis = model.getbreakdist();
	state accelstate = model.getaccelState();
	string msg= "";
	view.displayHeader();
	int random = 0;	
	random = (rand() % 3) +1;
	
	 model.setroadcondion(random );	
	for (int i = 1; i <= 24; i++) {
		random = (rand() % 6);

		model.setspeed(speed-random);
		speed = model.getspeed();
		roadcon = model.getroadcondion();
		model.setbreakdist(speed, roadcon );
		breakdis = model.getbreakdist();
		model.accelatorstate(speed, breakdis);
		
		speed = model.getspeed();
	
		state accelstate = model.getaccelState();
		model.savedatatofile(i, speed, roadcon, breakdis, accelstate);
		view.displayData(i, speed, roadcon, breakdis, accelstate);
		std::this_thread::sleep_for(std::chrono::milliseconds(model.getSampling()));
	}
}

void Controller::configureSensor(void){
	int samplingPeriod = model.getSampling();
	view.message("\Current sampling Period [ms]:");
	view.message(std::to_string(samplingPeriod));
	view.message("\nEnter new sampling Period [ms]:");
	while (!(cout << "\nEnter new sampling Period [ms]:" && std::cin >> samplingPeriod))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	
	model.setSampling(samplingPeriod);
}