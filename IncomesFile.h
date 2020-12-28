#ifndef INCOMESFILE_H
#define INCOMESFILE_H
#include <iostream>
#include <vector>

#include "Income.h"
#include "Markup.h"
#include "XMLFile.h"
#include "AuxiliaryMethods.h"
using namespace std;

class IncomesFile: XMLFile {
	int lastIncomeId;

public: 
	IncomesFile(string filenameWithIncomes) :
		XMLFile(filenameWithIncomes) {
		lastIncomeId = 0;
	};
	
	void addIncomeToFile(Income income);
	vector <Income> readIncomesFromFile(int idLoggedUser);
	int loadLastIncomeId();
};

#endif