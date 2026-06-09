#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter 1 for Addition:\n2 For Subtraction:\n3 For Multiplication:\n4 For Division:" << endl;
    cin >> num;

    if(num == 1){
        double a, b;
        cout << "Enter the first number:";
        cin >> a;

        cout << "Enter the second number:";
        cin >> b;

        cout << "The Addition of the two numbers" << " is:" << a + b << endl;

    }

    else if (num == 2){
        double a, b;
        cout << "Enter the first number:";
        cin >> a;

        cout << "Enter the second number:";
        cin >> b;

        cout << "The Subtraction of the two numbers" << " is:" << a - b << endl;

    }

    else if (num == 3){
        double a, b;
        cout << "Enter the first number:";
        cin >> a;

        cout << "Enter the second number:";
        cin >> b;

        cout << "The Multiplication of the two numbers" << " is:" << a * b << endl;

    }

    else if (num == 4){
        double a, b;
        cout << "Enter the first number:";
        cin >> a;

        cout << "Enter the second number:";
        cin >> b;

        cout << "The Division of the two numbers" << " is:" << a / b << endl;

    }

    return 0;
}
