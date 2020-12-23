#include "IncomesFile.h"

void IncomesFile::addIncomeToFile(Income income)
{
	CMarkup xml;
	bool fileExists = xml.Load(filenameWithIncomes);
	

	if (!fileExists) {
		xml.AddElem("Incomes");
	}

	xml.FindElem();
	xml.IntoElem();
	xml.AddElem("Income");
	xml.IntoElem();
	xml.AddElem("IncomeId", income.getIncomeId());
	xml.AddElem("UserId", income.getUserId());
	xml.AddElem("Date", income.getDate());
	xml.AddElem("Item", income.getItem());
	xml.AddElem("Amount", income.getAmount());

	xml.Save(filenameWithIncomes);
}
