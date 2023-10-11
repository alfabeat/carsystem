//***********************************************************
//
//  File:        AuthenticationInfo.h  
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


#include <utility>
#include <sstream>
#include <string>
#include <map>

class AuthenticationInfo
{

	std::map<std::string, std::string> users;

	public:
	
	
	AuthenticationInfo(void); // constructor sets attributes 
	bool validateUser(std::string role, std::string pass);
};



