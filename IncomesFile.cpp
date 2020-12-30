#include "IncomesFile.h"

void IncomesFile::addIncomeToFile(Income income)
{
	CMarkup xml;
	bool fileExists = xml.Load(getFilename());

	string newDate;
	int date = income.getDate();
	newDate = AuxiliaryMethods::dateConverter(date);

	ostringstream temporaryString;
	temporaryString << income.getAmount();
	string amountAsString = temporaryString.str();

	if (!fileExists) {
		xml.AddElem("Incomes");
	}

	xml.FindElem();
	xml.IntoElem();
	xml.AddElem("Income");
	xml.IntoElem();
	xml.AddElem("IncomeId", income.getIncomeId());
	xml.AddElem("UserId", income.getUserId());
	xml.AddElem("Date", newDate);
	xml.AddElem("Item", income.getItem());
	xml.AddElem("Amount", amountAsString);
	lastIncomeId++;
	xml.Save(getFilename());
}

vector<Income> IncomesFile::readIncomesFromFile(int idLoggedUser)
{
	CMarkup xml;
	Income income;
	vector <Income> incomes;
	xml.Load(getFilename());
	

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
		strSN.erase(4, 1);
		strSN.erase(6, 1);
		income.setDate(AuxiliaryMethods::stringToIntConverter(strSN));

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
