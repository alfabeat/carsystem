//***********************************************************
//
//  File:        Subject.h  
//  Description: header file 
//  Rev:         1
//  Created:     10 Nov 2020
//  Author:      Janusz Kulon, University of South Wales
//  email:       j.kulon@southwales.ac.uk 
//  web:         http://staff.southwales.ac.uk/users/1032-jkulon
//  Tel:         +44 (0) 1443 654136
//
//
//***********************************************************

#pragma once
#include <string>

class Subject {
	std::string role;
	std::string proofid;


public:

	std::string getrole(void);
	void enterrole(void);
	std::string getproofofid(void);
	void setproofofid(std::string proof);
};





