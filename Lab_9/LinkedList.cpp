//Charles Dodge
//CIST 2362 CRN 63228
//Lab 9 Linked List

#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList(const LinkedList &list) {
    ListNode *nodePtr = list.head;
    while (nodePtr) {
        appendNode(nodePtr->value);
        nodePtr = nodePtr->nextNode;
    }

    /*
    ListNode *nextNode;
    ListNode *nodePtr;

    //If copied list is empty
    if (!list.head){
        head = nullptr;
    } else {//Deep copy all values
        head = new ListNode;
        //Copy over value and pointer to nextNode
        head->value = list.head->value;

//        head->nextNode = list.head->nextNode;

        //Advance nodePtr
        nodePtr = head;
        //advance nextNode
        nextNode = list.head->nextNode;

        while (nextNode){
            nodePtr->nextNode = new ListNode;
            nodePtr = nodePtr->nextNode;
            nodePtr->value = nextNode->value;

            nextNode = nextNode->nextNode;
        }
    }
*/
}

void LinkedList::appendNode(int val) {
    ListNode *newNode;
    ListNode *nodePtr;

    newNode = new ListNode();
    newNode->value = val;
    newNode->nextNode = nullptr;

    //Check if first node being inserted
    if (!head) {
        head = newNode;

    } else {
        nodePtr = head; // ptr to head

        while (nodePtr->nextNode) { //While nodes
            nodePtr = nodePtr->nextNode; //Advance to next node
        }
        //Once no more nodes, set final node ptr to new node
        nodePtr->nextNode = newNode;
    }
}

void LinkedList::deleteNode(int val) {
    ListNode *nodePtr;
    ListNode *previousNode;

    //if empty list
    if (!head)
        return;

    //Check first node
    if (head->value == val) {
        nodePtr = head->nextNode;
        delete head;
        head = nodePtr;
    } else {
        nodePtr = previousNode = head;

        //while not end of list, and not found val, continue
        while (nodePtr != nullptr && nodePtr->value != val) {
            previousNode = nodePtr;
            nodePtr = nodePtr->nextNode;
        }
        if (nodePtr) {
            previousNode->nextNode = nodePtr->nextNode;
            delete nodePtr;
        }
    }

}

void LinkedList::insertNode(int val) {
    ListNode *newNode; //node to be inserted
    ListNode *nodePtr; //ptr to traverse list
    ListNode *previousNode; // ptr to previous node

    //Allocate new node
    newNode = new ListNode();
    newNode->value = val;
    newNode->nextNode = nullptr;
    //If first
    if (!head) {
        head = newNode;
    } else {
        nodePtr = head;
        previousNode = nullptr;

        //While current node value < val, continue walking
        while (nodePtr != nullptr && nodePtr->value < val) {
            previousNode = nodePtr;
            nodePtr = nodePtr->nextNode;
        }

        //If node to be inserted is first in list
        if (previousNode == nullptr) {
            head = newNode;
            newNode->nextNode = nodePtr;
        } else {
            previousNode->nextNode = newNode;
            newNode->nextNode = nodePtr;
        }
    }
}

void LinkedList::displayList() const {
    //Traverse List
    ListNode *nodePtr;

    if (head) {
        nodePtr = head;

        //While next node exists
        while (nodePtr->nextNode) {
            std::cout << nodePtr->value << ", "; // Display each value
            nodePtr = nodePtr->nextNode; //Advance pointer
        }
        //Print out last node's value
        std::cout << nodePtr->value << std::endl;
    } else {
        std::cout << "No values\n";
    }
}

void LinkedList::reverseList() {
    ListNode *previous = nullptr;
    ListNode *nodePtr = head;
    ListNode *nextNode = nullptr;

    while (nodePtr != nullptr) {
        //Store next
        nextNode = nodePtr->nextNode;
        //Reverse pointer
        nodePtr->nextNode = previous;
        //Move pointers ahead
        previous = nodePtr;
        nodePtr = nextNode;
    }
    head = previous;
}

//Destructor
LinkedList::~LinkedList() {
    ListNode *nodePtr;
    ListNode *nextNode;

    nodePtr = head;

    //While more nodes exist
    while (nodePtr != nullptr) {
        //Store pointer to next node
        nextNode = nodePtr->nextNode;

        //Delete current node
        delete nodePtr;

        //Point to next node
        nodePtr = nextNode;
    }
}