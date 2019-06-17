//
// Created by Charles Dodge on 2019-06-17.
//

#ifndef CLASSWORK_STACK_H
#define CLASSWORK_STACK_H

template<class T>
class Stack {
private:
    T *stackArray;
    int stackSize;
    int top;
public:
    //Constructor
    Stack(int);
    //Copy Constructor
    Stack(const Stack &);
    //Destructor
    ~Stack();

    void push(T);
    T pop();

    void print();

    bool isEmpty() {
        return top == -1;
    };

    bool isFull() {
        return top == (stackSize - 1);
    };

};


//Constructor
template <class T>
Stack<T>::Stack(int size) {
    stackArray = new T[size];
    stackSize = size;
    top = -1;
}

//Copy constructor
template<class T>
Stack<T>::Stack(const Stack & obj) {
    if (obj.stackSize > 0) {
        stackArray = new T[obj.stackSize];
    } else {
        stackArray = nullptr;
    }

    stackSize = obj.stackSize;

    for (int i = 0; i < obj.stackSize; ++i) {
        stackArray[i] = obj.stackArray[i];
    }

    top = obj.top;
}

//destructor
template<class T>
Stack<T>::~Stack() {
    delete [] stackArray;
}

template<class T>
void Stack<T>::push(T data) {
    if (isFull()){
        std::cout << "Stack full";
    } else {
        top++;
        stackArray[top] = data;
    }
}

template<class T>
T Stack<T>::pop() {
    if (isEmpty()) {
        std::cout << "Stack is empty";
    } else {
        T data = stackArray[top];
        top--;
        return data;
    }
}

template<class T>
void Stack<T>::print() {
    std::cout << "Data contained in stack: \n";
    for (int i = 0; i < stackSize; ++i) {
        std::cout << stackArray[i] << std::endl;
    }
}

#endif //CLASSWORK_STACK_H
