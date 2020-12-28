#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H
#include <iostream>
#include <vector>
#include <sstream>

#include "Expense.h"
#include "Markup.h"
#include "XMLFile.h"
#include "AuxiliaryMethods.h"
using namespace std;

class ExpensesFile: XMLFile {
	int lastExpenseId;

public:
	ExpensesFile(string fileNameWithExpenses) :
		XMLFile(fileNameWithExpenses) {
		lastExpenseId = 0;
	};

	void addExpenseToFile(Expense expense);
	vector <Expense> readExpensesFromFile(int idLoggedUser);
	int loadLastExpenseId();
};

#endif