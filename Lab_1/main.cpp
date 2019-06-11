//Charles Dodge
//CIST 2361 CRN 63328
//Lab 1, Program 3
#include <iostream>

using namespace std;

int doContinue = 0;
const int COLS = 2;
const int NUM_MONTHS = 12;

void getData(double[][COLS]);
double averageHigh(double[][COLS]);
double averageLow(double[][COLS]);
int indexHighTemp(double[][COLS]);
int indexLowTemp(double[][COLS]);

int main() {
    do {
        cout
                << "This program will take in highest and lowest temperatures for each month, and give averages, as well as highest and lowest month"
                << endl;
        double monthlyTemps[NUM_MONTHS][COLS];
        getData(monthlyTemps);

        double yearlyHighAverage = averageHigh(monthlyTemps);
        double yearlyLowAverage = averageLow(monthlyTemps);
        int indexHighest = indexHighTemp(monthlyTemps);
        int indexLowest = indexLowTemp(monthlyTemps);

        cout << "The average high was: " << yearlyHighAverage << endl;
        cout << "The average low was: " << yearlyLowAverage << endl;
        cout << "The month with the highest temperature was month " << (indexHighest + 1) << " with a temperature of "
             << monthlyTemps[indexHighest][0] << endl;
        cout << "The month with the lowest temperature was month " << (indexLowest + 1) << " with a temperature of "
             << monthlyTemps[indexLowest][0] << endl;

        cout << "enter 1 to go again, anything else to exit ";
        cin >> doContinue;
    } while (doContinue == 1);
    return 0;
}

//Gets initial monthly highs and lows
void getData(double monthlyTemps[][COLS]) {
    for (int i = 0; i < NUM_MONTHS; i++) {
        cout << "Enter highest temperature for month " << (i + 1) << ": ";
        //highs in [i][0]
        cin >> monthlyTemps[i][0];
        while (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "monthly temperature must be a number: ";
            cin >> monthlyTemps[i][0];
        }

        cout << "Enter lowest temperature for month " << (i + 1) << ": ";
        //lows in [i][1]
        cin >> monthlyTemps[i][1];
        while (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "monthly temperature must be a number: ";
            cin >> monthlyTemps[i][1];
        }
    }
}

//returns the average high for the year
double averageHigh(double monthlyTemps[][COLS]) {
    double sum = 0;
    for (int i = 0; i < NUM_MONTHS; i++) {
        sum += monthlyTemps[i][0];
    }
    return sum / NUM_MONTHS;
}

//returns the average low for the year
double averageLow(double monthlyTemps[][COLS]) {
    double sum = 0;
    for (int i = 0; i < NUM_MONTHS; i++) {
        sum += monthlyTemps[i][1];
    }
    return sum / NUM_MONTHS;
}

//returns index of the highest temperature
int indexHighTemp(double monthlyTemps[][COLS]) {
    double highest = monthlyTemps[0][0];
    int indexHighest = 0;
    for (int i = 0; i < NUM_MONTHS; i++) {
        if (monthlyTemps[i][0] > highest) {
            highest = monthlyTemps[i][0];
            indexHighest = i;
        }
    }
    return indexHighest;
}

//returns index of the lowest temperature
int indexLowTemp(double monthlyTemps[][COLS]) {
    double lowest = monthlyTemps[0][1];
    int indexHighest = 0;
    for (int i = 0; i < NUM_MONTHS; i++) {
        if (monthlyTemps[i][1] < lowest) {
            lowest = monthlyTemps[i][1];
            indexHighest = i;
        }
    }
    return indexHighest;
}




/*
//Charles Dodge
//CIST 2361 CRN 63328
//Lab 1, Program 2
#include <iostream>
#include <iomanip>

using namespace std;

int doContinue = 0;
//Accepts and validates user input > 0
double getUserInput(string);

int main() {
    do {
        //Set to 2 decimal places
        cout << fixed << setprecision(2);
        double initialLoanAmount = 0;
        double loanLeft = 0;
        double interestRateYear = 0;
        double interestRateMonth = 0;
        double monthlyPayment = 0;
        double interestAmount = 0;
        double actualPayment = 0;

        int monthsToPay = 0;

        //Get loan amounts, interest rate, and monthly payment
        cout << "Enter loan amount: ";
        initialLoanAmount = getUserInput("Initial loan amount ");
        loanLeft = initialLoanAmount;

        cout << "Enter interest rate per year as percentage (e.g. 7.2): ";
        interestRateYear = getUserInput("Interest rate ");
        //convert yearly interest into monthly, and decimal
        interestRateMonth = interestRateYear / 12 / 100;

        cout << "Enter monthly payment: ";
        monthlyPayment = getUserInput("Monthly payment");


        if (monthlyPayment < loanLeft * interestRateMonth) {
            cout << "Your monthly payment is too low, you will never pay off your loan.";
            return 0;
        }

        //Calculate months to apy off loam
        while (loanLeft > 0) {
            //Interest Gains
            interestAmount = loanLeft * interestRateMonth;
            //How much of the monthly goes towards the principal
            actualPayment = monthlyPayment - interestAmount;
            loanLeft -= actualPayment;

            monthsToPay++;
        }

        cout << "With a monthly payment of " << monthlyPayment << ", it will take you " << monthsToPay
             << " months to pay off $" << initialLoanAmount << " at " << interestRateYear << "% interest." <<endl << endl;
        cout << "enter 1 to go again, anything else to exit ";
        cin >> doContinue;

    } while (doContinue == 1);
    return 0;
}

double getUserInput(string desc){
    double userInput = 0;
    cin >> userInput;
    while (cin.fail() || userInput <= 0){
        cin.clear();
        cin.ignore(10000, '\n');
        cout << desc << "must be a positive number: ";
        cin >> userInput;
    }
    return userInput;
}
*/


/*
//Charles Dodge
//CIST 2361 CRN 63328
//Lab 1, Program 1
#include <iostream>
#include <iomanip>

using namespace std;
int doContinue = 0;

int main() {
    do {
        //$5K upon delivery of manuscript, $20K upon publishing
        const int MANUSCRIPT_DELIVERY_FEE = 5000, NOVEL_PUBLISHING_FEE = 20000;
        const int FLAT_FEE_TOTAL = MANUSCRIPT_DELIVERY_FEE + NOVEL_PUBLISHING_FEE;
        //12.5% royalty flat rate, OR 10% for first 4K, 14% after 4K
        const double FIXED_RATE_ROYALTY = .125, VARIABLE_RATE_ROYALTY_LESS_4K = .10, VARIABLE_RATE_ROYALTY_GREATER_4K = .14;

        int estimatedCopiesSold;
        double novelCost;
        double fixedRateAmount, variableLessAmount, variableGreaterAmount, totalVariableAmount;

        cout << "Please enter the estimated number of copies sold: ";
        cin >> estimatedCopiesSold;
        while (cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number: ";
            cin >> estimatedCopiesSold;
        }

        cout << "Please enter the estimated retail price per copy: ";
        cin >> novelCost;
        while (cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number: ";
            cin >> novelCost;
        }

        fixedRateAmount = (FIXED_RATE_ROYALTY * novelCost) * estimatedCopiesSold;
        if (estimatedCopiesSold < 4000) {
            variableLessAmount = (VARIABLE_RATE_ROYALTY_LESS_4K * novelCost) * estimatedCopiesSold;
            variableGreaterAmount = 0;
        } else {
            variableLessAmount = (VARIABLE_RATE_ROYALTY_LESS_4K * novelCost) * 4000;
            variableGreaterAmount = (VARIABLE_RATE_ROYALTY_GREATER_4K * novelCost) * (estimatedCopiesSold - 4000);
        }

        totalVariableAmount = variableLessAmount + variableGreaterAmount;

        //formatting
        cout << setprecision(2) << fixed;
        cout << "Selling " << estimatedCopiesSold << " at $" << novelCost << " per copy, you will receive: " << endl;
        cout << "$" << FLAT_FEE_TOTAL << " by accepting the fixed amount. " << endl;
        cout << "$" << fixedRateAmount << " by accepting the fixed rate of " << (FIXED_RATE_ROYALTY * 100)
             << "% per copy sold." << endl;
        cout << "$" << totalVariableAmount << " by accepting the variable rate of "
             << (VARIABLE_RATE_ROYALTY_LESS_4K * 100)
             << "% for the first 4000 copies and " << (VARIABLE_RATE_ROYALTY_GREATER_4K * 100)
             << "% for all copies after" << endl << endl;

        cout << "Your best option would be to take ";
        //25,000 is greatest
        if (FLAT_FEE_TOTAL > fixedRateAmount && FLAT_FEE_TOTAL > totalVariableAmount) {
            cout << "the flat amount.";
        } else if (fixedRateAmount > totalVariableAmount) {//flat rate amount is more than variable rate amount
            cout << "the fixed royalty rate";
        } else { // flat fee and flat rate are not greatest, variable rate must be greatest
            cout << "the variable royalty rate";
        }
        cout << endl << endl;

        cout << "enter 1 to go again, anything else to exit ";
        cin >> doContinue;
    } while (doContinue == 1);

    return 0;
}*/