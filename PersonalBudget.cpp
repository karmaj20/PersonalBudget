#include "PersonalBudget.h"

void PersonalBudget::signupUser()
{
	userManager.signupUser();
}

void PersonalBudget::loginUser()
{
	userManager.loginUser();
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
	financeManager.addIncome();
}

void PersonalBudget::displayIncomes()
{
	financeManager.displayIncomes();
}
