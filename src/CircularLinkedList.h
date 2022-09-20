#ifndef LAB1_CIRCULARLINKEDLIST_H
#define LAB1_CIRCULARLINKEDLIST_H

#include <iostream>
#include "Node.h"

using namespace std;

class CircularLinkedList
{
private:
    Node* _head = nullptr;

public:
    CircularLinkedList() = default;
    CircularLinkedList(const CircularLinkedList& list);

    virtual ~CircularLinkedList();

    Node* getHead() const;
    Node* getTail() const;

    Node* insertToBegin(int value);
    Node* insertToEnd(int value);

    Node* insertBeforeNode(int value, Node* node);
    Node* insertAfterNode(int value, Node* node);

    void removeNode(Node* node);
};

ostream& operator<<(ostream& os, const CircularLinkedList& list);
istream& operator>>(istream& is, CircularLinkedList& list);
CircularLinkedList operator+(const CircularLinkedList& list1, const CircularLinkedList& list2);

#endif //LAB1_CIRCULARLINKEDLIST_H
