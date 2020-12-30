#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

#include "Income.h"
#include "Expense.h"

using namespace std;


struct compIncome
{
	inline bool operator()(Income& firstDate, Income& secondDate) const {
		return firstDate.getDate() < secondDate.getDate();
	}
};

struct compExpense
{
	inline bool operator()(Expense& firstDate, Expense& secondDate) const {
		return firstDate.getDate() < secondDate.getDate();
	}
};

class AuxiliaryMethods {

public:
	static string intToStringConverter(int number);
	static string dateConverter(int number);
	static int stringToIntConverter(string number);
	static float stringToFloatConverter(string number);
	static string loadLine();
	static char loadChar();
	static int loadInteger();
	static vector <Income> sortingIncomesByDate(vector<Income>& incomes);
	static vector <Expense> sortingExpensesByDate(vector<Expense>& expenses);
};

#endif