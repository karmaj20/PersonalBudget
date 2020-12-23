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
		financeManager = new FinanceManager(FILENAME_WITH_INCOMES, userManager.loadIdLoggedUser());
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

void PersonalBudget::displayIncomes()
{
	financeManager->displayIncomes();
}
