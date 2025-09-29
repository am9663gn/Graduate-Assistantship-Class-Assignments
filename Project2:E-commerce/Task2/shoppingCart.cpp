/**
 * @file shoppingCart.cpp
 * @brief Implementation file for ShoppingCart class.
 */

#include "shoppingCart.h"

ShoppingCart::ShoppingCart() : totalPrice(0.0) {}

double ShoppingCart::getTotalPrice() const {
    return totalPrice;
}

bool ShoppingCart::add(const Item& item) {
    bool added = Bag<Item>::add(item);
    if (added) {
        totalPrice += item.getPrice() * item.getQuantity();
    }
    return added;
}

bool ShoppingCart::remove(const Item& item) {
    bool removed = Bag<Item>::remove(item);
    if (removed) {
        totalPrice -= item.getPrice() * item.getQuantity();
    }
    return removed;
}

void ShoppingCart::clear() {
    Bag<Item>::clear();
    totalPrice = 0.0;
}
