/**
 * @file main.cpp
 * @brief Driver program for Infix Expression Calculator.
 * @details
 * Continuously prompts the user for infix expressions, checks validity,
 * and evaluates them using stack-based algorithms. Supports error handling
 * and safe termination.
 * 
 * @author Dinesh Seveti
 * @date October 2025
 */

#include <iostream>
#include "InfixCalculator.h"

int main() {
    InfixCalculator calc;
    std::string expr;

    std::cout << "=== Infix Expression Calculator ===\n";
    while (true) {
        std::cout << "\nEnter infix expression (or 'exit' to quit): ";
        std::cin >> expr;
        if (expr == "exit") break;

        if (calc.setExpression(expr)) {
            try {
                std::cout << "Result: " << calc.evaluate() << std::endl;
            } catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
        } else {
            std::cout << "Invalid or unbalanced expression. Please try again.\n";
        }
    }
    std::cout << "\nExiting calculator. Goodbye!\n";
    return 0;
}
