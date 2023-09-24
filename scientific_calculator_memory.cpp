#include "scientific_calculator_memory.h"
#include <cmath>
#include <cassert>
#include <stdexcept>

using namespace std;

Calculator::Calculator() {
    result = 0.0;
    next = nullptr;
}

double Calculator::performOperation(double num1, double num2, char op) {
    try {
        switch (op) {
            case '+':
                return num1 + num2;
            case '-':
                return num1 - num2;
            case '*':
                return num1 * num2;
            case '/':
                assert(num2 != 0 && "Division by zero.");
                return num1 / num2;
            case '%':
                assert(num2 != 0 && "Modulo operation with divisor 0.");
                return fmod(num1, num2);
            case '^':
                return pow(num1, num2);
            default:
                throw invalid_argument("Error: Invalid operator.");
        }
    } catch (const exception& e) {
        cerr << e.what() << endl;
        return NAN;
    }
}

double Calculator::squareRoot(double num) {
    try {
        assert(num >= 0 && "Square root of a negative number.");
        return sqrt(num);
    } catch (const exception& e) {
        cerr << e.what() << endl;
        return NAN;
    }
}

double Calculator::naturalLog(double num) {
    try {
        assert(num > 0 && "Natural logarithm of a non-positive number.");
        return log(num);
    } catch (const exception& e) {
        cerr << e.what() << endl;
        return NAN;
    }
}

double Calculator::base10Log(double num) {
    try {
        assert(num > 0 && "Logarithm of a non-positive number.");
        return log10(num);
    } catch (const exception& e) {
        cerr << e.what() << endl;
        return NAN;
    }
}

double Calculator::getResult() const {
    return result;
}

void Calculator::setResult(double value) {
    result = value;
}

Calculator* Calculator::getNext() const {
    return next;
}

void Calculator::setNext(Calculator* nextCalculator) {
    next = nextCalculator;
}

