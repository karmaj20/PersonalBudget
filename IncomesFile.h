#ifndef INCOMESFILE_H
#define INCOMESFILE_H
#include <iostream>
#include <vector>

#include "Income.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"
using namespace std;

class IncomesFile {
	const string FILENAME_WITH_INCOMES;
	int lastIncomeId;

public: 
	IncomesFile(string filenameWithIncomes) :
		FILENAME_WITH_INCOMES(filenameWithIncomes) {
		lastIncomeId = 0;
	};
	
	void addIncomeToFile(Income income);
	vector <Income> readIncomesFromFile(int idLoggedUser);
	int loadLastIncomeId();
};

#endif