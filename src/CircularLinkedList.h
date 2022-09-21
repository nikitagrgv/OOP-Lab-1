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
    CircularLinkedList(CircularLinkedList&& list) noexcept;

    virtual ~CircularLinkedList();

    void removeNode(Node* node);

    Node* getHead() const;
    Node* getTail() const;

    Node* findNode(int value) const;

    Node* insertToBegin(int value);
    Node* insertToEnd(int value);

    Node* insertBeforeNode(int value, Node* node);
    Node* insertAfterNode(int value, Node* node);
};

ostream& operator<<(ostream& os, const CircularLinkedList& list);
istream& operator>>(istream& is, CircularLinkedList& list);

#endif //LAB1_CIRCULARLINKEDLIST_H
