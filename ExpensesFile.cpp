#include "ExpensesFile.h"

void ExpensesFile::addExpenseToFile(Expense expense)
{
	CMarkup xml;
	bool fileExists = xml.Load(getFilename());

	string newDate;
	int date = expense.getDate();
	newDate = AuxiliaryMethods::dateConverter(date);

	ostringstream temporaryString;
	temporaryString << expense.getAmount();
	string amountAsString = temporaryString.str();

	if (!fileExists) {
		xml.AddElem("Expenses");
	}

	xml.FindElem();
	xml.IntoElem();
	xml.AddElem("Expense");
	xml.IntoElem();
	xml.AddElem("ExpenseId", expense.getExpenseId());
	xml.AddElem("UserId", expense.getUserId());
	xml.AddElem("Date", newDate);
	xml.AddElem("Item", expense.getItem());
	xml.AddElem("Amount", amountAsString);


	xml.Save(getFilename());
}

vector<Expense> ExpensesFile::readExpensesFromFile(int idLoggedUser)
{
	CMarkup xml;
	Expense expense;
	vector <Expense> expenses;
	xml.Load(getFilename());

	xml.FindElem();
	xml.IntoElem();
	while (xml.FindElem("Expense")) {
		xml.IntoElem();

		xml.FindElem("ExpenseId");
		MCD_STR strSN = xml.GetData();
		expense.setExpenseId(AuxiliaryMethods::stringToIntConverter(strSN));
		xml.FindElem("UserId");
		strSN = xml.GetData();
		expense.setUserId(AuxiliaryMethods::stringToIntConverter(strSN));

		xml.FindElem("Date");
		strSN = xml.GetData();
		expense.setDate(AuxiliaryMethods::stringToIntConverter(strSN));

		xml.FindElem("Item");
		strSN = xml.GetData();
		expense.setItem(strSN);

		xml.FindElem("Amount");
		strSN = xml.GetData();
		expense.setAmount(AuxiliaryMethods::stringToFloatConverter(strSN));
		xml.OutOfElem();

		lastExpenseId++;
		if(idLoggedUser == expense.getUserId())
			expenses.push_back(expense);
	}

	return expenses;
}

int ExpensesFile::loadLastExpenseId()
{
	return lastExpenseId;
}
