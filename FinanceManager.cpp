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
    income.setUserId(ID_LOGGED_USER);
    income.setDate(date);
    income.setItem(item);
    income.setAmount(amount);

    return income;
}

Income FinanceManager::giveNewIncomeChosenDate()
{
    Income income;
    int incomeId = 0, userId = 0;
    string date = "", item = "";
    float amount = 0.0;

    date = choseDate();
    cout << "What is the category of income ?: ";
    item = AuxiliaryMethods::loadLine();
    income.setItem(item);

    cout << "Write amount of income: ";
    cin >> amount;

    income.setIncomeId(loadNewIncomeId());
    income.setUserId(ID_LOGGED_USER);
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

string FinanceManager::choseDate()
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

    date = el[0] + "-" + el[1] + "-" + el[2];

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

void FinanceManager::displayExpenses()
{
    system("cls");
    if (!expenses.empty()) {
        cout << "             >>> EXPENSES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector<Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
            displayExpenseData(*itr);
        }
        cout << endl;
    }
    else {
        cout << endl << "You did not add expenses." << endl << endl;
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

void FinanceManager::displayExpenseData(Expense expense)
{
    cout << "Expense Id:    " << expense.getExpenseId() << endl;
    cout << "User Id:       " << expense.getUserId() << endl;
    cout << "Date:          " << expense.getDate() << endl;
    cout << "Category:      " << expense.getItem() << endl;
    cout << "Amount:        " << expense.getAmount() << endl;
}

int FinanceManager::loadNewIncomeId() {
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getIncomeId() + 1;
}

void FinanceManager::addIncome()
{
    cout << "           >>>INCOME MENU<<<          " << endl;
    cout << "--------------------------------------" << endl;
    cout << "1. Add income with present date" << endl;
    cout << "2. Add income with chosen date" << endl;
    char choice;
    cin >> choice;
    if (choice == '1') {
        Income income = giveNewIncomeData();
        incomes.push_back(income);
        incomesFile.addIncomeToFile(income);
    }
    else if (choice == '2') {
        Income income = giveNewIncomeChosenDate();
        incomes.push_back(income);
        incomesFile.addIncomeToFile(income);
    }
    else {
        cout << "Press 1 or 2" << endl;
    }

    cout << endl << "Income added succesfuly" << endl;
    system("pause");
}


Expense FinanceManager::giveNewExpenseData()
{
    Expense expense;
    int expenseId = 0, userId = 0;
    string date = "", item = "";
    float amount = 0.0;

    date = presentDate();
    cout << "What is the category of income ?: ";
    item = AuxiliaryMethods::loadLine();
    expense.setItem(item);

    cout << "Write amount of income: ";
    cin >> amount;

    expense.setExpenseId(loadNewExpenseId());
    expense.setUserId(ID_LOGGED_USER);
    expense.setDate(date);
    expense.setItem(item);
    expense.setAmount(amount);

    return expense;
}

Expense FinanceManager::giveNewExpenseChosenDate()
{
    Expense expense;
    int expenseId = 0, userId = 0;
    string date = "", item = "";
    float amount = 0.0;

    date = choseDate();
    cout << "What is the category of income ?: ";
    item = AuxiliaryMethods::loadLine();
    expense.setItem(item);

    cout << "Write amount of income: ";
    cin >> amount;

    expense.setExpenseId(loadNewExpenseId());
    expense.setUserId(ID_LOGGED_USER);
    expense.setDate(date);
    expense.setItem(item);
    expense.setAmount(amount);

    return expense;
}

int FinanceManager::loadNewExpenseId() {
    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().getExpenseId() + 1;
}

void FinanceManager::addExpense()
{
    cout << "           >>>EXPENSE MENU<<<          " << endl;
    cout << "--------------------------------------" << endl;
    cout << "1. Add expense with present date" << endl;
    cout << "2. Add expense with chosen date" << endl;
    char choice;
    cin >> choice;
    if (choice == '1') {
        Expense expense = giveNewExpenseData();
        expenses.push_back(expense);
        expensesFile.addExpenseToFile(expense);
    }
    else if (choice == '2') {
        Expense expense = giveNewExpenseData();
        expenses.push_back(expense);
        expensesFile.addExpenseToFile(expense);
    }
    else {
        cout << "Press 1 or 2" << endl;
    }

    cout << endl << "Expense added succesfuly" << endl;
    system("pause");
}