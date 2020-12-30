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

float FinanceManager::displayIncomes()
{
    incomes = AuxiliaryMethods::sortingIncomesByDate(incomes);
    float sum = 0.0;
    system("cls");
    if (!incomes.empty()) {
        cout << "             >>> INCOMES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector<Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            sum += itr->getAmount();
            displayIncomeData(*itr);
        }
        cout << endl;
    }
    else {
        cout << endl << "You did not add incomes." << endl << endl;
    }
    return sum;
}

float FinanceManager::displayExpenses()
{
    expenses = AuxiliaryMethods::sortingExpensesByDate(expenses);
    float sum = 0.0;
    if (!expenses.empty()) {
        cout << "             >>> EXPENSES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector<Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
            sum += itr->getAmount();
            displayExpenseData(*itr);
        }
        cout << endl << endl;
    }
    else {
        cout << endl << "You did not add expenses." << endl << endl;
    }
    return sum;
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
    string date;
    cout << "Write date in format rrrr-mm-dd: ";
    cin >> date;
    vector <string> el;
    stringstream ss(date);
    string item;
    while (getline(ss, item, '-')) {
        el.push_back(item);
    }

    /*
    year = AuxiliaryMethods::stringToIntConverter(el[0]);
    month = AuxiliaryMethods::stringToIntConverter(el[1]);
    day = AuxiliaryMethods::stringToIntConverter(el[2]);
    */

    date = el[0] + el[1] + el[2];

    return AuxiliaryMethods::stringToIntConverter(date);
}

void FinanceManager::displayIncomesAndExpenses()
{
    float sumIncomes = 0.0, sumExpenses = 0.0, balance = 0.0;

    sumIncomes = displayIncomes();
    sumExpenses = displayExpenses();

    balance = sumIncomes - sumExpenses;

    cout << "Your total incomes this period: "              << sumIncomes << endl;
    cout << "Your total expenses this period: "             << sumExpenses << endl;
    cout << "Difference between incomes and expenses: "     << balance << endl;
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

