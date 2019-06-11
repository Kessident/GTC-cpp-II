//Charles Dodge
//CIST 2362 CRN 63228
//Lab 9 Linked List
#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList list;

    //No values
    cout << "--No Values--\n";
    list.displayList();

    list.appendNode(1);
    list.appendNode(3);
    list.appendNode(5);

    //1, 3, 5
    cout << "\n--Insert 1 3 5-- \n";
    list.displayList();

    list.insertNode(2);
    list.insertNode(4);

    //1, 2, 3, 4, 5
    cout << "\n--Insert 2 4--\n";
    list.displayList();

    list.deleteNode(2);
    list.deleteNode(3);

    //1, 4, 5
    cout << "\n--Delete 2 3--\n";
    list.displayList();



    LinkedList list2 = list;
    cout << "\n--Copy List 1 to List 2--\n";
    list2.displayList();


    list.reverseList();
    //5, 4, 1
    cout << "\n--Reverse List--\n";
    list.displayList();
    return 0;
}