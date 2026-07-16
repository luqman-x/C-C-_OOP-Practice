/*
Question 2 - Pointer Functions
Create four functions:
● int add(int a, int b)
● int subtract(int a, int b)
● int multiply(int a, int b)
● int divide(int a, int b) - handle division by zero
Create another function, calculate(), that accepts two integer parameters and a function pointer
and returns an integer.
In main():
1. Declare a function pointer that can point to any of the above functions:
○ int(*operation)(int, int);
2. Call the calculate function and display the results.
*/

#include <iostream>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    if (b == 0)
    {
        cout << "Error: Division by zero!" << endl;
        return 0;
    }

    return a / b;
}

// Function that accepts a function pointer
int calculate(int a, int b, int (*operation)(int, int))
{
    return operation(a, b);
}

int main()
{
    int x, y;

    cout << "Enter first number: ";
    cin >> x;

    cout << "Enter second number: ";
    cin >> y;

    // Function pointer
    int (*operation)(int, int);
    /*
    This means:
    operation is a pointer
    It points to a function
    The function takes two int parameters
    The function returns an int
     */

    operation = add;
    /*
    Now operation points to add() function.
    when calculate(x, y, operation); is called,
    the calculate() function receives that pointer and executes it:
    return operation(a, b); which is equivalent to: return add(a, b);
    */
    cout << "Addition: " << calculate(x, y, operation) << endl;

    operation = subtract;
    cout << "Subtraction: " << calculate(x, y, operation) << endl;

    operation = multiply;
    cout << "Multiplication: " << calculate(x, y, operation) << endl;

    operation = divide;
    cout << "Division: " << calculate(x, y, operation) << endl;

    return 0;
}