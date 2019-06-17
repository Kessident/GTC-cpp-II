//
// Created by Charles Dodge on 2019-06-17.
//

#ifndef CLASSWORK_STACK_INTSTACK_H
#define CLASSWORK_STACK_INTSTACK_H

class IntStack {
private:
    int * stackArray;
    int stackSize;
    int top;
public:
    IntStack(int);
    IntStack(const IntStack&);
    ~IntStack();

    void push(int);
    int pop();
    void print();

    bool isEmpty();
    bool isFull();
};



#endif //CLASSWORK_STACK_INTSTACK_H
