/**
 * ---------------------------------------------------------------
 * File: Customer.h
 * Course: CSCI 301 – Computer Science II
 * Assignment: Project 6 – Simulation of a Waiting Line
 * ---------------------------------------------------------------
 * @brief Defines the Customer class representing an individual 
 *        customer in the waiting line simulation.
 * 
 * Each Customer object stores:
 *  - Arrival time
 *  - Transaction time
 *  - Customer number (ID)
 * ---------------------------------------------------------------
 * @author Dinesh
 * @date Fall 2025
 * ---------------------------------------------------------------
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer {
private:
    int arrivalTime;        ///< The time (minute) when the customer arrives.
    int transactionTime;    ///< The total time required for the transaction.
    int customerNumber;     ///< The unique number identifying the customer.

public:
    /**
     * @brief Default constructor initializing all fields to zero.
     */
    Customer();

    /**
     * @brief Parameterized constructor to create a customer.
     * @param arrival Arrival time in minutes.
     * @param transaction Transaction duration in minutes.
     * @param number Unique ID number of the customer.
     */
    Customer(int arrival, int transaction, int number);

    /**
     * @brief Gets the customer's arrival time.
     * @return Arrival time (in minutes).
     */
    int getArrivalTime() const;

    /**
     * @brief Gets the customer's transaction time.
     * @return Transaction time (in minutes).
     */
    int getTransactionTime() const;

    /**
     * @brief Gets the customer's ID number.
     * @return Customer number (integer).
     */
    int getCustomerNumber() const;
};

#endif
