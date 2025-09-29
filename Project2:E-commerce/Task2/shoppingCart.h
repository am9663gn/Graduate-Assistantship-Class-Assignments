/**
 * @file shoppingCart.h
 * @brief Header file for ShoppingCart class.
 * @author Dinesh
 * @date 09/22/2025
 */

#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "bag.h"
#include "../Task1/item.h"

/**
 * @class ShoppingCart
 * @brief Derived class from Bag<Item> to represent a shopping cart.
 */
class ShoppingCart : public Bag<Item> {
private:
    double totalPrice; ///< Total price of all items in the cart

public:
    /**
     * @brief Default constructor. Initializes totalPrice to 0.0
     */
    ShoppingCart();

    /**
     * @brief Get the total price of items in the cart.
     * @return Total price
     */
    double getTotalPrice() const;

    /**
     * @brief Add an item to the cart and update total price.
     * @param item The item to add
     * @return true if added successfully
     */
    bool add(const Item& item) override;

    /**
     * @brief Remove an item from the cart and update total price.
     * @param item The item to remove
     * @return true if removed successfully
     */
    bool remove(const Item& item) override;

    /**
     * @brief Clear all items from the cart and reset total price.
     */
    void clear() override;
};

#endif // SHOPPINGCART_H
