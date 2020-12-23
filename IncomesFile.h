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

public: 
	IncomesFile(string filenameWithIncomes) :
		FILENAME_WITH_INCOMES(filenameWithIncomes) {};
	
	void addIncomeToFile(Income income);
	vector <Income> readIncomesFromFile(int idLoggedUser);
};

#endif