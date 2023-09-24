#include <iostream>
#include "scientific_calculator_memory.h"

using namespace std;

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
        bool usePreviousResult = false;

        while (continueCalculation) {
            if (!usePreviousResult) {
                cout << "Enter first number: ";
                cin >> num1;
            } else {
                num1 = currentCalculator->getResult();
                usePreviousResult = false;
            }

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

                char choice;
                cout << "Do you want to continue with the previous result as the first number? (y/n): ";
                cin >> choice;
                if (choice != 'y' && choice != 'Y') {
                    break;
                }

                num1 = result;
                usePreviousResult = true;
            }

            char choice;
            cout << "Do you want to continue the current calculation? (y/n): ";
            cin >> choice;
            if (choice != 'y' && choice != 'Y') {
                continueCalculation = false;
            }
        }

        char choice;
        cout << "Do you want to create a new calculator? (y/n): ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            break;
        }

        if (currentCalculator != nullptr) {
            Calculator* newCalculator = new Calculator();
            currentCalculator->setNext(newCalculator);
            currentCalculator = newCalculator;
        }
    }

    currentCalculator = firstCalculator;
    while (currentCalculator != nullptr) {
        Calculator* nextCalculator = currentCalculator->getNext();
        delete currentCalculator;
        currentCalculator = nextCalculator;
    }

    return 0;
}

