#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H
#include <iostream>
#include <vector>

using namespace std;
#include "Income.h"
#include "Expense.h"
#include "UserManager.h"

class FinanceManager {
	vector<Income> incomes;
	vector<Expense> expenses;
public:
	void addIncome();
	void addExpense();
	void currentMonthBalance();
	void previousMonthBalance();
	void chosenPeriodBalance();
	void changePassword();
};

#endif