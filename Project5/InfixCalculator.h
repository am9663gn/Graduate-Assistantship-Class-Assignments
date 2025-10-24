/**
 * @file InfixCalculator.h
 * @brief Header for InfixCalculator class.
 * @details
 * Defines the public and private members for an infix calculator
 * that converts infix expressions to postfix and evaluates them
 * using stack-based algorithms.
 * 
 * @author Dinesh Seveti
 * @date October 2025
 */

#ifndef INFIXCALCULATOR_H
#define INFIXCALCULATOR_H

#include <string>
#include "Stack.h"

/**
 * @class InfixCalculator
 * @brief Provides functionality to evaluate arithmetic infix expressions.
 */
class InfixCalculator {
private:
    std::string infixExp; ///< The infix expression entered by the user.

    /**
     * @brief Checks if the infix expression contains valid syntax.
     * @param exp The expression to check.
     * @return True if well-formed, false otherwise.
     */
    bool isWellFormed(const std::string& exp);

    /**
     * @brief Verifies that parentheses are balanced.
     * @param exp The expression to check.
     * @return True if balanced, false otherwise.
     */
    bool isBalanced(const std::string& exp);

    /**
     * @brief Converts infix expression to postfix using a stack.
     * @param exp Infix expression.
     * @return Postfix expression string.
     */
    std::string infixToPostfix(const std::string& exp);

    /**
     * @brief Determines operator precedence.
     * @param op Operator character.
     * @return Precedence level (1 or 2).
     */
    int precedence(char op);

    /**
     * @brief Evaluates a postfix expression using stack.
     * @param postfix Postfix expression.
     * @return Numeric result.
     */
    double evalPostfix(const std::string& postfix);

public:
    /** @brief Default constructor initializes empty infixExp. */
    InfixCalculator();

    /**
     * @brief Sets and validates the infix expression.
     * @param exp Input expression string.
     * @return True if valid and set successfully, false otherwise.
     */
    bool setExpression(const std::string& exp);

    /**
     * @brief Evaluates the stored infix expression.
     * @return Numeric result of expression.
     * @throws std::runtime_error for division by zero or invalid syntax.
     */
    double evaluate();
};

#endif
