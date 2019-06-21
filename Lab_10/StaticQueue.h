//Charles Dodge
//CIST 2362 CRN 63228
//Lab 10  Static Queue

#ifndef LAB_10_STATICQUEUE_H
#define LAB_10_STATICQUEUE_H

#include <iostream>

template<class T>
class StaticQueue {
private:
    T *queueArray;  //Pointer to queue array
    int queueSize;  //size
    int front;      //Subscript of front item
    int rear;       //Subscript of rear item
    int numItems;   //Number of items in queue
public:
    //Constructor
    StaticQueue(int size);

    //Copy Constructor
    StaticQueue(const StaticQueue &);

    //Destructor
    ~StaticQueue();

    //Operators
    void enqueue(T);
    T dequeue();
    bool isEmpty();
    bool isFull();
    void clear();

};

//Constructor
template<class T>
StaticQueue<T>::StaticQueue(int size) {
    queueArray = new T[size];
    queueSize = size;
    front = -1;
    rear = -1;
    numItems = 0;
}

//Copy Constructor
template<class T>
StaticQueue<T>::StaticQueue(const StaticQueue &obj) {
    queueArray = new T[obj.queueSize];

    queueSize = obj.queueSize;
    front = obj.front;
    rear = obj.rear;
    numItems = obj.numItems;

    for (int i = 0; i < obj.queueSize; ++i) {
        queueArray[i] = obj.queueArray[i];
    }
}

//Destructor
template<class T>
StaticQueue<T>::~StaticQueue() {
    delete[] queueArray;
}


//Adds item to end of queue
template<class T>
void StaticQueue<T>::enqueue(T item) {
    if (isFull()) {
        std::cout << "Queue is full.\n";
    } else {
        //Move rear subscript forward 1, restart at 0 if at end
        rear = (rear + 1) % queueSize;
        queueArray[rear] = item;
        numItems++;
    }
}

//Removes front item and returns it
template<class T>
T StaticQueue<T>::dequeue() {
    if (isEmpty()) {
        std::cout << "The queue is empty.\n";
    } else {
        //Move front subscript forward 1, restart at 0 if at end
        front = (front + 1) % queueSize;
        numItems--;
        //Store first item to return
        T temp = queueArray[front];
        return temp;
    }
}

//true if numItems == 0, else false
template<class T>
bool StaticQueue<T>::isEmpty() {
    return !numItems;
}

//true if numItems != 0, else false
template<class T>
bool StaticQueue<T>::isFull() {
    return numItems == queueSize;
}

template<class T>
void StaticQueue<T>::clear() {
    front = queueSize - 1;
    rear = queueSize - 1;
    numItems = 0;
}

#endif //LAB_10_STATICQUEUE_H
