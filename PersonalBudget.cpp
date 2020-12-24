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
	financeManager->addIncome();
}

void PersonalBudget::addExpense()
{
	financeManager->addExpense();
}

void PersonalBudget::displayIncomes()
{
	financeManager->displayIncomes();
}

void PersonalBudget::displayExpenses()
{
	financeManager->displayExpenses();
}
