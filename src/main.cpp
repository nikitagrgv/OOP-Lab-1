#include <iostream>

#include "CircularLinkedList.h"

using namespace std;

int main()
{
    CircularLinkedList list1;

    list1.insertToEnd(1);
    list1.insertToEnd(2);
    list1.insertToEnd(3);
    list1.insertToEnd(4);
    list1.insertToBegin(0);

    cout << "list1: " << list1 << endl;

    auto node1111 = list1.findNode(2)->insertAfter(777)->insertAfter(1111);

    cout << "list1: " << list1 << endl;

    list1.removeNode(node1111);

    cout << "list1: " << list1 << endl;

    list1.findNode(777)->setValue(666);

    cout << "list1: " << list1 << endl;


    cout << "----------------------------------------------" << endl;


    auto list2 = list1;

    cout << "list1: " << list1 << endl;
    cout << "list2: " << list2 << endl << endl;

    list2.removeNode(list2.getHead());
    list2.removeNode(list2.getTail());
    list2.removeNode(list2.getTail());
    list2.removeNode(list2.getTail());

    cout << "list1: " << list1 << endl;
    cout << "list2: " << list2 << endl;


    cout << "----------------------------------------------" << endl;


    auto list3 = list1 + list2 + list2;
    cout << "list3: " << list3 << endl;


    cout << "----------------------------------------------" << endl;


    list3.doForEachNode([](auto node)
                        {
                            auto new_value = node->getValue() + 1;
                            node->setValue(new_value);
                        });
    cout << "list3: " << list3 << endl;


    cout << "----------------------------------------------" << endl;


    int list3_sum = 0;
    int list3_product = 1;
    list3.doForEachNodeConst([&list3_sum, &list3_product](auto node)
                             {
                                 list3_sum += node->getValue();
                                 list3_product *= node->getValue();
                             });
    cout << "Sum of list3: " << list3_sum << endl;
    cout << "Product of list3: " << list3_product << endl;


    return 0;
}



