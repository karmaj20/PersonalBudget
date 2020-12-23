#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H
#include <iostream>
#include <vector>
#include <time.h>
#include <string>

using namespace std;
#include "Income.h"
#include "Expense.h"
#include "UserManager.h"
#include "AuxiliaryMethods.h"

class FinanceManager {
	vector<Income> incomes;
	vector<Expense> expenses;

	Income giveNewIncomeData();
	string presentDate();
	void addIncomeWithCurrentDate();
	void displayIncomeData(Income income);
public:
	void displayIncomes();

	void addIncome();
	void addExpense();
	void currentMonthBalance();
	void previousMonthBalance();
	void chosenPeriodBalance();
	void changePassword();
};

#endif