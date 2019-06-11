//Charles Dodge
//CIST 2362 CRN 63228
//Classwork 3
#include <iostream>

using namespace std;

struct CorporateSalesData {
    string divName;
    double firstQuarterSales = 0;
    double secondQuarterSales = 0;
    double thirdQuarterSales = 0;
    double fourthQuarterSales = 0;
    double totalAnnualSales = 0;
    double averageQuarterSales = 0;
};

int doContinue = 0;

void getSalesData(CorporateSalesData &);

void calcSalesData(CorporateSalesData &);

void displaySalesData(CorporateSalesData &);

int main() {
    do {
        CorporateSalesData divNorth;
        divNorth.divName = "North";
        CorporateSalesData divEast;
        divEast.divName = "East";
        CorporateSalesData divSouth;
        divSouth.divName = "South";
        CorporateSalesData divWest;
        divWest.divName = "West";

        getSalesData(divNorth);
        getSalesData(divEast);
        getSalesData(divSouth);
        getSalesData(divWest);

        calcSalesData(divNorth);
        calcSalesData(divEast);
        calcSalesData(divSouth);
        calcSalesData(divWest);

        displaySalesData(divNorth);
        displaySalesData(divEast);
        displaySalesData(divSouth);
        displaySalesData(divWest);

        cout << "Enter 1 to go again, anything else to exit: ";
        cin >> doContinue;
        cin.ignore();

    } while (doContinue == 1);
    return 0;

}

void getSalesData(CorporateSalesData &data) {
    cout << "Enter first quarter sales for " << data.divName << " division: ";
    cin >> data.firstQuarterSales;
    while (cin.fail() || data.firstQuarterSales < 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Sales must be a positive number: ";
    }

    cout << "Enter second quarter sales for " << data.divName << " division: ";
    cin >> data.secondQuarterSales;
    while (cin.fail() || data.secondQuarterSales < 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Sales must be a positive number: ";
    }

    cout << "Enter third quarter sales for " << data.divName << " division: ";
    cin >> data.thirdQuarterSales;
    while (cin.fail() || data.thirdQuarterSales < 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Sales must be a positive number: ";
    }

    cout << "Enter fourth quarter sales for " << data.divName << " division: ";
    cin >> data.fourthQuarterSales;
    while (cin.fail() || data.fourthQuarterSales < 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Sales must be a positive number: ";
    }

    cout << endl;
}

void calcSalesData(CorporateSalesData &data) {
    data.totalAnnualSales =
            data.firstQuarterSales + data.secondQuarterSales + data.thirdQuarterSales + data.fourthQuarterSales;
    data.averageQuarterSales = data.totalAnnualSales / 4;
}

void displaySalesData(CorporateSalesData &data) {
    cout << "-----Division " << data.divName << "-----" << endl;
    cout << "First quarter sales: $" << data.firstQuarterSales << endl;
    cout << "Second quarter sales: $" << data.secondQuarterSales << endl;
    cout << "Third quarter sales: $" << data.thirdQuarterSales << endl;
    cout << "Fourth quarter sales: $" << data.fourthQuarterSales << endl;
    cout << "Total annual sales: $" << data.totalAnnualSales << endl;
    cout << "Average quarterly sales: $" << data.averageQuarterSales << endl << endl;
}