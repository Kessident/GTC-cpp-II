//Charles Dodge
//CIST 2362 CRN 63228
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

    cout << "---Printing out values on Stack--\n";
    otherStack.print();

    cout << "---Popping values off the Stack--\n";
    for (int i = 0; i < STACK_SIZE; ++i) {
        cout << otherStack.pop() << endl;
    }

    return 0;
}