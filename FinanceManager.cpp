#include "FinanceManager.h"

Income FinanceManager::giveNewIncomeData()
{
    Income income;
    int incomeId = 0, userId = 0;
    string date = "", item = "";
    float amount = 0.0;

    date = presentDate();
    cout << "What is the category of income ?: ";
    item = AuxiliaryMethods::loadLine();
    income.setItem(item);

    cout << "Write amount of income: ";
    cin >> amount;

    income.setIncomeId(loadNewIncomeId());
    income.setUserId(userId);
    income.setDate(date);
    income.setItem(item);
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

    map<string, string> months;
    months = {
        {"Jan", "01"},
        {"Feb", "02"},
        {"Mar", "03"},
        {"Apr", "04"},
        {"May", "05"},
        {"Jun", "06"},
        {"Jul", "07"},
        {"Aug", "08"},
        {"Sep", "09"},
        {"Oct", "10"},
        {"Nov", "11"},
        {"Dec", "12"}
    };

    map<string, string>::iterator iter = months.find(month);
    if (iter != months.end()) {
        month = iter->second;
    }

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
    incomesFile.addIncomeToFile(income);

    cout << endl << "Income added succesfuly" << endl;
    system("pause");
}

int FinanceManager::loadNewIncomeId() {
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getIncomeId() + 1;
}