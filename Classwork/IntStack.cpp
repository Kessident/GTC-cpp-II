//
// Created by Charles Dodge on 2019-06-17.
//

#include <iostream>
#include "IntStack.h"

//Constructor
IntStack::IntStack(int size) {
    stackArray = new int[size];
    stackSize = size;
    top = -1;
}

//Copy Constructor
IntStack::IntStack(const IntStack& previousStack){
    //Stack Initialized
    if (previousStack.stackSize > 0){
        stackArray = new int[previousStack.stackSize];
    } else {
        stackArray = nullptr;
    }

    stackSize = previousStack.stackSize;

    for (int i = 0; i < stackSize; ++i) {
        stackArray[i] = previousStack.stackArray[i];
    }

    top = previousStack.top;
}

//Destructor
IntStack::~IntStack(){
    delete [] stackArray;
}

void IntStack::push(int num) {
    if (isFull()) {
        std::cout << "Stack is full";
    } else {
        top++;
        stackArray[top] = num;
    }
}

int IntStack::pop() {
    if (isEmpty()) {
        std::cout << "Stack is empty";
        return 0;
    } else {
        int data = stackArray[top];
        top--;
        return data;
    }
}

void IntStack::print() {
    std::cout << "Data contained in stack: ";
    for (int i = 0; i < stackSize; ++i) {
        std::cout << stackArray[i] << ", ";
    }
    std::cout << std::endl;
}

bool IntStack::isFull() {
    return top == (stackSize - 1);
}

bool IntStack::isEmpty() {
    return top == -1;
}