#include <iostream>
#include <cmath>
#include <cassert>
#include <stdexcept>

using namespace std;

class Calculator {
public:
    Calculator() {
        result = 0.0;
        next = nullptr;
    }

    double performOperation(double num1, double num2, char op) {
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
                    return (num1 * num2) / 100;
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

    double squareRoot(double num) {
        try {
            assert(num >= 0 && "Square root of a negative number.");
            return sqrt(num);
        } catch (const exception& e) {
            cerr << e.what() << endl;
            return NAN;
        }
    }

    double naturalLog(double num) {
        try {
            assert(num > 0 && "Natural logarithm of a non-positive number.");
            return log(num);
        } catch (const exception& e) {
            cerr << e.what() << endl;
            return NAN;
        }
    }

    double base10Log(double num) {
        try {
            assert(num > 0 && "Logarithm of a non-positive number.");
            return log10(num);
        } catch (const exception& e) {
            cerr << e.what() << endl;
            return NAN;
        }
    }

    double getResult() const {
        return result;
    }

    void setResult(double value) {
        result = value;
    }

    Calculator* getNext() const {
        return next;
    }

    void setNext(Calculator* nextCalculator) {
        next = nextCalculator;
    }

private:
    double result;
    Calculator* next;
};

int main() {
    Calculator* firstCalculator = nullptr;
    Calculator* currentCalculator = nullptr;

    while (true) {
        if (currentCalculator == nullptr) {
            currentCalculator = new Calculator();
            if (firstCalculator == nullptr) {
                firstCalculator = currentCalculator;
            }
        }

        double num1, num2, result;
        char op;
        bool continueCalculation = true;
        bool usePreviousResult = false; // Track if the previous result should be used

        while (continueCalculation) {
            if (!usePreviousResult) {
                cout << "Enter first number: ";
                cin >> num1;
            } else {
                num1 = currentCalculator->getResult();
                usePreviousResult = false;
            }

            // Initialize num2 with 0 for the first iteration
            num2 = 0;

            while (true) {
                cout << "Enter operator (+, -, *, /, %, s, q, ^, l, g): ";
                cin >> op;

                if (op == 's') {
                    result = currentCalculator->squareRoot(num1);
                } else if (op == 'q') {
                    result = num1 * num1;
                } else if (op == '^') {
                    cout << "Enter second number: ";
                    cin >> num2;
                    result = currentCalculator->performOperation(num1, num2, op);
                } else if (op == 'l') {
                    result = currentCalculator->naturalLog(num1);
                } else if (op == 'g') {
                    result = currentCalculator->base10Log(num1);
                } else if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%') {
                    cout << "Enter second number: ";
                    cin >> num2;
                    result = currentCalculator->performOperation(num1, num2, op);
                } else {
                    cerr << "Error: Invalid operator." << endl;
                    continue;
                }

                if (!isnan(result)) {
                    cout << "Result: " << result << endl;
                    currentCalculator->setResult(result);
                }

                // Ask if the user wants to continue with the previous result as the first number
                char choice;
                cout << "Do you want to continue with the previous result as the first number? (y/n): ";
                cin >> choice;
                if (choice != 'y' && choice != 'Y') {
                    break;
                }

                // Set num1 to the result for the next iteration
                num1 = result;
                usePreviousResult = true; // Indicate that the next iteration should use the previous result
            }

            // Ask if the user wants to continue the current calculation
            char choice;
            cout << "Do you want to continue the current calculation? (y/n): ";
            cin >> choice;
            if (choice != 'y' && choice != 'Y') {
                continueCalculation = false;
            }
        }

        // Ask if the user wants to create a new calculator
        char choice;
        cout << "Do you want to create a new calculator? (y/n): ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            break;
        }

        if (currentCalculator != nullptr) {
            // Link the current calculator to a new one
            Calculator* newCalculator = new Calculator();
            currentCalculator->setNext(newCalculator);
            currentCalculator = newCalculator;
        }
    }

    // Clean up dynamically allocated calculator objects
    currentCalculator = firstCalculator;
    while (currentCalculator != nullptr) {
        Calculator* nextCalculator = currentCalculator->getNext();
        delete currentCalculator;
        currentCalculator = nextCalculator;
    }

    return 0;
}

