#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <windows.h>
#include <vector>

#include "User.h"

using namespace std;

class UserManager {
	int idLoggedUser;
	vector<User> users;
	User getNewUserData();
	int loadNewUserId();
	bool isLoginExist(string login);

public:
	void signupUser();
	int loginUser();
	void logoutUser();
	bool isUserLogged();
};

#endif