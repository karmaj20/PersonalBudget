#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H
#include <iostream>

#include "UserManager.h"
#include "FinanceManager.h"
#include "XMLFile.h"

using namespace std;

class PersonalBudget {
	UserManager userManager;
	FinanceManager* financeManager;
	const string FILENAME_WITH_INCOMES;
	const string FILENAME_WITH_EXPENSES;
public:
	PersonalBudget(string filenameWithUsers, string filenameWithIncomes, string filenameWithExpenses) :
		userManager(filenameWithUsers), FILENAME_WITH_INCOMES(filenameWithIncomes), FILENAME_WITH_EXPENSES(filenameWithExpenses)
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
	void logoutUser();
	void changePasswordLoggedUser();
	void displayUsers();
	void addIncome();
	void addExpense();
	void displayIncomesAndExpenses();
	
};

#endif