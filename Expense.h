#ifndef EXPENSES_H
#define EXPENSES_H
#include <iostream>

using namespace std;

class Expense {
	int expenseId;
	int userId;
	string date;
	string item;
	float amount;

public:
	void setExpenseId(int newExpenseId);
	void setUserId(int newUserId);
	void setDate(string newDate);
	void setItem(string newItem);
	void setAmount(int newAmount);

	int getExpenseId();
	int getUserId();
	string getDate();
	string getItem();
	float getAmount();
};

#endif