/**
 * @file DoublyNode.h
 * @brief Node class for a doubly linked list.
 *
 * Each node contains:
 *  - an item (data of type T)
 *  - a pointer to the next node
 *  - a pointer to the previous node
 *
 * This class is used internally by DoublyLinkedBag.
 *
 * @author Dinesh Seveti
 * @course CSCI 301
 * @date Fall 2025
 */

#ifndef DOUBLYNODE_H
#define DOUBLYNODE_H

template<class T>
class DoublyNode {
public:
    T item;                  ///< Data stored in the node
    DoublyNode<T>* next;     ///< Pointer to next node
    DoublyNode<T>* prev;     ///< Pointer to previous node

    /** 
     * @pre None.
     * @post Creates an empty node with null pointers.
     */
    DoublyNode() : next(nullptr), prev(nullptr) {}

    /**
     * @pre None.
     * @post Creates a node with given item, null next/prev.
     */
    DoublyNode(const T& anItem) : item(anItem), next(nullptr), prev(nullptr) {}

    /**
     * @pre None.
     * @post Creates a node with given item and pointers.
     */
    DoublyNode(const T& anItem, DoublyNode<T>* nextNode, DoublyNode<T>* prevNode)
        : item(anItem), next(nextNode), prev(prevNode) {}
};

#endif
