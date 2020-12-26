#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H
#include <iostream>
#include <vector>
#include <sstream>

#include "Expense.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"
using namespace std;

class ExpensesFile {
	const string FILENAME_WITH_EXPENSES;
	int lastExpenseId;

public:
	ExpensesFile(string fileNameWithExpenses) :
		FILENAME_WITH_EXPENSES(fileNameWithExpenses) {
		lastExpenseId = 0;
	};

	void addExpenseToFile(Expense expense);
	vector <Expense> readExpensesFromFile(int idLoggedUser);
	int loadLastExpenseId();
};

#endif