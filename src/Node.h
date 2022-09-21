#ifndef LAB1_NODE_H
#define LAB1_NODE_H

class Node
{
    friend class CircularLinkedList;

private:
    int _value;
    Node* _next = this;
    Node* _previous = this;

private:
    explicit Node(int value);
    Node(int value, Node* previous, Node* next);
    virtual ~Node();

    void placeBetween(Node* previous, Node* next);

    static void connectNodes(Node* previous, Node* next);

public:
    Node(const Node& node) = delete;

    int getValue() const;
    void setValue(int value);

    Node* getNext() const;
    Node* getPrevious() const;
};

#endif //LAB1_NODE_H
