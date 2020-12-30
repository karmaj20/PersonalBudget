#include "PersonalBudget.h"

char PersonalBudget::chooseMainMenuOption()
{
	return userManager.chooseMainMenuOption();
}

char PersonalBudget::chooseUserMenuOption()
{
	return userManager.chooseUserMenuOption();
}

void PersonalBudget::signupUser()
{
	userManager.signupUser();
}

void PersonalBudget::loginUser()
{
	userManager.loginUser();

	if (userManager.isUserLogged())
	{
		financeManager = new FinanceManager(FILENAME_WITH_INCOMES, FILENAME_WITH_EXPENSES, userManager.loadIdLoggedUser());
	}
}

void PersonalBudget::logoutUser()
{
	userManager.logoutUser();
	delete financeManager;
	financeManager = NULL;
}

void PersonalBudget::changePasswordLoggedUser()
{
	userManager.changePasswordLoggedUser();
}

void PersonalBudget::displayUsers()
{
	userManager.displayUsers();
}

bool PersonalBudget::isUserLogged()
{
	return userManager.isUserLogged();
}

void PersonalBudget::addIncome()
{
	if (isUserLogged()) {
		financeManager->addIncome();
	}
	else {
		cout << "Login to add income." << endl;
		system("pause");
	}
}

void PersonalBudget::addExpense()
{
	if (isUserLogged()) {
		financeManager->addExpense();
	}
	else {
		cout << "Login to add expense." << endl;
		system("pause");
	}
}
void PersonalBudget::displayIncomesAndExpenses()
{
	financeManager->displayIncomesAndExpenses();
}

void PersonalBudget::currentMonthBalance()
{
	financeManager->currentMonthBalance();
}

void PersonalBudget::previousMonthBalance()
{
	financeManager->previousMonthBalance();
}

void PersonalBudget::chosenPeriodBalance()
{
	financeManager->chosenPeriodBalance();
}
