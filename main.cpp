#include <iostream>
#include <Windows.h>

#include "PersonalBudget.h"

using namespace std;

int main() 
{ 
    PersonalBudget personalBudget("users.xml", "incomes.xml", "expenses.xml");
    char choice;
    while (true)
    {
        if (personalBudget.isUserLogged() == 0)
        {
            choice = personalBudget.chooseMainMenuOption();

            switch (choice)
            {
            case '1':
                personalBudget.signupUser();
                break;
            case '2':
                personalBudget.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Lack of this option in menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = personalBudget.chooseUserMenuOption();

            switch (choice)
            {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.currentMonthBalance();
                break;
            case '4':
                personalBudget.previousMonthBalance();
                break;
            case '5':
                personalBudget.chosenPeriodBalance();
                break;
            case '6':
                personalBudget.changePasswordLoggedUser();
                break;
            case '7':
                personalBudget.logoutUser();
                break;
            default:
                cout << endl << "Lack of this option in menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }
}