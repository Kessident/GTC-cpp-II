//Charles Dodge
//CIST 2362 CRN 63228
//Lab 9 Linked List

#ifndef LAB_9_LINKEDLIST_H
#define LAB_9_LINKEDLIST_H


class LinkedList {
private:
    struct ListNode {
        int value;
        struct ListNode *nextNode;
    };

    ListNode *head;

public:
    LinkedList(){head = nullptr;}
    LinkedList (const LinkedList&);

    ~LinkedList();

    void appendNode(int);
    void insertNode(int);
    void deleteNode(int);
    void displayList() const;
    void reverseList();
};


#endif //LAB_9_LINKEDLIST_H
