#include "Model.h"
#include "TxtFileLogger.h" 
#include "ConsoleLogger.h" 
#include "LoggerDec.h"
#include "sec.h"
#include <fstream>

	Model::Model(void) { retriveDataFromDatabase(); }
	void accel::on(void) {
		curraccelstate = state::On;
		
	}
	void accel::off(void) {
		curraccelstate = state::Off;

	}
	void accel::increaceaccelation(void) {

		accelate = safeadd(accelate, 10);
	}
	state accel::getState(void) const {
		return curraccelstate;
	}

	void Model::switchon(void){
		acceler.on();
	}

	void Model::switchoff(void) {
		acceler.off();
	}

	void Model::accelatorstate(const int speed, const double breakdist) {
		if (speed >= speedlimit || breakdist > 70) {
			switchoff();
			setspeed(safemin(speed , 5));
		}
		else if (speed <= safemin(speedlimit, 10) || breakdist <70) {
			switchon();
			setspeed(safeadd(speed , 15));
		}
	}
	int Model::getspeedlim(void) const {
		return speedlimit;
	}

	void Model::setspeedlim(const int lim) {
		speedlimit = lim;
	}


	state Model::getaccelState(void) const {
		return acceler.getState();
	}

	const std::string Model::getName(void) const {
		return this->name;
	}
	void Model::setName(const std::string name) {
		this->name = name;
	}
	int Model::getroadcondion(void) const {
		return roadcondion;
	}

	void Model::setroadcondion(const int road){
		roadcondion = road;
	}

	double Model::getbreakdist(void) const {
		return breakdist;
	}

	void Model::setbreakdist(const int x, const int y) {
		double brea = 0;
		switch (y) {
		case (1):
			brea = x * 0.0005;
			break;
		case (2):
			brea= (x * 0.0005)*2;
			break;
		case (3):
			brea = (x * 0.0005)*5;
			break;
		}
		brea = safeag(brea, 1000);
		breakdist = brea;
	}

	int Model::getspeed(void) const {
		return speed;
	}
	void Model::setspeed(const int t) {
		speed = t;
	}
	void Model::setSampling(const int sampling) {
		samplingPeriod = sampling;
	}
	int Model::getSampling(void) {
		return samplingPeriod;
	}


	void Model::savedatatofile(int time, int speed, int road, double brea, state acc) {
		std::string msg;
		unique_ptr< Logger> loggerformatted;
		loggerformatted = make_unique<TxtFileLogger>();
		msg += std::to_string(time);
		msg += " ";
		msg += std::to_string(speed);
		msg += " ";
		msg += std::to_string(road);
		msg += " ";
		msg += std::to_string(brea);
		msg += " ";
		msg += std::to_string((int)acc);
		loggerformatted->log(msg);
	}

	void Model::retriveDataFromDatabase(void) {
		setName("Car");
		setspeed(5);
	}


