#include <iostream>

#include "CircularLinkedList.h"

using namespace std;

int main()
{
    CircularLinkedList list1;

    list1.insertToEnd(1);
    list1.insertToEnd(2);
    auto node3 = list1.insertToEnd(3);
    list1.insertToEnd(4);
    list1.insertToBegin(-1);
    list1.insertToBegin(-2);
    list1.insertToBegin(-3);
    list1.insertToBegin(-4);

    auto list2 = list1;

    list1.findNode(-2)->setValue(-22222);
    node3->getNext()->getNext()->setValue(12345);
    list1.findNode(4)->setValue(44444);

    list2.findNode(-3)->getPrevious()->setValue(111111);

    auto list12 = list1 + list2 + list2;

    cout << "Size of list 1: " << list1.getSize() << endl;
    cout << "Size of list 2: " << list2.getSize() << endl;
    cout << "Size of list 3: " << list12.getSize() << endl;

    cout << "List 1: " << list1 << endl;
    cout << "List 2: " << list2 << endl;
    cout << "List 3: " << list12 << endl;

    int sum = 0;
    list1.doForEachNodeConst([&sum](auto node)
                             {
                                 sum += node->getValue();
                             });
    cout << "Sum of list 1: " << sum << endl;

    return 0;
}



