/**
 * ---------------------------------------------------------------
 * File: main.cpp
 * Course: CSCI 301 – Computer Science II
 * Assignment: Project 6 – Simulation of a Waiting Line
 * ---------------------------------------------------------------
 * @brief Interactive version that lets the user input parameters
 *        for the waiting line simulation.
 * ---------------------------------------------------------------
 */

#include "WaitLine.h"
#include <limits>
using namespace std;

/**
 * @brief Main function that accepts user input and runs simulation.
 */
int main() {
    WaitLine simulation;

    int duration;
    double arrivalProbability;
    int maxTransactionTime;

    cout << "===== Waiting Line Simulation =====" << endl;

    // Get duration
    cout << "Enter simulation duration (in minutes): ";
    while (!(cin >> duration) || duration <= 0) {
        cout << "Invalid input. Please enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Get arrival probability
    cout << "Enter arrival probability (0.0 – 1.0): ";
    while (!(cin >> arrivalProbability) || arrivalProbability < 0.0 || arrivalProbability > 1.0) {
        cout << "Invalid input. Enter a value between 0.0 and 1.0: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Get max transaction time
    cout << "Enter maximum transaction time (in minutes): ";
    while (!(cin >> maxTransactionTime) || maxTransactionTime <= 0) {
        cout << "Invalid input. Please enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "\nStarting simulation...\n" << endl;

    simulation.simulate(duration, arrivalProbability, maxTransactionTime);

    return 0;
}
