#include <string>
#include <iostream>
#include <iomanip>
#include "View.h"
#include "Choice.h" 
#include "ErrorLogger.h" 

using namespace std;

void View::printModelDetails(const Model& m) const {
	string x = "";
	if (m.getaccelState() == state::On) {
		x = "On";
	}
	else if (m.getaccelState() == state::Off) {
		x = "Off";
	}
	cout << "**************************************" << endl;
	cout << "Device Name: " << m.getName() << endl;
	cout << "Speed: " << m.getspeed() << endl;
	cout << "Road condtion: " << m.getroadcondion() << endl;
	cout << "Break distance: " << m.getbreakdist() << endl;
	cout << "accelerator state: " << x << endl;
	cout << "**************************************" << endl;
}

void View::displayHeader(void) {
	cout << " Time" << setw(6) <<" Speed" << setw(6) << " Road condtion" << setw(6) << " Break distance" << setw(6) << " Accelerator state" << endl;
	cout << "[minute]" << setw(6) <<" [KPH]" << setw(6) << " [Dry, Wet, Icy]" << setw(6) << " [Meters]" << setw(6) << " [On, Off]" << endl;
}

void View::displayData(int hour, int speed, int road, double breakdist, state accelor) {
	string x = "";
	if (accelor == state::On ) {
		 x = "On";
	}
	else if(accelor == state::Off) {
		 x = "Off";
	}
	ios init(NULL);
	init.copyfmt(cout);
	cout << setfill('0') << setw(2) << hour;
	cout.copyfmt(init);
	cout << setw(10) << speed << setw(10) << road << setw(15) << breakdist << setw(10) << x <<  endl;

}

void View::message(std::string s) {
	cout << s << endl;
}


void View::error_log(void) {
	char buffer[100];
	int input = 0;
	std::string msg;
	unique_ptr< Logger> loggerformatted;
	loggerformatted = make_unique<ErrorLogger>();
	try
	{
		ifstream myfile("error.txt"); // open a text file for reading
		// ifstream does not have exceptions by default. Let’s register 3 of them to the stream:
		myfile.exceptions(ifstream::eofbit | ifstream::failbit | ifstream::badbit);

			while (myfile.getline(buffer, 100))
			{
				
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
	
			while (!(cout << "Do you want to clear the error log? 1 for Yes or 0 for No" && std::cin >> input))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		
		if (input ==1) {
			ofstream myfile("error.txt", std::ofstream::out | std::ofstream::trunc);
			myfile.close();
		}
		}else{
		cout << "There was an error: " << e.what() << endl;
		msg = "There was an error on error log";
		loggerformatted->log(msg);
		}
	
	}
}

Choice View::mainMenu(void) {
	int input = 0;
	cout << "\nWelcome to the device simulation\n";
	cout << "Select from the following options\n";
	cout << "---------------------------------\n";
	cout << (int)(Choice::Information) << ": Information about the device\n";
	cout << (int)(Choice::Login) << ": Log in\n";
	cout << (int)(Choice::Read) << ": Read data\n";
	cout << (int)(Choice::Configure) << ": Configure\n";
	cout << (int)(Choice::Change_speed) << ": Change speed limit\n";
	cout << (int)(Choice::Retreave) << ": Retrieve data\n";
	cout << (int)(Choice::error_log) << ": Error Log\n";
	cout << (int)(Choice::Quit) << ": Quit\n";
	
	while (!(cout << "Your choice: " && std::cin >> input))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}


	return (Choice)input;
}
