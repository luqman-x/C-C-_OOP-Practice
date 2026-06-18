#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Calculator
{
private:
    float a;
    float b;
    char op;

    float add() { return a + b; }
    float subtract() { return a - b; }
    float multiply() { return a * b; }
    float divide() { return a / b; }

    void getInput()
    {
        cout << "Enter first number: ";
        cin >> a;
        cout << "Enter the second number: ";
        cin >> b;
        cout << "Enter the operator of choice (+, -, *, /): ";
        cin >> op;
    }

    void compute()
    {
        float result;
        bool valid = true;

        switch (op)
        {
        case '+':
            result = add();
            break;
        case '-':
            result = subtract();
            break;
        case '*':
            result = multiply();
            break;
        case '/':
            if (b == 0)
            {
                cout << "Error: Division by zero!" << endl;
                valid = false;
            }
            else
            {
                result = divide();
            }
            break;
        default:
            cout << "Invalid operator. Please enter one of: +, -, *, /" << endl;
            valid = false;
        }

        if (valid)
            cout << a << " " << op << " " << b << " = " << result << "\n\n";
    }

public:
    Calculator()
    {
        a = 0;
        b = 0;
        op = 0;
    }

    void run()
    {
        cout << "This is a simple calculator. Enter two values and select an operation.\n";
        while (true)
        {
            getInput();
            compute();
        }
    }
};

int main_1()
{
    Calculator calc;
    calc.run();
    return 0;
}
