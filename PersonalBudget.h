#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H
#include <iostream>

#include "UserManager.h"
#include "FinanceManager.h"

using namespace std;

class PersonalBudget {
	UserManager userManager;
	FinanceManager* financeManager;
	const string FILENAME_WITH_INCOMES;
public:
	PersonalBudget(string filenameWithUsers, string filenameWithIncomes) :
		userManager(filenameWithUsers), FILENAME_WITH_INCOMES(filenameWithIncomes) 
	{
		financeManager = NULL;
	};
	~PersonalBudget() 
	{
		delete financeManager;
		financeManager = NULL;
	}

	void signupUser();
	void loginUser();
	void changePasswordLoggedUser();
	void displayUsers();
	void addIncome();
	void displayIncomes();
	
};

#endif