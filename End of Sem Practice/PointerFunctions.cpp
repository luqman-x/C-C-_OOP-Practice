/*
Question 2 - Pointer Functions

Create four functions:
- int add(int a, int b)
- int subtract(int a, int b)
- int multiply(int a, int b)
- int divide(int a, int b) - handle division by zero

Create another function, calculate(), that accepts two integer parameters
and a function pointer and returns an integer.

In main():
1. Declare a function pointer that can point to any of the above functions:
   int(*operation)(int, int);

2. Call the calculate function and display the results.

*/

#include <limits>
#include <iostream>
#include <string>
using namespace std;

// Addition
int add(int a, int b)
{
    return a + b;
}

// Subtraction
int subtract(int a, int b)
{
    return a - b;
}

// Multiplication
int multiply(int a, int b)
{
    return a * b;
}

// Division
int divide(int a, int b)
{
    if (b == 0)
    {
        cout << "Error: Division by zero!" << endl;
        return 0;
    }

    return a / b;
}

int calculate(int a, int b, int (*operation)(int, int))
{
    return operation(a, b);
}

int main_5()
{
    int a = 20;
    int b = 5;

    // Declare function pointer
    int (*operation)(int, int);

    operation = add;
    cout << "Addition: " << calculate(a, b, operation) << endl;

    // Subtraction
    operation = subtract;
    cout << "Subtraction: "
         << calculate(a, b, operation) << endl;

    // Multiplication
    operation = multiply;
    cout << "Multiplication: "
         << calculate(a, b, operation) << endl;

    // Division
    operation = divide;
    cout << "Division: "
         << calculate(a, b, operation) << endl;

    return 0;
}
