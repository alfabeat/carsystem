//***********************************************************
//
//  File:        Authenticator.cpp
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

#include "Authenticator.h" 
#include <time.h>  
#include <string>
#include <iostream> 

std::string Authenticator::encyptDecrypt(std::string toenrypt) {
	char key = 'A';
	std::string output = toenrypt;
	for (uint16_t i = 0; i < toenrypt.size(); i++) {
		output[i] = toenrypt[i] ^ key;
	}
	return output;
}

proofofid Authenticator::authenticateUser(Subject& subject)
{
	AuthenticationInfo ainfo;
	proofofid Proofofid;
	std::string role = subject.getrole();
	std::string pass;
	std::string token;
	std::cout << "\nEnter password :";
	std::cin >> pass;
	if (ainfo.validateUser(role, pass)) {

		std::cout << "\nLogged in!\n";
		token = encyptDecrypt(role + pass);
		Proofofid = proofofid(token);
		subject.setproofofid(token);
	}
	else {
		std::cout << "Invalid user role or password. Please try again.";
	}

	return Proofofid;

};

