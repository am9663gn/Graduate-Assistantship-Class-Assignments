/**
 * @file DoublyLinkedBag.cpp
 * @brief Implementation of the DoublyLinkedBag class using a doubly linked list.
 *
 * Provides all bag operations such as add, remove, contains, clear, frequency,
 * and conversion to a vector. This file is included in DoublyLinkedBag.h.
 *
 * @author Dinesh Seveti
 * @course CSCI 301
 * @date Fall 2025
 */

#include "DoublyLinkedBag.h"

/**
 * @pre None.
 * @post Initializes an empty bag with headPtr set to nullptr.
 */
template<class T>
DoublyLinkedBag<T>::DoublyLinkedBag() : headPtr(nullptr), itemCount(0) {}

/**
 * @pre None.
 * @post Frees all nodes by calling clear().
 */
template<class T>
DoublyLinkedBag<T>::~DoublyLinkedBag() { clear(); }

/**
 * @pre None.
 * @post Returns the number of items currently in the bag.
 */
template<class T>
int DoublyLinkedBag<T>::getCurrentSize() const { return itemCount; }

/**
 * @pre None.
 * @post Returns true if the bag has no items.
 */
template<class T>
bool DoublyLinkedBag<T>::isEmpty() const { return itemCount == 0; }

/**
 * @param newEntry The item to insert.
 * @pre None.
 * @post Adds newEntry at the beginning of the list. Increases itemCount by 1.
 * @return True if addition succeeds.
 */
template<class T>
bool DoublyLinkedBag<T>::add(const T& newEntry) {
    DoublyNode<T>* newNode = new DoublyNode<T>(newEntry, headPtr, nullptr);
    if (headPtr != nullptr)
        headPtr->prev = newNode;
    headPtr = newNode;
    itemCount++;
    return true;
}

/**
 * @param anEntry The item to remove.
 * @pre None.
 * @post Removes one occurrence of anEntry if found. Decreases itemCount by 1.
 * @return True if removal succeeded, false otherwise.
 */
template<class T>
bool DoublyLinkedBag<T>::remove(const T& anEntry) {
    DoublyNode<T>* target = getPointerTo(anEntry);
    if (target == nullptr) return false;

    if (target->prev != nullptr)
        target->prev->next = target->next;
    else
        headPtr = target->next;

    if (target->next != nullptr)
        target->next->prev = target->prev;

    delete target;
    itemCount--;
    return true;
}

/**
 * @pre None.
 * @post Deletes all nodes and sets itemCount to 0.
 */
template<class T>
void DoublyLinkedBag<T>::clear() {
    while (headPtr != nullptr) {
        DoublyNode<T>* nodeToDelete = headPtr;
        headPtr = headPtr->next;
        delete nodeToDelete;
    }
    itemCount = 0;
}

/**
 * @param anEntry The item to check.
 * @pre None.
 * @post Returns true if bag contains at least one occurrence of anEntry.
 */
template<class T>
bool DoublyLinkedBag<T>::contains(const T& anEntry) const {
    return (getPointerTo(anEntry) != nullptr);
}

/**
 * @param anEntry The item to count.
 * @pre None.
 * @post Returns number of occurrences of anEntry in the bag.
 */
template<class T>
int DoublyLinkedBag<T>::getFrequencyOf(const T& anEntry) const {
    int freq = 0;
    DoublyNode<T>* cur = headPtr;
    while (cur != nullptr) {
        if (cur->item == anEntry) freq++;
        cur = cur->next;
    }
    return freq;
}

/**
 * @pre None.
 * @post Returns a vector containing all items in the bag.
 */
template<class T>
std::vector<T> DoublyLinkedBag<T>::toVector() const {
    std::vector<T> bagContents;
    DoublyNode<T>* cur = headPtr;
    while (cur != nullptr) {
        bagContents.push_back(cur->item);
        cur = cur->next;
    }
    return bagContents;
}

/**
 * @param target The item to search for.
 * @pre None.
 * @post Returns pointer to the node containing target, or nullptr if not found.
 */
template<class T>
DoublyNode<T>* DoublyLinkedBag<T>::getPointerTo(const T& target) const {
    DoublyNode<T>* cur = headPtr;
    while (cur != nullptr) {
        if (cur->item == target) return cur;
        cur = cur->next;
    }
    return nullptr;
}
