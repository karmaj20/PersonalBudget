#ifndef USERSFILE_H
#define USERSFILE_H
#include <iostream>
#include <vector>

#include "User.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UsersFile {
	const string FILENAME_WITH_USERS;

public:
	UsersFile(string filenameWithUsers) :
		FILENAME_WITH_USERS(filenameWithUsers) {};

	void addUserToFile(User user);
	vector <User> readUsersFromFile();
	void saveUsersToFile(vector <User>& users);
};

#endif