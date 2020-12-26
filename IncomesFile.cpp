#include "IncomesFile.h"

void IncomesFile::addIncomeToFile(Income income)
{
	CMarkup xml;
	bool fileExists = xml.Load(FILENAME_WITH_INCOMES);
	ostringstream temporaryString;

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

	temporaryString << income.getAmount();
	string amountAsString = temporaryString.str();
	xml.AddElem("Amount", amountAsString);

	xml.Save(FILENAME_WITH_INCOMES);
}

vector<Income> IncomesFile::readIncomesFromFile(int idLoggedUser)
{
	CMarkup xml;
	Income income;
	vector <Income> incomes;
	xml.Load(FILENAME_WITH_INCOMES);
	

	xml.FindElem();
	xml.IntoElem();
	while (xml.FindElem("Income")) {
		xml.IntoElem();

		xml.FindElem("IncomeId");
		MCD_STR strSN = xml.GetData();
		income.setIncomeId(AuxiliaryMethods::stringToIntConverter(strSN));
		xml.FindElem("UserId");
		strSN = xml.GetData();
		income.setUserId(AuxiliaryMethods::stringToIntConverter(strSN));

		xml.FindElem("Date");
		strSN = xml.GetData();
		income.setDate(strSN);

		xml.FindElem("Item");
		strSN = xml.GetData();
		income.setItem(strSN);

		xml.FindElem("Amount");
		strSN = xml.GetData();
		income.setAmount(AuxiliaryMethods::stringToFloatConverter(strSN));
		xml.OutOfElem();

		lastIncomeId++;
		if(idLoggedUser == income.getUserId())
			incomes.push_back(income);
	}

	return incomes;
}

int IncomesFile::loadLastIncomeId()
{
	return lastIncomeId;
}
