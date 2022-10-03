#include <iostream>
#include <limits>

#include "CircularLinkedList.h"
#include "Node.h"

CircularLinkedList::CircularLinkedList(const CircularLinkedList& list)
{
    *this += list;
}

CircularLinkedList::CircularLinkedList(CircularLinkedList&& list)
{
    std::swap(this->_head, list._head);
}

CircularLinkedList::~CircularLinkedList()
{
    clear();
}

void CircularLinkedList::removeNode(Node& node)
{
    if (&node == _head)
    {
        auto node_after_head = &_head->getNext();

        if (node_after_head == _head)
        {
            _head = nullptr;
        }
        else
        {
            _head = node_after_head;
        }
    }

    delete &node;
}

void CircularLinkedList::clear()
{
    while (_head != nullptr)
    {
        removeNode(*_head);
    }
}

Node& CircularLinkedList::getHead() const
{
    throwIfZeroSize();

    return *_head;
}

Node& CircularLinkedList::getTail() const
{
    throwIfZeroSize();

    return _head->getPrevious();
}

Node& CircularLinkedList::insertToBegin(int value)
{
    _head = &insertToEnd(value);

    return *_head;
}

Node& CircularLinkedList::insertToEnd(int value)
{
    if (_head == nullptr)
    {
        _head = new Node(value);
        return *_head;
    }

    return _head->insertBefore(value);
}

Node& CircularLinkedList::findNode(int value) const
{
    throwIfZeroSize();

    auto current_node = _head;
    do
    {
        if (current_node->getValue() == value)
        {
            return *current_node;
        }
        current_node = &current_node->getNext();
    } while (current_node != _head);

    throw std::runtime_error("No such node");
}

void CircularLinkedList::throwIfZeroSize() const
{
    if (_head == nullptr)
    {
        throw std::runtime_error("CircularLinkedList has zero size");
    }
}

int CircularLinkedList::getSize() const
{
    int size = 0;
    doForEachNodeConst([&size](const auto& node)
                       {
                           size++;
                       });

    return size;
}

void CircularLinkedList::doForEachNode(const std::function<void(Node&)>& f)
{
    if (_head == nullptr)
    {
        return;
    }

    auto current_node = _head;
    do
    {
        f(*current_node);
        current_node = &current_node->getNext();
    } while (current_node != _head);
}

void CircularLinkedList::doForEachNodeConst(const std::function<void(const Node&)>& f) const
{
    const_cast<CircularLinkedList*>(this)->doForEachNode(f);
}

std::ostream& operator<<(std::ostream& os, const CircularLinkedList& list)
{
    list.doForEachNodeConst([&os](const auto& node)
                            {
                                os << node.getValue() << " ";
                            });

    return os;
}

static void checkIStream(std::istream& is)
{
    if (is.fail())
    {
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        throw std::runtime_error("Invalid CircularLinkedList data in the stream");
    }
}


std::istream& operator>>(std::istream& is, CircularLinkedList& list)
{
    int count;
    is >> count;
    checkIStream(is);

    for (int i = 0; i < count; ++i)
    {
        int value;
        is >> value;
        checkIStream(is);
        list.insertToEnd(value);
    }

    return is;
}

CircularLinkedList& CircularLinkedList::operator+=(const CircularLinkedList& list)
{
    list.doForEachNodeConst([this](const auto& node)
                            {
                                this->insertToEnd(node.getValue());
                            });

    return *this;
}

CircularLinkedList& CircularLinkedList::operator=(const CircularLinkedList& list)
{
    if (&list != this)
    {
        CircularLinkedList list_copy(list);
        std::swap(list_copy._head, this->_head);
    }

    return *this;
}

CircularLinkedList& CircularLinkedList::operator=(CircularLinkedList&& list)
{
    CircularLinkedList tmp(std::move(list));
    std::swap(tmp._head, this->_head);

    return *this;
}

CircularLinkedList operator+(const CircularLinkedList& list1, const CircularLinkedList& list2)
{
    CircularLinkedList sum_list;

    sum_list += list1;
    sum_list += list2;

    return sum_list;
}
