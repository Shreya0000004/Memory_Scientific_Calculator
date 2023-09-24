#ifndef SCIENTIFIC_CALCULATOR_MEMORY_H
#define SCIENTIFIC_CALCULATOR_MEMORY_H

#include <iostream>

class Calculator {
public:
    Calculator();
    double performOperation(double num1, double num2, char op);
    double squareRoot(double num);
    double naturalLog(double num);
    double base10Log(double num);
    double getResult() const;
    void setResult(double value);
    Calculator* getNext() const;
    void setNext(Calculator* nextCalculator);

private:
    double result;
    Calculator* next;
};

#endif // SCIENTIFIC_CALCULATOR_MEMORY_H

