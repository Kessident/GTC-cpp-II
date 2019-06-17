#include <iostream>
#include "IntStack.h"
#include "Stack.h"

using namespace std;

int STACK_SIZE = 5;

int main() {
    IntStack stack (STACK_SIZE);

    cout << "---Pushing value onto the IntStack---\n";
    for (int i = 0; i < STACK_SIZE; ++i) {
        cout << i << endl;
        stack.push(i);
    }

    cout << "---Printing out values on IntStack--\n";
    stack.print();

    cout << "---Popping values off the IntStack--\n";
    for (int i = 0; i < STACK_SIZE; ++i) {
        cout << stack.pop() << endl;
    }


    Stack<string> otherStack (STACK_SIZE);
    string toBeAdded ("");
    cout << "---Pushing value onto the Stack---\n";
    for (int i = 0; i < STACK_SIZE; ++i) {
        toBeAdded += "a";
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