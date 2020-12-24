#ifndef EXPENSES_H
#define EXPENSES_H
#include <iostream>

using namespace std;

class Expense {
	int expenseId = 0;
	int userId = 0;
	string date = "";
	string item = "";
	float amount = 0.0;

public:
	void setExpenseId(int newExpenseId);
	void setUserId(int newUserId);
	void setDate(string newDate);
	void setItem(string newItem);
	void setAmount(float newAmount);

	int getExpenseId();
	int getUserId();
	string getDate();
	string getItem();
	float getAmount();
};

#endif