//Charles Dodge
//CIST 2362 CRN 63228
//Lab 10 Inventory Bin

#include <iostream>
#include "Inventory.h"
#include "DynamicStack.h"

using namespace std;
int doContinue = 0;

Inventory* addItem();

void removeItem(DynamicStack<Inventory> &);

string getManufactDate();
void printFullStack(DynamicStack<Inventory> &);

int main() {
    DynamicStack<Inventory> invStack;

    while (true) {
        cout << "Enter 1 to add a part to inventory\n"
             << "Enter 2 to remove a part from inventory\n"
             << "Enter 0 to exit\n";
        int userChoice;
        cin >> userChoice;

        while (cin.fail() || (userChoice < 0 || userChoice > 2)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid entry\n";
            cout << "Enter 1 to add a part to inventory\n"
                 << "Enter 2 to remove a part from inventory\n"
                 << "Enter 0 to exit\n";
            cin >> userChoice;
        }

        switch (userChoice){
            case 1: {
                Inventory* newItem = addItem();
                invStack.push(*newItem);
                cout << "item added\n";
                break;
            }
            case 2: {
                removeItem(invStack);
                break;
            }
            default:
                printFullStack(invStack);
                return 0;
        }
    }
}

Inventory* addItem() {
    int serialNum;
    string manufactDate;
    int lotNum;

    cout << "Enter the serial number: ";
    cin >> serialNum;
    while (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid, please try again: ";
        cin >> serialNum;
    }

    manufactDate = getManufactDate();

    cout << "Enter the lot number: ";
    cin >> lotNum;
    while (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid, please try again: ";
        cin >> lotNum;
    }

    Inventory newItem (serialNum, manufactDate, lotNum);

    return new Inventory(serialNum, manufactDate, lotNum);
}

void removeItem(DynamicStack<Inventory> &invStack) {
    if (invStack.isEmpty()) {
        cout << "No items in inventory.\n";
    } else {


        Inventory removedItem;
        invStack.pop(removedItem);

        cout << "--Item removed--\n";
        removedItem.print();
    }

}

string getManufactDate(){
    string year, month, day;
    cout << "Enter year of manufacture: ";
    cin >> year;
    cout << "Enter month of manufacture: ";
    cin >> month;
    cout << "Enter day of manufacture: ";
    cin >> day;

    return month + " " + day + ", " + year;
}

void printFullStack(DynamicStack<Inventory>& invStack){
    cout << "----All items in inventory----\n";
    while (!invStack.isEmpty()) {
        //Remove topmost item and print its information
        Inventory item;
        invStack.pop(item);
        item.print();
    }
}

/*
//Lab 10  Static Queue

#include "StaticQueue.h"
#include <iostream>
#include <string>

using namespace std;

int const QUEUE_SIZE = 5;
int main() {
    StaticQueue<int> queue (QUEUE_SIZE);

//    cout << queue.dequeue();

    cout << "---adding items to queue---\n";
    for (int i = 0; i < QUEUE_SIZE; ++i) {
        cout << i << endl;
        queue.enqueue(i);
    }

    cout << "---Just one more---\n";
    queue.enqueue(5);

    cout << "---values are---\n";
    while (!queue.isEmpty()) {
        cout << queue.dequeue() << endl;
    }

    cout << "---Remove one more---\n";
    queue.dequeue();
    return 0;
}*/


/*
//Lab 10 Dynamic Stack Template
#include <string>
#include <iostream>
#include "DynamicStack.h"

using namespace std;

int STACK_SIZE = 5;

int main() {
    DynamicStack<string> dynStack;

    string toAdd;

    cout << "---Adding items to stack---\n";
    for (int i = 0; i < STACK_SIZE; ++i) {
        toAdd = "Item " + to_string(i+1);
        cout << toAdd << endl;
        dynStack.push(toAdd);
    }

    cout << "---Adding some more items to stack---\n";
    for (int i = 0; i < STACK_SIZE; ++i) {
        toAdd = "Item " + to_string(i+1+5);
        cout << toAdd << endl;
        dynStack.push(toAdd);
    }

    cout << "---Printing out values on the stack---\n";
    dynStack.print();

    int stackSize = dynStack.size();
    cout << "---Removing items from the Stack---\n";
    for (int i = 0; i < stackSize; ++i) {
        string temp;
        dynStack.pop(temp);
        cout << temp << endl;
    }


    return 0;
}*/


/*
//Lab 10 Static Stack Template
#include <iostream>
#include "StaticStack.h"

using namespace std;

int STACK_SIZE = 5;

int main() {
    StaticStack<string> otherStack (STACK_SIZE);
    string toBeAdded;
    cout << "---Pushing value onto the Stack---\n";
    for (int i = 0; i < STACK_SIZE; ++i) {
        toBeAdded = "Item " + to_string(i+1);
        cout << toBeAdded << endl;
        otherStack.push(toBeAdded);
    }

    cout << "---Printing out values on Stack---\n";
    otherStack.print();

    cout << "---Popping values off the Stack---\n";
    for (int i = 0; i < STACK_SIZE; ++i) {
        cout << otherStack.pop() << endl;
    }

    return 0;
}
 */