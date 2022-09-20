#include "CircularLinkedList.h"
#include "Node.h"

Node::Node(int value) : _value(value)
{
}

Node::Node(int value, Node* previous, Node* next) : Node(value)
{
    _previous = previous;
    _next = next;
}

Node::~Node()
{
    connectNodes(_previous, _next);
}

void Node::connectNodes(Node* previous, Node* next)
{
    previous->_next = next;
    next->_previous = previous;
}

void Node::placeNodeBetween(Node* new_node, Node* previous, Node* next)
{
    connectNodes(previous, new_node);
    connectNodes(new_node, next);
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

