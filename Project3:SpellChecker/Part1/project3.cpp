/**
 * @file project3.cpp
 * @brief Test driver for the DoublyLinkedBag ADT implemented with a doubly linked list.
 *
 * This program:
 *   1. Creates an empty DoublyLinkedBag of strings.
 *   2. Tests all basic bag operations (add, remove, contains, frequency, clear).
 *   3. Displays the bag contents after each operation.
 *
 * Expected outputs are included to verify correctness.
 *
 * Example:
 *   Testing the DoublyLinkedBag:
 *   isEmpty: returns 1; should be 1 (true)
 *   Add 6 items to the bag:
 *   Bag contains: one two three four five one
 *
 * Author: Dinesh Seveti
 * Course: CSCI 301
 * Date: Fall 2025
 */

#include <iostream>
#include <string>
#include <vector>
#include "DoublyLinkedBag.h"

using namespace std;

/**
 * Displays all items in the bag.
 * @param bag A const reference to a DoublyLinkedBag<string>.
 * @pre Bag may be empty or contain items.
 * @post Prints bag size and its items in order.
 */
void displayBag(const DoublyLinkedBag<string>& bag) {
    cout << "The bag contains " << bag.getCurrentSize() << " items:" << endl;
    vector<string> bagItems = bag.toVector();
    for (auto& item : bagItems) {
        cout << item << " ";
    }
    cout << endl << endl;
}

/**
 * Tests the core functions of DoublyLinkedBag.
 * @param bag A reference to a DoublyLinkedBag<string>.
 * @pre Bag may be empty.
 * @post Exercises add, remove, contains, frequency, and clear with expected results.
 */
void bagTester(DoublyLinkedBag<string>& bag) {
    cout << "isEmpty: returns " << bag.isEmpty()
         << "; should be 1 (true)" << endl;
    displayBag(bag);

    string items[] = {"one", "two", "three", "four", "five", "one"};
    cout << "Add 6 items to the bag:" << endl;
    for (int i = 0; i < 6; i++) {
        bag.add(items[i]);
    }
    displayBag(bag);

    cout << "isEmpty: returns " << bag.isEmpty()
         << "; should be 0 (false)" << endl;
    cout << "getCurrentSize: returns " << bag.getCurrentSize()
         << "; should be 6" << endl;

    cout << "contains(\"three\"): returns " << bag.contains("three")
         << "; should be 1 (true)" << endl;
    cout << "contains(\"ten\"): returns " << bag.contains("ten")
         << "; should be 0 (false)" << endl;

    cout << "getFrequencyOf(\"one\"): returns "
         << bag.getFrequencyOf("one") << "; should be 2" << endl;

    cout << "remove(\"one\"): returns " << bag.remove("one")
         << "; should be 1 (true)" << endl;
    cout << "getFrequencyOf(\"one\"): returns "
         << bag.getFrequencyOf("one") << "; should be 1" << endl;

    cout << "remove(\"one\"): returns " << bag.remove("one")
         << "; should be 1 (true)" << endl;
    cout << "remove(\"one\"): returns " << bag.remove("one")
         << "; should be 0 (false)" << endl;

    displayBag(bag);

    cout << "After clearing the bag, ";
    bag.clear();
    cout << "isEmpty: returns " << bag.isEmpty()
         << "; should be 1 (true)" << endl;
}

/**
 * Main function that launches the bag tester.
 * @pre None.
 * @post Runs all test cases on the bag implementation.
 * @return 0 upon successful execution.
 */
int main() {
    DoublyLinkedBag<string> bag;
    cout << "Testing the DoublyLinkedBag:" << endl;
    cout << "The initial bag is empty." << endl;
    bagTester(bag);
    cout << "All done!" << endl;
    return 0;
}
