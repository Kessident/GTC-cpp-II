#include <iostream>
#include "IntStack.h"
#include "Stack.h"

using namespace std;

int STACK_SIZE = 5;

int main() {
    IntStack intStack (STACK_SIZE);

    cout << "---Pushing value onto the IntStack---\n";
    for (int i = 0; i < STACK_SIZE; ++i) {
        cout << i << endl;
        intStack.push(i);
    }

    cout << "---Printing out values on IntStack--\n";
    intStack.print();

    cout << "---Popping values off the IntStack--\n";
    for (int i = 0; i < STACK_SIZE; ++i) {
        cout << intStack.pop() << endl;
    }


    
    Stack<string> stackTemp (STACK_SIZE);
    string toBeAdded = ("");
    cout << "---Pushing value onto the Stack---\n";
    for (int i = 0; i < STACK_SIZE; ++i) {
        toBeAdded += "a";
        cout << toBeAdded << endl;
        stackTemp.push(toBeAdded);
    }

    cout << "---Printing out values on Stack--\n";
    stackTemp.print();

    cout << "---Popping values off the Stack--\n";
    for (int i = 0; i < STACK_SIZE; ++i) {
        cout << stackTemp.pop() << endl;
    }
    return 0;
}