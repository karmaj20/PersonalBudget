#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H
#include <iostream>

#include "UserManager.h"

using namespace std;

class PersonalBudget {
	UserManager userManager;

public:
	void signupUser();
	void loginUser();
};

#endif