#pragma once

#include "AuthenticationInfo.h" 
#include "Subject.h" 

#include "proofofid.h"


class Authenticator
{
	std::string encyptDecrypt(std::string toencrypt);
public:
	proofofid authenticateUser(Subject& s);
};

