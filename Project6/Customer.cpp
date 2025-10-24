/**
 * ---------------------------------------------------------------
 * File: Customer.cpp
 * Course: CSCI 301 – Computer Science II
 * Assignment: Project 6 – Simulation of a Waiting Line
 * ---------------------------------------------------------------
 * @brief Implements the Customer class defined in Customer.h.
 * ---------------------------------------------------------------
 * This file contains definitions for:
 *  - Default constructor
 *  - Parameterized constructor
 *  - Getter methods for arrival time, transaction time, and ID
 * ---------------------------------------------------------------
 */

#include "Customer.h"

/**
 * @brief Default constructor initializing all data members to zero.
 */
Customer::Customer() : arrivalTime(0), transactionTime(0), customerNumber(0) {}

/**
 * @brief Constructs a new Customer object with given parameters.
 * @param arrival The time when the customer arrives.
 * @param transaction The required transaction time.
 * @param number The unique customer ID number.
 */
Customer::Customer(int arrival, int transaction, int number)
    : arrivalTime(arrival), transactionTime(transaction), customerNumber(number) {}

/**
 * @brief Gets the time when the customer arrived.
 * @return The arrival time in minutes.
 */
int Customer::getArrivalTime() const {
    return arrivalTime;
}

/**
 * @brief Gets the time needed to complete the customer's transaction.
 * @return The transaction duration in minutes.
 */
int Customer::getTransactionTime() const {
    return transactionTime;
}

/**
 * @brief Gets the unique ID number of the customer.
 * @return The customer's assigned number.
 */
int Customer::getCustomerNumber() const {
    return customerNumber;
}
