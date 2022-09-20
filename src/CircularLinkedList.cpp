#include <iostream>
#include <limits>

#include "CircularLinkedList.h"
#include "Node.h"

void foo() const;
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

CircularLinkedList::CircularLinkedList(CircularLinkedList&& list) noexcept
{
    swap(this->_head, list._head);
}

CircularLinkedList::~CircularLinkedList()
{
    while (_head != nullptr)
    {
        removeNode(_head);
    }
}

void CircularLinkedList::removeNode(Node* node)
{
    if (node == _head)
    {
        Node* node_after_head = _head->getNext();

        if (node_after_head == _head)
        {
            _head = nullptr;
        }
        else
        {
            _head = node_after_head;
        }
    }

    delete node;
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
    return new Node(value, node->getPrevious(), node);
}

Node* CircularLinkedList::insertAfterNode(int value, Node* node)
{
    return new Node(value, node, node->getNext());
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
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        throw runtime_error("Invalid node value");
    }

    list.insertToEnd(value);

    return is;
}

