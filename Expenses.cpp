#include "Expenses.h"

void Expenses::setExpenseId(int newExpenseId)
{
	expenseId = newExpenseId;
}

void Expenses::setUserId(int newUserId)
{
	userId = newUserId;
}

void Expenses::setDate(string newDate)
{
	date = newDate;
}

void Expenses::setItem(string newItem)
{
	item = newItem;
}

void Expenses::setAmount(int newAmount)
{
	amount = newAmount;
}

int Expenses::getExpenseId()
{
	return expenseId;
}

int Expenses::getUserId()
{
	return userId;
}

string Expenses::getDate()
{
	return date;
}

string Expenses::getItem()
{
	return item;
}

float Expenses::getAmount()
{
	return amount;
}
