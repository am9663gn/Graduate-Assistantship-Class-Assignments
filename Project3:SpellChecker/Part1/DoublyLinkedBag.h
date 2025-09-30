/**
 * @file DoublyLinkedBag.h
 * @brief Header file for the DoublyLinkedBag class.
 *
 * This class implements the ADT Bag using a doubly linked list. 
 * The bag supports insertion, removal, frequency counting, containment checks,
 * and conversion to a vector for easy traversal.
 *
 * The headPtr points to the first node of the list. Each node links forward and backward.
 *
 * @author Dinesh Seveti
 * @course CSCI 301
 * @date Fall 2025
 */

#ifndef DOUBLY_LINKED_BAG_H
#define DOUBLY_LINKED_BAG_H

#include "DoublyNode.h"
#include <vector>

template<class T>
class DoublyLinkedBag {
private:
    DoublyNode<T>* headPtr;   ///< Pointer to the first node
    int itemCount;            ///< Number of items in the bag

    /**
     * Locates the node containing target.
     * @param target item to find
     * @pre None.
     * @post Returns pointer to node containing target, or nullptr if not found.
     */
    DoublyNode<T>* getPointerTo(const T& target) const;

public:
    /** @pre None. @post Creates an empty bag. */
    DoublyLinkedBag();

    /** @pre None. @post Clears all nodes before destruction. */
    ~DoublyLinkedBag();

    /** @pre None. @post Returns number of items currently in the bag. */
    int getCurrentSize() const;

    /** @pre None. @post Returns true if bag is empty, false otherwise. */
    bool isEmpty() const;

    /** 
     * @param newEntry item to add
     * @pre None.
     * @post Adds newEntry to the front of the list.
     * @return True if successfully added.
     */
    bool add(const T& newEntry);

    /**
     * @param anEntry item to remove
     * @pre anEntry must exist in the bag.
     * @post Removes one occurrence of anEntry if found.
     * @return True if removed, false otherwise.
     */
    bool remove(const T& anEntry);

    /** @pre None. @post Removes all items from the bag. */
    void clear();

    /** @param anEntry item to check
     *  @pre None.
     *  @post Returns true if bag contains anEntry.
     */
    bool contains(const T& anEntry) const;

    /** 
     * @param anEntry item to count
     * @pre None.
     * @post Returns the number of times anEntry appears in the bag.
     */
    int getFrequencyOf(const T& anEntry) const;

    /** 
     * @pre None.
     * @post Returns a vector with all items in the bag.
     */
    std::vector<T> toVector() const;
};

// Implementation is included for template
#include "DoublyLinkedBag.cpp"
#endif
