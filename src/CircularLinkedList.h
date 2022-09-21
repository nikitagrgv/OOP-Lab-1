#ifndef LAB1_CIRCULARLINKEDLIST_H
#define LAB1_CIRCULARLINKEDLIST_H

#include <iostream>
#include <functional>
#include "Node.h"

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

    void doForEachNode(const std::function<void(Node*)>& f);
    void doForEachNodeConst(const std::function<void(const Node*)>& f) const;

    Node* findNode(int value) const;

    int getSize() const;

    Node* insertToBegin(int value);
    Node* insertToEnd(int value);

    Node* insertBeforeNode(int value, Node* node);
    Node* insertAfterNode(int value, Node* node);
};

std::ostream& operator<<(std::ostream& os, const CircularLinkedList& list);
std::istream& operator>>(std::istream& is, CircularLinkedList& list);

#endif //LAB1_CIRCULARLINKEDLIST_H
