#include <iostream>
#include <limits>

#include "CircularLinkedList.h"
#include "Node.h"

CircularLinkedList::CircularLinkedList(const CircularLinkedList& list)
{
    *this += list;
}

CircularLinkedList::CircularLinkedList(CircularLinkedList&& list) noexcept
{
    std::swap(this->_head, list._head);
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

Node* CircularLinkedList::findNode(int value) const
{
    if (_head == nullptr)
    {
        return nullptr;
    }

    auto current_node = _head;
    do
    {
        if (current_node->getValue() == value)
        {
            return current_node;
        }
        current_node = current_node->getNext();
    } while (current_node != _head);

    return nullptr;
}

int CircularLinkedList::getSize() const
{
    int size = 0;
    doForEachNodeConst([&size](auto node)
                       {
                           size++;
                       });

    return size;
}

void CircularLinkedList::doForEachNode(const std::function<void(Node*)>& f)
{
    if (_head == nullptr)
    {
        return;
    }

    auto current_node = _head;
    do
    {
        f(current_node);
        current_node = current_node->getNext();
    } while (current_node != _head);
}

void CircularLinkedList::doForEachNodeConst(const std::function<void(const Node*)>& f) const
{
    const_cast<CircularLinkedList*>(this)->doForEachNode(f);
}

std::ostream& operator<<(std::ostream& os, const CircularLinkedList& list)
{
    list.doForEachNodeConst([&os](auto node)
                            {
                                os << node->getValue() << " ";
                            });

    return os;
}

std::istream& operator>>(std::istream& is, CircularLinkedList& list)
{
    int value;
    is >> value;

    if (is.fail())
    {
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        throw std::runtime_error("Invalid node value");
    }

    list.insertToEnd(value);

    return is;
}

CircularLinkedList& CircularLinkedList::operator+=(const CircularLinkedList& list)
{
    list.doForEachNodeConst([this](auto node)
                            {
                                this->insertToEnd(node->getValue());
                            });

    return *this;
}

CircularLinkedList operator+(const CircularLinkedList& list1, const CircularLinkedList& list2)
{
    CircularLinkedList sum_list;

    sum_list += list1;
    sum_list += list2;

    return sum_list;
}
