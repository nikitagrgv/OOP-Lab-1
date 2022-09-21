#include <limits>
#include <iostream>
#include "CircularLinkedList.h"
#include "Node.h"

Node::Node(int value) : _value(value)
{
}

Node::Node(int value, Node* previous, Node* next) : Node(value)
{
    placeBetween(previous, next);
}

Node::~Node()
{
    connectNodes(_previous, _next);
}

void Node::placeBetween(Node* previous, Node* next)
{
    connectNodes(previous, this);
    connectNodes(this, next);
}

void Node::connectNodes(Node* previous, Node* next)
{
    previous->_next = next;
    next->_previous = previous;
}

int Node::getValue() const
{
    return _value;
}

void Node::setValue(int value)
{
    _value = value;
}

Node* Node::getNext() const
{
    return _next;
}

Node* Node::getPrevious() const
{
    return _previous;
}

Node* Node::insertBefore(int value)
{
    return new Node(value, _previous, this);
}

Node* Node::insertAfter(int value)
{
    return new Node(value, this, _next);
}