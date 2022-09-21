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

    cout << list1 << endl;
    cout << list2 << endl;

    int sum = 0;
    list1.doForEachNodeConst([&sum](auto node)
                             {
                                 sum += node->getValue();
                             });

    cout << "SUM: " << sum << endl;

    cout << "size1 " << list1.getSize() << endl;
    cout << "size2 " << list2.getSize() << endl;

    return 0;
}



