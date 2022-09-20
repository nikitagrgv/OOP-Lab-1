#include <iostream>

#include "CircularLinkedList.h"
#include "Node.h"

using namespace std;

CircularLinkedList::CircularLinkedList(const CircularLinkedList& list)
{
    _head = new Node(list.getHead()->getValue());

    auto node = list.getHead()->getNext();
    do
    {
        insertToEnd(node->getValue());
        node = node->getNext();
    } while (node != list.getHead());
}

CircularLinkedList::~CircularLinkedList()
{
    for (auto node = getTail(); node != _head; node = getTail())
    {
        delete node;
    }

    delete _head;
}

Node* CircularLinkedList::getHead() const
{
    return _head;
}

Node* CircularLinkedList::getTail() const
{
    if (_head == nullptr)
    {
        return nullptr;
    }

    return _head->getPrevious();
}

Node* CircularLinkedList::insertToBegin(int value)
{
    if (_head == nullptr)
    {
        _head = new Node(value);
        return _head;
    }

    _head = insertBeforeNode(value, _head);
    return _head;
}

Node* CircularLinkedList::insertToEnd(int value)
{
    if (_head == nullptr)
    {
        _head = new Node(value);
        return _head;
    }

    return insertBeforeNode(value, _head);
}

Node* CircularLinkedList::insertBeforeNode(int value, Node* node)
{
    auto new_node = new Node(value);
    Node::placeNodeBetween(new_node, node->getPrevious(), node);
    return new_node;
}

Node* CircularLinkedList::insertAfterNode(int value, Node* node)
{
    auto new_node = new Node(value);
    Node::placeNodeBetween(new_node, node, node->getNext());
    return new_node;
}

void CircularLinkedList::removeNode(Node* node)
{
    if (node == _head)
    {
        _head = nullptr;
    }

    delete node;
}

ostream& operator<<(ostream& os, const CircularLinkedList& list)
{
    auto node = list.getHead();

    do
    {
        cout << node->getValue() << " ";
        node = node->getNext();
    } while (node != list.getHead());

    return os;
}

istream& operator>>(istream& is, CircularLinkedList& list)
{
    int value;
    auto& result = is >> value;

    if (result.fail())
    {
        cin.clear();
        cin.ignore(1);

        throw runtime_error("Invalid node value");
    }

    list.insertToEnd(value);

    return is;
}

