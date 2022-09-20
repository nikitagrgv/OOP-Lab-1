#include <iostream>

#include "Node.h"
#include "CircularLinkedList.h"

using namespace std;

int main()
{

    CircularLinkedList list;

    list.insertToEnd(1);

    list.getHead()->setValue(1111111111);

    list.insertToEnd(2);
    auto node3 = list.insertToEnd(3);
    list.insertToBegin(-1);
    list.insertToEnd(4);
    list.insertToEnd(5);
    list.insertToBegin(-2);
    list.insertToEnd(6);

    CircularLinkedList list2 = list;

    node3->setValue(333);
    node3->getNext()->setValue(444);

    cin >> list2;
    cin >> list2;
    cin >> list2;

    cout << "list1: " << list << endl;
    cout << "list2: " << list2 << endl;

    return 0;
}



