#include "FinanceManager.h"

void FinanceManager::addIncome()
{
    Income income = giveNewIncomeData();
    incomes.push_back(income);
    incomesFile.addIncomeToFile(income);

    cout << endl << "Income added succesfuly" << endl;
    system("pause");
}

void FinanceManager::addExpense()
{
    Expense expense = giveNewExpenseData();
    expenses.push_back(expense);
    expensesFile.addExpenseToFile(expense);

    cout << endl << "Expense added succesfuly" << endl;
    system("pause");
}

void FinanceManager::currentMonthBalance()
{
    float incomesSum = 0.0, expensesSum = 0.0;
    int date = presentDate();
    cout << endl;
    string firstDate, secondDate;
    int firstDateHelper, secondDateHelper;

    firstDate = AuxiliaryMethods::intToStringConverter(date);
    firstDate.replace(6, 2, "01");

    secondDate = AuxiliaryMethods::intToStringConverter(date);
    secondDate.replace(6, 2, "31");

    firstDateHelper = AuxiliaryMethods::stringToIntConverter(firstDate);
    secondDateHelper = AuxiliaryMethods::stringToIntConverter(secondDate);

    incomes = AuxiliaryMethods::sortingIncomesByDate(incomes);
    expenses = AuxiliaryMethods::sortingExpensesByDate(expenses);
    displayIncomesAndExpenses(firstDateHelper, secondDateHelper);
}

void FinanceManager::previousMonthBalance()
{
    float incomesSum = 0.0, expensesSum = 0.0;
    string firstDate, secondDate, newDate, month;
    int firstDateHelper, secondDateHelper;
    int date = presentDate();
    newDate = AuxiliaryMethods::intToStringConverter(date);
    month = newDate.substr(4, 2);

    map<string, string> months;
    months = {
        {"01", "12"},
        {"02", "01"},
        {"03", "02"},
        {"04", "03"},
        {"05", "04"},
        {"06", "05"},
        {"07", "06"},
        {"08", "07"},
        {"09", "08"},
        {"10", "09"},
        {"11", "10"},
        {"12", "11"}
    };

    map<string, string>::iterator iter = months.find(month);
    if (iter != months.end()) {
        month = iter->second;
    }

    cout << endl;

    firstDate = AuxiliaryMethods::intToStringConverter(date);
    firstDate.replace(4, 2, month);
    firstDate.replace(6, 2, "01");

    secondDate = AuxiliaryMethods::intToStringConverter(date);
    secondDate.replace(4, 2, month);
    secondDate.replace(6, 2, "31");

    firstDateHelper = AuxiliaryMethods::stringToIntConverter(firstDate);
    secondDateHelper = AuxiliaryMethods::stringToIntConverter(secondDate);

    incomes = AuxiliaryMethods::sortingIncomesByDate(incomes);
    expenses = AuxiliaryMethods::sortingExpensesByDate(expenses);
    displayIncomesAndExpenses(firstDateHelper, secondDateHelper);
}

void FinanceManager::chosenPeriodBalance()
{
    int firstDate, secondDate;
    float incomesSum = 0.0, expensesSum = 0.0;
    firstDate = choseDate();
    secondDate = choseDate();
    cout << endl;

    incomes = AuxiliaryMethods::sortingIncomesByDate(incomes);
    expenses = AuxiliaryMethods::sortingExpensesByDate(expenses);

    displayIncomesAndExpenses(firstDate, secondDate);
}

void FinanceManager::displayIncomesAndExpenses(int firstDate, int secondDate)
{
    float incomesSum = 0.0, expensesSum = 0.0;
    if (!incomes.empty()) {
        cout << "             >>> INCOMES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector<Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            if (itr->getDate() > firstDate && itr->getDate() < secondDate) {
                incomesSum += itr->getAmount();
                displayIncomeData(*itr);
            }
        }
        cout << endl;
    }
    else {
        cout << endl << "You did not add incomes." << endl << endl;
    }
    if (!expenses.empty()) {
        cout << "             >>> EXPENSES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector<Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
            if (itr->getDate() > firstDate && itr->getDate() < secondDate) {
                expensesSum += itr->getAmount();
                displayExpenseData(*itr);
            }
        }
        cout << endl;
    }
    else {
        cout << endl << "You did not add epenses." << endl << endl;
    }

    float balance = incomesSum - expensesSum;
    cout << "Your total incomes this period: " << incomesSum << endl;
    cout << "Your total expenses this period: " << expensesSum << endl;
    cout << "Total balance: " << balance << endl;
    system("pause");
}

Income FinanceManager::giveNewIncomeData()
{
    Income income;
    int incomeId = 0, userId = 0, date = 0;
    string item = "";
    float amount = 0.0;
    
    cout << "           >>>INCOME MENU<<<          " << endl;
    cout << "--------------------------------------" << endl;
    cout << "1. Add income with present date" << endl;
    cout << "2. Add income with chosen date" << endl;
    char choice;
    cin >> choice;
    if (choice == '1')
        date = presentDate();
    else if (choice == '2')
        date = choseDate();

    cout << "What is the category of income ?: ";
    item = AuxiliaryMethods::loadLine();
    income.setItem(item);

    cout << "Write amount of income: ";
    cin >> amount;

    income.setIncomeId(incomesFile.loadLastIncomeId() + 1);
    income.setUserId(ID_LOGGED_USER);
    income.setDate(date);
    income.setItem(item);
    income.setAmount(amount);

    return income;
}

Expense FinanceManager::giveNewExpenseData()
{
    Expense expense;
    int expenseId = 0, userId = 0, date = 0;
    string item = "";
    float amount = 0.0;

    cout << "           >>>EXPENSE MENU<<<          " << endl;
    cout << "--------------------------------------" << endl;
    cout << "1. Add expense with present date" << endl;
    cout << "2. Add expense with chosen date" << endl;
    char choice;
    cin >> choice;
    if (choice == '1')
        date = presentDate();
    else if (choice == '2')
        date = choseDate();

    cout << "What is the category of expense ?: ";
    item = AuxiliaryMethods::loadLine();
    expense.setItem(item);

    cout << "Write amount of expense: ";
    cin >> amount;

    expense.setExpenseId(expensesFile.loadLastExpenseId() + 1);
    expense.setUserId(ID_LOGGED_USER);
    expense.setDate(date);
    expense.setItem(item);
    expense.setAmount(amount);

    return expense;
}

int FinanceManager::presentDate()
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

    date = year + month + day;

    return AuxiliaryMethods::stringToIntConverter(date);
}

int FinanceManager::choseDate()
{
    //int year, month, day;
    int newDate;
    string date;
    do {
        cout << "Write date in format rrrr-mm-dd: ";
        cin >> date;
        date.erase(4, 1);
        date.erase(6, 1);
        newDate = AuxiliaryMethods::stringToIntConverter(date);
    } while (checkDateCorectness(newDate) == false);

    date = AuxiliaryMethods::dateConverter(newDate);
    vector <string> partOfDateContainer;
    stringstream ss(date);
    string item;
    while (getline(ss, item, '-')) {
        partOfDateContainer.push_back(item);
    }

    date = partOfDateContainer[0] + partOfDateContainer[1] + partOfDateContainer[2];

    return AuxiliaryMethods::stringToIntConverter(date);
}

void FinanceManager::displayIncomeData(Income income)
{
    string newDate;
    int date = income.getDate();
    newDate = AuxiliaryMethods::dateConverter(date);

    cout << " Date: "           << newDate;
    cout << " Category: "       << income.getItem();
    cout << " Cost: "           << income.getAmount() << endl;
        
}

void FinanceManager::displayExpenseData(Expense expense)
{
    string newDate;
    int date = expense.getDate();
    newDate = AuxiliaryMethods::dateConverter(date);

    cout << " Date: "           << newDate;
    cout << " Category: "       << expense.getItem();
    cout << " Cost: "           << expense.getAmount() << endl;
}   

bool FinanceManager::checkDateCorectness(int date)
{
    bool hasTheDateCorrectFormat = true;
    int year, month, day;
    string newDate = AuxiliaryMethods::intToStringConverter(date);
    string tempYear = newDate.substr(0, 4);
    string tempMonth = newDate.substr(4, 2);
    string tempDay = newDate.substr(6, 2);

    year = AuxiliaryMethods::stringToIntConverter(tempYear);
    month = AuxiliaryMethods::stringToIntConverter(tempMonth);
    day = AuxiliaryMethods::stringToIntConverter(tempDay);

    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (day < 1 || day > 31) {
            hasTheDateCorrectFormat = false;
            return hasTheDateCorrectFormat;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (day < 1 || day > 30) {
            hasTheDateCorrectFormat = false;
            return hasTheDateCorrectFormat;
        }
        break;
    case 2:
        if (leapyear(year) == true) {
            if (day < 1 || day > 29) {
                hasTheDateCorrectFormat = false;
                return hasTheDateCorrectFormat;
            }
        }
        else {
            if (day < 1 || day > 28) {
                hasTheDateCorrectFormat = false;
                return hasTheDateCorrectFormat;
            }
        }
        break;
    }
    if ((year < 2000) || (month < 1) || (month > 12)) {
        hasTheDateCorrectFormat = false;
        return hasTheDateCorrectFormat;
    }
    return hasTheDateCorrectFormat;
}

bool FinanceManager::leapyear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    else {
        return false;
    }
}