#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <windows.h>
#include <vector>

#include "User.h"
#include "UsersFile.h"

using namespace std;

class UserManager {
	int idLoggedUser;
	vector<User> users;

	User getNewUserData();
	int loadNewUserId();
	bool isLoginExist(string login);
	UsersFile usersFile;

public:
	UserManager(string filenameWithUsers) : usersFile(filenameWithUsers) {
		users = usersFile.readUsersFromFile();
	};
	void signupUser();
	int loginUser();
	void logoutUser();
	bool isUserLogged();
	void changePasswordLoggedUser();
	void saveUsersToFile();
	void displayUsers();
	int loadIdLoggedUser();
};

#endif