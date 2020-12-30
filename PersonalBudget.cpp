#include "PersonalBudget.h"

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

void PersonalBudget::addIncome()
{
	if (userManager.isUserLogged()) {
		financeManager->addIncome();
	}
	else {
		cout << "Login to add income." << endl;
		system("pause");
	}
}

void PersonalBudget::addExpense()
{
	if (userManager.isUserLogged()) {
		financeManager->addExpense();
	}
	else {
		cout << "Login to add expense." << endl;
		system("pause");
	}
}

void PersonalBudget::displayIncomes()
{
	financeManager->displayIncomes();
}

void PersonalBudget::displayExpenses()
{
	financeManager->displayExpenses();
}

void PersonalBudget::displayIncomesAndExpenses()
{
	financeManager->displayIncomesAndExpenses();
}
