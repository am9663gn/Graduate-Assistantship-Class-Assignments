/**
 * ---------------------------------------------------------------
 * File: WaitLine.cpp
 * Course: CSCI 301 – Computer Science II
 * Assignment: Project 6 – Simulation of a Waiting Line
 * ---------------------------------------------------------------
 * @brief Implements the WaitLine class simulation logic.
 * ---------------------------------------------------------------
 * The simulate() function runs a time-based simulation that:
 *   - Creates new customers based on arrival probability
 *   - Serves customers in order of arrival
 *   - Tracks and reports performance statistics
 * ---------------------------------------------------------------
 */

#include "WaitLine.h"
using namespace std;

/**
 * @brief Constructs an empty WaitLine simulation with counters set to zero.
 */
WaitLine::WaitLine()
    : numberOfArrivals(0), numberServed(0), totalTimeWaited(0) {}

/**
 * @brief Simulates customer arrivals, services, and queue progression.
 * 
 * This simulation proceeds minute by minute. For each minute:
 *   - A random number determines if a new customer arrives.
 *   - If the server is busy, it continues service.
 *   - Otherwise, the next waiting customer begins service.
 * 
 * At the end, it displays a summary of:
 *   - Total customers served
 *   - Average wait time
 *   - Customers left in line
 * 
 * @param duration Total simulation duration (minutes).
 * @param arrivalProbability Probability (0–1) that a new customer arrives each minute.
 * @param maxTransactionTime Maximum service duration (minutes) for a customer.
 */
void WaitLine::simulate(int duration, double arrivalProbability, int maxTransactionTime) {
    int transactionTimeLeft = 0;
    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "---- Simulation Start ----" << endl;

    for (int clock = 0; clock < duration; clock++) {
        cout << "\nTime " << clock << ":" << endl;

        // Check if a new customer arrives
        double randomValue = static_cast<double>(rand()) / RAND_MAX;
        if (randomValue < arrivalProbability) {
            numberOfArrivals++;
            int transactionTime = rand() % maxTransactionTime + 1;
            Customer nextArrival(clock, transactionTime, numberOfArrivals);
            line.push(nextArrival);

            cout << "  Customer " << numberOfArrivals
                 << " enters line with a " << transactionTime
                 << "-minute transaction." << endl;
        }

        // Continue serving if current transaction ongoing
        if (transactionTimeLeft > 0) {
            transactionTimeLeft--;
            cout << "  Current customer continues to be served." << endl;
        }
        // Start serving next customer if available
        else if (!line.empty()) {
            Customer nextCustomer = line.front();
            line.pop();

            transactionTimeLeft = nextCustomer.getTransactionTime() - 1;
            int timeWaited = clock - nextCustomer.getArrivalTime();
            totalTimeWaited += timeWaited;
            numberServed++;

            cout << "  Customer " << nextCustomer.getCustomerNumber()
                 << " begins service after waiting " << timeWaited << " minutes." << endl;
        }
    }

    // Simulation summary
    cout << "\n---- Simulation Ends ----" << endl;
    cout << "Total customers served: " << numberServed << endl;

    if (numberServed > 0)
        cout << "Average wait time: "
             << static_cast<double>(totalTimeWaited) / numberServed
             << " minutes" << endl;
    else
        cout << "Average wait time: 0 minutes" << endl;

    cout << "Customers left in line: " << line.size() << endl;
}
