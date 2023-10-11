//***********************************************************
//
//  File:        AuthenticationInfo.cpp
//  Description: source code file 
//  Rev:         1
//  Created:     10 Nov 2020
//  Author:      Janusz Kulon, University of South Wales
//  email:       j.kulon@southwales.ac.uk 
//  web:         http://staff.southwales.ac.uk/users/1032-jkulon
//  Tel:         +44 (0) 1443 654136
//
//
//***********************************************************


#include "AuthenticationInfo.h"
#include "ErrorLogger.h"
#include <iostream> 
#include <fstream>
using namespace std;



AuthenticationInfo::AuthenticationInfo(void) {

users.insert(pair<string, string>("admin", "a"));

users.insert(pair<string, string>("man", "p"));

};

//determines whether a user-specified PIN matches PIN in Account
bool AuthenticationInfo::validateUser(string role, string pass)
{
	bool validUser = false;
	std::map<string, string>::iterator it;
	it = users.find(role);
	if (it != users.end()) {
		if (!(it->second.compare(pass))) {
			validUser = true;
		}
	}
	return validUser;
}

