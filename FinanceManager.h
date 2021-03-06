#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H
#include <iostream>
#include <vector>
#include <time.h>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
#include "Income.h"
#include "Expense.h"
#include "UserManager.h"
#include "IncomesFile.h"
#include "ExpensesFile.h"
#include "AuxiliaryMethods.h"

class FinanceManager {
	const int ID_LOGGED_USER;
	vector<Income> incomes;
	vector<Expense> expenses;

	Income giveNewIncomeData();
	Expense giveNewExpenseData();
	int presentDate();
	int choseDate();
	void displayIncomeData(Income income);
	void displayExpenseData(Expense expense);
	IncomesFile incomesFile;
	ExpensesFile expensesFile;
	void displayIncomesAndExpenses(int firstDate, int secondDate);
	bool checkDateCorectness(int date);
	bool leapyear(int year);
	string changeCommaToDot(string amount);
public:
	FinanceManager(string filenameWithIncomes, string filenameWithExpenses, int idLoggedUser) :
		incomesFile(filenameWithIncomes), expensesFile(filenameWithExpenses), ID_LOGGED_USER(idLoggedUser)
	{
		incomes = incomesFile.readIncomesFromFile(ID_LOGGED_USER);
		expenses = expensesFile.readExpensesFromFile(ID_LOGGED_USER);
	};

	void addIncome();
	void addExpense();
	void currentMonthBalance();
	void previousMonthBalance();
	void chosenPeriodBalance();
};

#endif