/**
 * ---------------------------------------------------------------
 * File: WaitLine.h
 * Course: CSCI 301 – Computer Science II
 * Assignment: Project 6 – Simulation of a Waiting Line
 * ---------------------------------------------------------------
 * @brief Declares the WaitLine class which simulates a single 
 *        service queue using a time-driven simulation.
 * 
 * The WaitLine class:
 *  - Manages arrivals using probability
 *  - Serves customers in FIFO order using a queue
 *  - Tracks statistics: arrivals, served customers, wait time, remaining queue
 * ---------------------------------------------------------------
 */

#ifndef WAITLINE_H
#define WAITLINE_H

#include <queue>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Customer.h"

class WaitLine {
private:
    std::queue<Customer> line;   ///< Queue representing the line of waiting customers.
    int numberOfArrivals;        ///< Total number of customers that entered the line.
    int numberServed;            ///< Total number of customers served.
    int totalTimeWaited;         ///< Accumulated waiting time of all served customers.

public:
    /**
     * @brief Default constructor initializing counters to zero.
     */
    WaitLine();

    /**
     * @brief Simulates the waiting line for a given time duration.
     * 
     * @param duration Total simulation time (in minutes).
     * @param arrivalProbability Probability (0–1) that a new customer arrives each minute.
     * @param maxTransactionTime Maximum time (minutes) for any single transaction.
     */
    void simulate(int duration, double arrivalProbability, int maxTransactionTime);
};

#endif
