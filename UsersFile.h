#ifndef USERSFILE_H
#define USERSFILE_H
#include <iostream>

#include "User.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UsersFile {
	string filenameWithUsers;

public:
	UsersFile(string FILENAME_WITH_USERS) : filenameWithUsers(FILENAME_WITH_USERS) {};
};

#endif