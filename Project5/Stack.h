/**
 * @file Stack.h
 * @brief Template definition for a link-based Stack ADT using exceptions.
 * @details
 * Implements push, pop, top, and clear operations with runtime error handling.
 * Used by InfixCalculator for infix/postfix processing.
 * 
 * @author Dinesh Seveti
 * @date October 2025
 */

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>

/**
 * @class Stack
 * @brief A generic stack implemented using a singly linked list.
 * @tparam T The type of elements stored in the stack.
 */
template<typename T>
class Stack {
private:
    /**
     * @struct Node
     * @brief Represents a node in the linked list.
     */
    struct Node {
        T data;        ///< Data stored in the node
        Node* next;    ///< Pointer to the next node
        Node(const T& d, Node* n = nullptr) : data(d), next(n) {}
    };

    Node* topNode;     ///< Pointer to the top of the stack

public:
    /** @brief Default constructor initializes an empty stack. */
    Stack() : topNode(nullptr) {}

    /** @brief Destructor clears all stack elements. */
    ~Stack() { clear(); }

    /**
     * @brief Pushes an element onto the top of the stack.
     * @param item Element to push.
     */
    void push(const T& item) {
        topNode = new Node(item, topNode);
    }

    /**
     * @brief Removes the top element from the stack.
     * @throws std::underflow_error if stack is empty.
     */
    void pop() {
        if (isEmpty())
            throw std::underflow_error("Stack underflow: cannot pop empty stack");
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    /**
     * @brief Returns the top element without removing it.
     * @return Top element.
     * @throws std::underflow_error if stack is empty.
     */
    T top() const {
        if (isEmpty())
            throw std::underflow_error("Stack is empty: cannot access top");
        return topNode->data;
    }

    /** @brief Checks whether the stack is empty. */
    bool isEmpty() const { return topNode == nullptr; }

    /** @brief Removes all elements from the stack. */
    void clear() {
        while (!isEmpty()) pop();
    }
};

#endif
