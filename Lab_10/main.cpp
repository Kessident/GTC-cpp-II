//Charles Dodge
//CIST 2362 CRN 63228
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
}


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
        string temp = dynStack.pop();
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