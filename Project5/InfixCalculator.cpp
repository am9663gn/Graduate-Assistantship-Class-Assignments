/**
 * @file InfixCalculator.cpp
 * @brief Implementation of the InfixCalculator class.
 * @details
 * Uses stack-based algorithms for validation, conversion, and evaluation
 * of infix arithmetic expressions. Handles invalid input and division errors.
 * 
 * @author Dinesh Seveti
 * @date October 2025
 */

#include "InfixCalculator.h"
#include <iostream>
#include <cctype>
#include <stdexcept>

InfixCalculator::InfixCalculator() : infixExp("") {}

/**
 * Checks if parentheses in the expression are balanced.
 */
bool InfixCalculator::isBalanced(const std::string& exp) {
    Stack<char> s;
    for (char ch : exp) {
        if (ch == '(') s.push(ch);
        else if (ch == ')') {
            if (s.isEmpty()) return false;
            s.pop();
        }
    }
    return s.isEmpty();
}

/**
 * Checks if expression is syntactically valid.
 */
bool InfixCalculator::isWellFormed(const std::string& exp) {
    if (exp.empty()) return false;
    for (size_t i = 0; i < exp.length(); i++) {
        char ch = exp[i];
        if (!isdigit(ch) && ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '(' && ch != ')')
            return false;
        if ((ch == '+' || ch == '-' || ch == '*' || ch == '/') &&
            (i == 0 || i == exp.length() - 1 ||
             ((!isdigit(exp[i - 1]) && exp[i - 1] != ')') ||
              (!isdigit(exp[i + 1]) && exp[i + 1] != '('))))
            return false;
    }
    return true;
}

/**
 * Determines operator precedence.
 */
int InfixCalculator::precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

/**
 * Converts infix expression to postfix using stack-based algorithm.
 */
std::string InfixCalculator::infixToPostfix(const std::string& exp) {
    Stack<char> s;
    std::string result = "";

    for (char ch : exp) {
        if (isdigit(ch)) result += ch;
        else if (ch == '(') s.push(ch);
        else if (ch == ')') {
            while (!s.isEmpty() && s.top() != '(') {
                result += s.top();
                s.pop();
            }
            if (!s.isEmpty()) s.pop();
        } else {
            while (!s.isEmpty() && precedence(s.top()) >= precedence(ch)) {
                result += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.isEmpty()) {
        result += s.top();
        s.pop();
    }
    return result;
}

/**
 * Evaluates postfix expression using stack.
 */
double InfixCalculator::evalPostfix(const std::string& postfix) {
    Stack<double> s;
    for (char ch : postfix) {
        if (isdigit(ch)) {
            s.push(ch - '0');
        } else {
            double b = s.top(); s.pop();
            double a = s.top(); s.pop();
            switch (ch) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/':
                    if (b == 0) throw std::runtime_error("Division by zero");
                    s.push(a / b);
                    break;
                default:
                    throw std::runtime_error("Invalid operator in postfix expression");
            }
        }
    }
    return s.top();
}

/**
 * Validates and sets the infix expression for evaluation.
 */
bool InfixCalculator::setExpression(const std::string& exp) {
    if (!isWellFormed(exp) || !isBalanced(exp)) return false;
    infixExp = exp;
    return true;
}

/**
 * Converts stored infix to postfix and evaluates.
 */
double InfixCalculator::evaluate() {
    std::string postfix = infixToPostfix(infixExp);
    return evalPostfix(postfix);
}
