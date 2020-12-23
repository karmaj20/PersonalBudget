#include "FinanceManager.h"

Income FinanceManager::giveNewIncomeData()
{
    Income income;
    int incomeId = 0, userId = 0;
    string date = "", item = "";
    float amount = 0.0;

    income.setIncomeId(incomeId);
    income.setUserId(userId);

    date = presentDate();
    income.setDate(date);
    cout << "What is the category of income ?: ";
    item = AuxiliaryMethods::loadLine();
    income.setItem(item);

    cout << "Write amount of income: ";
    cin >> amount;
    income.setAmount(amount);

    return income;
}

string FinanceManager::presentDate()
{
    string year, month, day;
    time_t t;
    struct tm* ptr;
    time(&t);
    ptr = localtime(&t);
    string date = asctime(ptr);
    year = date.substr(20, 4);
    month = date.substr(4, 3);
    day = date.substr(8, 2);

    date = year + '-' + month + "-" + day;
    return date;
}

void FinanceManager::displayIncomes()
{
    system("cls");
    if (!incomes.empty()) {
        cout << "             >>> INCOMES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector<Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            displayIncomeData(*itr);
        }
        cout << endl;
    }
    else {
        cout << endl << "You did not add incomes." << endl << endl;
    }
    system("pause");
}

void FinanceManager::displayIncomeData(Income income)
{
    cout << "Income Id:     " << income.getIncomeId() << endl;
    cout << "User Id:       " << income.getUserId() << endl;
    cout << "Date:          " << income.getDate() << endl;
    cout << "Category:      " << income.getItem() << endl;
    cout << "Amount:        " << income.getAmount() << endl;
        
}

void FinanceManager::addIncome()
{
	cout << "Would you like to add income with present day or other date ?" << endl;
    
    Income income = giveNewIncomeData();

    incomes.push_back(income);

    cout << endl << "Income added succesfuly" << endl;
    system("pause");
}
