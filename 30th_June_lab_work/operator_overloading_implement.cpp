#include <iostream>

using namespace std;

class Number
{
public:
    int n;
    Number(int num) : n(num) {}

    Number operator+(Number &numA)
    {
        return Number(n + numA.n);
    }

    // subtraction operator so 'b - a'
    Number operator-(const Number &numA) const
    {
        return Number(n - numA.n);
    }

    Number operator*(const Number &numA)
    {
        return Number(n * numA.n);
    }

    Number operator/(const Number &numA)
    {
        return Number(n / numA.n);
    }
};

int main()
{
    Number a(5);
    Number b(10);

    Number c = b - a;
    Number m = b * a;
    Number d = b / a;

    cout << c.n << endl;
    cout << m.n << endl;
    cout << d.n << endl;
}

// Do for ++ and more about prefix and postfix