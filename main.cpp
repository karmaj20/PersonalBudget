#include <iostream>
#include <Windows.h>
#include "PersonalBudget.h"

using namespace std;

int main() 
{
	PersonalBudget personalBudget("users.xml", "incomes.xml");

	/*
	personalBudget.signupUser();
	personalBudget.signupUser();
	personalBudget.signupUser();
	personalBudget.loginUser();
	personalBudget.changePasswordLoggedUser();
	*/
	personalBudget.addIncome();
	personalBudget.displayIncomes();
}