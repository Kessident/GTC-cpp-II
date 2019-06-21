//
// Created by Charles Dodge on 2019-06-17.
//

#ifndef LAB_10_DYNAMICSTACK_H
#define LAB_10_DYNAMICSTACK_H

template<class T>
class DynamicStack {
private:
    struct StackNode {
        T value;
        StackNode *next;
    };
    StackNode *top;
    int numNodes;
public:
    //Constructor
    DynamicStack() {
        top = nullptr;
        numNodes = 0;
    };

    //Copy Constructor
    DynamicStack(DynamicStack &);

    //Destructor
    ~DynamicStack();

    void push(T);

    void pop(T &);

    int size() {
        return numNodes;
    }

    bool isEmpty() {
        return top == nullptr;
    };

    void print();
};

//Copy Constructor
template<class T>
DynamicStack<T>::DynamicStack(DynamicStack &obj) {
    StackNode *nodePtr = obj.head;
    while (nodePtr) {
        push(nodePtr->value);
        nodePtr = nodePtr->next;
    }
    numNodes = obj.numNodes;
}

//Destructor
template<class T>
DynamicStack<T>::~DynamicStack() {
    StackNode *nodePtr;
    StackNode *next;

    nodePtr = top;

    while (nodePtr != nullptr) {
        next = nodePtr->next;
        delete nodePtr;
        nodePtr = next;
    }
}

template<class T>
void DynamicStack<T>::push(T value) {
    StackNode *newNode = nullptr;

    newNode = new StackNode;
    newNode->value = value;

    if (isEmpty()) {
        top = newNode;
        newNode->next = nullptr;
    } else {
        newNode->next = top;
        top = newNode;
    }
    numNodes++;
}

//Pops off first node and returns its value
//Returns nullptr if empty
template<class T>
void DynamicStack<T>::pop(T & item) {
    StackNode *temp = nullptr;

    if (isEmpty()) {
        std::cout << "Stack is empty";
    } else {
        item = top->value;
        temp = top->next;
        delete top;
        top = temp;
    }

    numNodes--;
}

template<class T>
void DynamicStack<T>::print() {
    //
    StackNode *nodePtr = nullptr;

    if (top) {
        nodePtr = top;

        //While nodes exist
        while (nodePtr){
            std::cout << nodePtr->value << std::endl; // Print out value
            nodePtr = nodePtr->next; // Advance pointer
        }
    } else {
        std::cout << "No values\n";
    }
}


#endif //LAB_10_DYNAMICSTACK_H
