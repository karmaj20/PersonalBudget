#include "ExpensesFile.h"

void ExpensesFile::addExpenseToFile(Expense expense)
{
	CMarkup xml;
	bool fileExists = xml.Load(FILENAME_WITH_EXPENSES);
	ostringstream temporaryString;

	if (!fileExists) {
		xml.AddElem("Expenses");
	}

	xml.FindElem();
	xml.IntoElem();
	xml.AddElem("Expense");
	xml.IntoElem();
	xml.AddElem("ExpenseId", expense.getExpenseId());
	xml.AddElem("UserId", expense.getUserId());
	xml.AddElem("Date", expense.getDate());
	xml.AddElem("Item", expense.getItem());

	temporaryString << expense.getAmount();
	string amountAsString = temporaryString.str();
	xml.AddElem("Amount", amountAsString);


	xml.Save(FILENAME_WITH_EXPENSES);
}

vector<Expense> ExpensesFile::readExpensesFromFile(int idLoggedUser)
{
	CMarkup xml;
	Expense expense;
	vector <Expense> expenses;
	xml.Load(FILENAME_WITH_EXPENSES);

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
		expense.setDate(strSN);

		xml.FindElem("Item");
		strSN = xml.GetData();
		expense.setItem(strSN);

		xml.FindElem("Amount");
		strSN = xml.GetData();
		expense.setAmount(AuxiliaryMethods::stringToFloatConverter(strSN));
		xml.OutOfElem();

		expenses.push_back(expense);
	}

	return expenses;
}
