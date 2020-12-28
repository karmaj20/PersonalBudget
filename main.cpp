#include <iostream>
#include <Windows.h>
#include "PersonalBudget.h"

using namespace std;

int main() 
{
	PersonalBudget personalBudget("users.xml", "incomes.xml", "expenses.xml");

	/*
	personalBudget.signupUser();
	personalBudget.signupUser();
	personalBudget.changePasswordLoggedUser();
	*/
	personalBudget.loginUser();
	personalBudget.addIncome();
	personalBudget.addExpense();
}