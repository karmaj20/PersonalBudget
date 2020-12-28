#ifndef USERSFILE_H
#define USERSFILE_H
#include <iostream>
#include <vector>

#include "User.h"
#include "Markup.h"
#include "XMLFile.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UsersFile: public XMLFile {

public:
	UsersFile(string filenameWithUsers) :
		XMLFile(filenameWithUsers) {};

	void addUserToFile(User user);
	vector <User> readUsersFromFile();
	void saveUsersToFile(vector <User>& users);
};

#endif