//***********************************************************
//
//  File:        Subject.cpp
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



#include "Subject.h" 

#include <iostream> 




void Subject::enterrole(void) {
	std::cout << "\nEnter Role :";
	std::cin >> role;
}



std::string Subject::getrole(void) {
	return role;
};
void Subject::setproofofid(std::string proof) {
	proofid = proof;
}
std::string Subject::getproofofid(void) {
	return proofid;
}





