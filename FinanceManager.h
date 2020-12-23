#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H
#include <iostream>
#include <vector>
#include <time.h>
#include <string>
#include <map>

using namespace std;
#include "Income.h"
#include "Expense.h"
#include "UserManager.h"
#include "IncomesFile.h"
#include "AuxiliaryMethods.h"

class FinanceManager {
	vector<Income> incomes;
	vector<Expense> expenses;

	Income giveNewIncomeData();
	string presentDate();
	void displayIncomeData(Income income);
	int loadNewIncomeId();
	IncomesFile incomesFile;
public:
	FinanceManager(string filenameWithIncomes) : incomesFile(filenameWithIncomes) {
		incomes = incomesFile.readIncomesFromFile();
	};
	void displayIncomes();

	void addIncome();
	void addExpense();
	void currentMonthBalance();
	void previousMonthBalance();
	void chosenPeriodBalance();
	void changePassword();
};

#endif