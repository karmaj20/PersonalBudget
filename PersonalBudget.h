#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H
#include <iostream>

#include "UserManager.h"
#include "FinanceManager.h"

using namespace std;

class PersonalBudget {
	UserManager userManager;
	FinanceManager financeManager;

public:
	PersonalBudget(string filenameWithUsers, string filenameWithIncomes) :
		userManager(filenameWithUsers), financeManager(filenameWithIncomes) {};

	void signupUser();
	void loginUser();
	void changePasswordLoggedUser();
	void displayUsers();
	void addIncome();
	void displayIncomes();
	
};

#endif