#include "Incomes.h"

void Incomes::setIncomeId(int newIncomeId)
{
	incomeId = newIncomeId;
}

void Incomes::setUserId(int newUserId)
{
	userId = newUserId;
}

void Incomes::setDate(string newDate)
{
	date = newDate;
}

void Incomes::setItem(string newItem)
{
	item = newItem;
}

void Incomes::setAmount(int newAmount)
{
	amount = newAmount;
}

int Incomes::getIncomeId()
{
	return incomeId;
}

int Incomes::getUserId()
{
	return userId;
}

string Incomes::getDate()
{
	return date;
}

string Incomes::getItem()
{
	return item);
}

float Incomes::getAmount()
{
	return amount;
}
