#pragma once
#include <string>
enum class state { Off, On };
class accel {
	int accelate{ 0 };
	state curraccelstate = state::Off;
public:
	void on(void);
	void off(void);
	void increaceaccelation(void);
	state getState(void) const;

};

	class Model {
		int speed {5};
		std::string name;
		int samplingPeriod {500};
		int roadcondion {1};
		int speedlimit {60};
		double breakdist {0};
		accel acceler;
	public:
		Model(void);	

		void switchon(void);

		void switchoff(void);

		void accelatorstate(const int speed, const double breakdist);

		state getaccelState(void) const;

		const std::string getName(void) const;

		void setName(const std::string name);

		int getspeedlim(void) const;

		void setspeedlim(const int road);

		int getroadcondion(void) const;

		void setroadcondion(const int road);

		double getbreakdist(void) const;

		void setbreakdist(const int x, const int y);

		int getspeed(void) const;

		void setspeed(const int speed);

		void savedatatofile(int time, int speed, int road, double brea, state acc);
				
		void setSampling(const int sampling);

		int getSampling(void);

		void retriveDataFromDatabase(void);
	};



