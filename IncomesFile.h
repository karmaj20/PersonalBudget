#ifndef INCOMESFILE_H
#define INCOMESFILE_H
#include <iostream>
#include <vector>

#include "Income.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"
using namespace std;

class IncomesFile {
	string filenameWithIncomes;

public: 
	IncomesFile(string FILENAME_WITH_INCOMES) :
		filenameWithIncomes(FILENAME_WITH_INCOMES) {};
	
	void addIncomeToFile(Income income);
	vector <Income> readIncomesFromFile();
};

#endif