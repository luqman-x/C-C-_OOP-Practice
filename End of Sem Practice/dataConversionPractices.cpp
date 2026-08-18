#include <iostream>
using namespace std;

class Number
{
private:
    int value;

public:

    Number(int v)
    {
        value = v;
    }

    operator int()
    {
        return value;
    }

    Number operator+(const Number& n)
    {
        return Number(value + n.value);
    }
};

int main()
{
    Number a(10);

    Number b = a + 5;

    int x = b;

    cout << x;
}
