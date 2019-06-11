//Charles Dodge
//CIST 2362 CRN 63228
/*
//Lab 4 Inventory Class
#include <iostream>
#include "Inventory.h"

using namespace std;

void mainMenu(Inventory&);
void editItemNum(Inventory&);
void editQuant(Inventory&);
void editCost(Inventory&);
void displayInfo(Inventory&);


int main() {
    cout << "This is a simple driver program for an inventory item\n";
    Inventory inv;
    mainMenu(inv);

    return 0;
}

void mainMenu(Inventory& inv) {
    cout << "-----Main menu-----\n";
    cout << "1 to edit item number\n";
    cout << "2 to edit quantity\n";
    cout << "3 to edit cost\n";
    cout << "4 to display info\n";
    cout << "Anything else to exit\n";
    int selection;
    cin >> selection;
    switch (selection){
        case 1:
            editItemNum(inv);
            break;
        case 2:
            editQuant(inv);
            break;
        case 3:
            editCost(inv);
            break;
        case 4:
            displayInfo(inv);
            break;
        default:
            break;
    }
}

void editItemNum(Inventory& inv) {
    int itemNumber;
    cout << "Enter the item number: ";
    cin >> itemNumber;
    while (cin.fail() || itemNumber < 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Item number must be a positive number: ";
        cin >> itemNumber;
    }
    inv.setItemNumber(itemNumber);\
    cout << endl;
    mainMenu(inv);
}

void editQuant(Inventory& inv) {
    int quantity;
    cout << "Enter the quantity: ";
    cin >> quantity;
    while (cin.fail() || quantity < 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Quantity must be a positive number: ";
        cin >> quantity;
    }
    inv.setQuantity(quantity);
    cout << endl;
    mainMenu(inv);
}

void editCost(Inventory& inv) {
    double cost;
    cout << "Enter the cost: ";
    cin >> cost;
    while (cin.fail() || cost < 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Cost must be a positive number: ";
        cin >> cost;
    }
    inv.setCost(cost);
    cout << endl;
    mainMenu(inv);
}

void displayInfo(Inventory& inv) {
    cout << "\nInventory item "<< inv.getItemNumber();
    cout << "\nQuantity: " << inv.getQuantity();
    cout << "\nCost: " << inv.getCost();
    cout << "\nTotal cost: " << inv.getTotalCost();
    cout << endl << endl;
    mainMenu(inv);
}*/



//Lab 4 Circle Class

#include <iostream>
#include "Circle.h"

using namespace std;
int doContinue = 0;

int main() {
    do {
        double radius;
        cout << "What is the radius of your circle? ";
        cin >> radius;
        while (cin.fail() || radius < 0) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Radius must be a positive number: ";
            cin >> radius;
        }

        Circle circ{radius};

        cout << "Area is " << circ.getArea() << endl;
        cout << "Diameter is " << circ.getDiameter() << endl;
        cout << "Circumference is " << circ.getCircumference() << endl;
        cout << endl << "enter 1 to go again, anything else to exit ";
        cin >> doContinue;
        cin.ignore();
    } while (doContinue == 1);
    return 0;
}
