//
// Created by Charles Dodge on 2019-06-17.
//

#ifndef LAB_10_STATICSTACK_H
#define LAB_10_STATICSTACK_H

template <class T>
class StaticStack {


private:
    T *stackArray;
    int stackSize;
    int top;
public:
    //Constructor
    StaticStack(int);
    //Copy Constructor
    StaticStack(const StaticStack &);
    //Destructor
    ~StaticStack();

    void push(T);
    T pop();

    void print() const;

    bool isEmpty() const {
        return top == -1;
    };

    bool isFull() const {
        return top == (stackSize - 1);
    };

};


//Constructor
template <class T>
StaticStack<T>::StaticStack(int size) {
    stackArray = new T[size];
    stackSize = size;
    top = -1;
}

//Copy constructor
template<class T>
StaticStack<T>::StaticStack(const StaticStack & obj) {
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
StaticStack<T>::~StaticStack() {
    delete [] stackArray;
}

template<class T>
void StaticStack<T>::push(T data) {
    if (isFull()){
        std::cout << "Stack full";
    } else {
        top++;
        stackArray[top] = data;
    }
}

template<class T>
T StaticStack<T>::pop() {
    if (isEmpty()) {
        std::cout << "Stack is empty";
    } else {
        T data = stackArray[top];
        top--;
        return data;
    }
}

template<class T>
void StaticStack<T>::print() const {
    std::cout << "Data contained in stack: \n";
    for (int i = 0; i < stackSize; ++i) {
        std::cout << stackArray[i] << std::endl;
    }
}


#endif //LAB_10_STATICSTACK_H
