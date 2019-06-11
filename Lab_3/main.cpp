//Charles Dodge
//CIST 2362 CRN 63228
//Lab 3 Customer Accounts
#include <iostream>

using namespace std;

struct CustomerAccount {
    string name;
    string address;
    string city;
    string state;
    string zip;
    string telNum;
    double balance;
    string dateLastPayment;
};

CustomerAccount initData();

void editAccounts(CustomerAccount[]);

void editAccount(CustomerAccount &);

void displayData(CustomerAccount[]);

void mainMenu(CustomerAccount[]);

void manualEdit(CustomerAccount &);

int main() {
    const int LEN = 10;
    CustomerAccount accounts[LEN];

    mainMenu(accounts);
    return 0;
}

void mainMenu(CustomerAccount accounts[]) {
    while (true) {
        cout << "-----Main Menu-----\n";
        cout << "Enter 1 to edit accounts\n";
        cout << "Enter 2 to display all account data\n";
        cout << "Enter anything else to exit\n";
        int userChoice;
        cin >> userChoice;
        switch (userChoice) {
            case 1:
                editAccounts(accounts);
                break;
            case 2:
                displayData(accounts);
                break;
            default:
                return;
        }
    }
}

//Allows user to select which account to edit
void editAccounts(CustomerAccount accounts[]) {
    cout << "Which account would you like to edit? (1-10) ";
    int userChoice;
    cin >> userChoice;
    //if user enters not int, clears failbit, ignores rest of input
    while (cin.fail() || (userChoice > 10 || userChoice < 0)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Please enter 1-10: ";
        cin >> userChoice;
    }

    editAccount(accounts[userChoice - 1]);
}

//Allows user to either full input or individually edit
void editAccount(CustomerAccount &acc) {
    cout << endl;
    cout << "Enter 1 to enter all data for this account\n";
    cout << "Enter 2 to edit account individually\n";
    int userChoice;
    cin >> userChoice;
    while (cin.fail() || (userChoice > 2 || userChoice < 0)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Please enter 1 or 2: ";
        cin >> userChoice;
    }

    if (userChoice == 1) {
        acc = initData();
    } else {
        manualEdit(acc);
    }
}

CustomerAccount initData() {
    string accName;
    string accAddress;
    string accCity;
    string accState;
    string accZIP;
    string accTel;
    double accBalance;
    string dateLastPayment;
    string payMonth;
    string payDay;
    string payYear;

    cout << "Enter customer name: ";
    cin >> accName;

    cout << "Enter customer address: ";
    cin >> accAddress;

    cout << "Enter customer city: ";
    cin >> accCity;

    cout << "Enter customer state: ";
    cin >> accState;

    cout << "Enter customer ZIP: ";
    cin >> accZIP;

    cout << "Enter customer telephone: ";
    cin >> accTel;

    cout << "Enter account balance: ";
    cin >> accBalance;
    while (cin.fail() || accBalance < 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Account balance must not be negative: ";
        cin >> accBalance;
    }

    cout << "Enter day of last payment: ";
    cin >> payDay;
    cout << "Enter month of last payment: ";
    cin >> payMonth;
    cout << "Enter year of last payment: ";
    cin >> payYear;
    dateLastPayment = payDay + "-" + payMonth + "-" + payYear;

    CustomerAccount newAccount = {accName, accAddress, accCity, accState, accZIP, accTel, accBalance, dateLastPayment};

    return newAccount;
}

void manualEdit(CustomerAccount &acc) {
    while (true){
        cout << "Enter 1 to edit account name\n";
        cout << "Enter 2 to edit account address\n";
        cout << "Enter 3 to edit account city\n";
        cout << "Enter 4 to edit account state\n";
        cout << "Enter 5 to edit account ZIP\n";
        cout << "Enter 6 to edit account telephone\n";
        cout << "Enter 7 to edit account balance\n";
        cout << "Enter 8 to edit date of last payment\n";
        cout << "Enter anything else to exit\n";
        int userChoice;
        cin >> userChoice;

        string newInput;
        switch (userChoice){
            case 1: {
                cout << "Enter new name: ";
                cin >> newInput;
                acc.name = newInput;
                break;
            }
            case 2: {
                cout << "Enter new address: ";
                cin >> newInput;
                acc.address = newInput;
                break;
            }
            case 3:{
                cout << "Enter new city: ";
                cin >> newInput;
                acc.city = newInput;
                break;

            }
            case 4:{
                cout << "Enter new state: ";
                cin >> newInput;
                acc.state = newInput;
                break;
            }
            case 5:{
                cout << "Enter new ZIP: ";
                cin >> newInput;
                acc.zip = newInput;
                break;
            }
            case 6:{
                cout << "Enter new telephone: ";
                cin >> newInput;
                acc.telNum = newInput;
                break;
            }
            case 7:{
                cout << "Enter new balance: ";
                double newBalance;
                cin >> newBalance;
                while (cin.fail() || newBalance < 0) {
                    cin.clear();
                    cin.ignore(10000,'\n');
                    cout << "Account balance must not be negative: ";
                    cin >> newBalance;
                }
                acc.balance = newBalance;
                break;
            }
            case 8:{
                string payMonth, payDay, payYear;

                cout << "Enter day of last payment: ";
                cin >> payDay;
                cout << "Enter month of last payment: ";
                cin >> payMonth;
                cout << "Enter year of last payment: ";
                cin >> payYear;
                string newDate;
                newDate.append(payDay).append("-").append(payMonth).append("-").append(payYear);
                acc.dateLastPayment = newDate;
                break;
            }
            default: {
                return;
            }
        }
    }
}

void displayData(CustomerAccount accounts[]) {
    cout << "--------------------\n";
    for (int i = 0; i < 10; i++) {

        cout << "Name: " << accounts[i].name << endl;
        cout << "Address: " << accounts[i].address << endl;
        cout << "City: " << accounts[i].city << endl;
        cout << "State: " << accounts[i].state << endl;
        cout << "ZIP: " << accounts[i].zip << endl;
        cout << "Telephone: " << accounts[i].telNum << endl;
        cout << "Balance: " << accounts[i].balance << endl;
        cout << "Date of Last Payment: " << accounts[i].dateLastPayment << endl << endl;
    }
}

/*
//Lab 3 Monthly Budget

#include <iostream>
#include <iomanip>

using namespace std;

struct MonthlyBudget {
    double housing,
            utilities,
            householdExpenses,
            transportation,
            food,
            medical,
            insurance,
            entertainment,
            clothing,
            miscellaneous;
};

const MonthlyBudget MAX_BUDGET{500, 150, 65, 50, 250, 30, 100, 150, 75, 50};

MonthlyBudget getBudgetInfo();

double sumFullBudget(MonthlyBudget);

void displayReport(MonthlyBudget);

int doContinue = 0;
int main() {
    do {
        MonthlyBudget currentExpenses = getBudgetInfo();

        displayReport(currentExpenses);

        cout << "Enter 1 to go again, anything else to exit: ";
        cin >> doContinue;

    } while (doContinue == 1);
    return 0;
}

MonthlyBudget getBudgetInfo() {
    MonthlyBudget temp{};
    cout << "Enter amount spend on housing: ";
    cin >> temp.housing;
    cout << "Enter amount spend on utilities: ";
    cin >> temp.utilities;
    cout << "Enter amount spend on household expenses: ";
    cin >> temp.householdExpenses;
    cout << "Enter amount spend on transportation: ";
    cin >> temp.transportation;
    cout << "Enter amount spend on food: ";
    cin >> temp.food;
    cout << "Enter amount spend on medical: ";
    cin >> temp.medical;
    cout << "Enter amount spend on insurance: ";
    cin >> temp.insurance;
    cout << "Enter amount spend on entertainment: ";
    cin >> temp.entertainment;
    cout << "Enter amount spend on clothing: ";
    cin >> temp.clothing;
    cout << "Enter amount spend on miscellaneous: ";
    cin >> temp.miscellaneous;

    return temp;
}

void displayReport(const MonthlyBudget budget) {
    cout << endl;
    cout << "You have $" << MAX_BUDGET.housing - budget.housing << " remaining this month for housing" << endl;
    cout << "You have $" << MAX_BUDGET.utilities - budget.utilities << " remaining this month for utilities" << endl;
    cout << "You have $" << MAX_BUDGET.householdExpenses - budget.householdExpenses << " remaining this month for household expenses" << endl;
    cout << "You have $" << MAX_BUDGET.transportation - budget.transportation << " remaining this month for transportation" << endl;
    cout << "You have $" << MAX_BUDGET.food - budget.food << " remaining this month for food" << endl;
    cout << "You have $" << MAX_BUDGET.medical - budget.medical << " remaining this month for medical expenses" << endl;
    cout << "You have $" << MAX_BUDGET.insurance - budget.insurance << " remaining this month for insurance" << endl;
    cout << "You have $" << MAX_BUDGET.entertainment - budget.entertainment << " remaining this month for entertainment" << endl;
    cout << "You have $" << MAX_BUDGET.clothing - budget.clothing << " remaining this month for clothing" << endl;
    cout << "You have $" << MAX_BUDGET.miscellaneous - budget.miscellaneous << " remaining this month for miscellaneous expenses" << endl;
    double fullBudgetSum = sumFullBudget(MAX_BUDGET);
    double currentBudgetSum = sumFullBudget(budget);
    cout << "You have $" << fullBudgetSum - currentBudgetSum << " remaining in total for this month" << endl << endl;
}

double sumFullBudget(MonthlyBudget budget) {
    return budget.housing
           + budget.utilities
           + budget.householdExpenses
           + budget.transportation
           + budget.food
           + budget.medical
           + budget.insurance
           + budget.entertainment
           + budget.clothing
           + budget.miscellaneous;
}
 */