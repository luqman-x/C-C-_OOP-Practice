/*
In C++, "function overloading" means declaring multiple functions with the
same name but different parameter lists within the same scope. Conversely,
"class overloading" is a common misnomer; classes themselves cannot be
overloaded in C++, though the term usually refers to either operator
overloading inside a class or class templates that adapt to multiple data
 types.

Function Overloading
Function overloading is a form of compile-time polymorphism. The compiler
automatically determines which function to invoke by evaluating the number,
type, and order of the provided arguments

"Rules for Function Overloading"

1. Must differ by the number of parameters, parameter data types,
or parameter order.

2. Cannot differ by return type alone

3. Ambiguity errors occur if the compiler cannot find a single best match
(e.g., due to overlapping default parameters or ambiguous implicit type conversions)

*/

#include <iostream>
using namespace std;

// Overloading by parameter type
void print(int i)
{
    cout << "Printing int: " << i << endl;
}

void print(double f)
{
    std::cout << "Printing float: " << f << std::endl;
}

// Overloaded by number of parameters
void print(int i, int j)
{
    std::cout << "Printing two ints: " << i << ", " << j << std::endl;
}

int main()
{
    print(5);    // Calls print(int)
    print(5.5);  // Calls print(double)
    print(2, 4); // Calls print(int, int)
    return 0;
}

// Another OOP implementation:

class Box
{
public:
    // Constructor Overloading
    Box() { width = 0; }      // Default constructor
    Box(int w) { width = w; } // Parameterized constructor

    // Member Function Overloading
    void setWidth(int w) { width = w; }
    void setWidth(double w) { width = static_cast<int>(w); }

private:
    int width;
};

// Operator Overloading

/*
This feature allows you to redefine how standard operators (like +, -, ==, or <<)
 interact with your custom class objects.
*/
