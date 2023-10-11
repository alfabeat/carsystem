
#include <string>
#include <iostream>
#include <thread>         // std::this_thread::sleep_for
#include "Controller.h"
#include "Choice.h"
#include "Authenticator.h"


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
		//
		//continue with menu options...
		//.............................
		default:
			break;
		}
	}
}

void Controller::accelatorstate(const int speed, const double breakdist) {
	if (speed <=50) {
		model.switchon();
		model.setspeed(speed+ 10);
	}
	else if (speed>= 60) {
		model.switchoff();
		model.setspeed(speed - 5);
	}
}

void Controller::readData(void) {
	int speed = model.getspeed();
	int roadcon = model.getroadcondion();
	double breakdis = model.getbreakdist();
	state accelstate = model.getaccelState();
	
	view.displayHeader();
	int random = 0;
	for (int i = 1; i <= 24; i++) {
		random = (rand() % 6);
		if (random <= 3) {
			roadcon = 1;
		}else{
			roadcon = 2;
		}
		model.setspeed(speed-random);
		speed = model.getspeed();
		//model.setroadcondion(roadcon );		
		accelatorstate(speed, breakdis);
		model.setbreakdist(speed, roadcon );
		speed = model.getspeed();
		roadcon = model.getroadcondion();
		breakdis = model.getbreakdist();
		state accelstate = model.getaccelState();
		view.displayData(i, speed, roadcon, breakdis, accelstate);
		std::this_thread::sleep_for(std::chrono::milliseconds(model.getSampling()));
	}
}

void Controller::configureSensor(void){
	int samplingPeriod = model.getSampling();
	view.message("\Current sampling Period [ms]:");
	view.message(std::to_string(samplingPeriod));
	view.message("\nEnter new sampling Period [ms]:");
	cin >> samplingPeriod;
	model.setSampling(samplingPeriod);
}