#include <iostream>
using namespace std;

class Counter
{
private:
    int value;

public:
    // constructor
    Counter(int v = 0) : value(v) {}

    // 1. PREFIX INCREAMENT (++obj)

    Counter &operator++()
    {
        ++value;      // Increment internal value
        return *this; // Return current object
    }

    // 2. POSTFIX INCREMENT (obj++)
    // Uses a dummy 'int' parameter to signal postfix to the compiler
    Counter operator++(int)
    {

        Counter temp = *this; // Save the original state
        ++value;              // Increment internal value
        return temp;          // Return the old state by value
    }

    // PREFIX DECREAMENT(++obj)
    Counter &operator--()
    {
        --value;
        return *this;
    }

    // POSTFIX DECREAMENT (obj--)
    Counter operator--(int)
    {
        Counter temp = *this;
        --value;
        return temp;
    }

    friend ostream &operator<<(ostream &out, const Counter &other)
    {
        out << other.value;
        return out;
    }

    friend istream &operator>>(istream &in, Counter &other)
    {
        in >> other.value;
        return in;
    }
};
int main()
{

    Counter c1(10);

    // Testing << and >>
    cout << "Initial c1: " << c1 << std::endl;

    cout << "\nEnter a new value for c1: ";
    cin >> c1;
    cout << "New c1 value: " << c1 << std::endl;

    // Testing Increment / Decrement
    cout << "\nTesting Modifiers on c1 (" << c1 << "):" << std::endl;
    cout << "Prefix (++c1):  " << ++c1 << " (Value updates instantly)" << std::endl;
    cout << "Postfix (c1++): " << c1++ << " (Returns old value first)" << std::endl;
    cout << "After Postfix:  " << c1 << " (Value is now updated)" << std::endl;

    return 0;
}
