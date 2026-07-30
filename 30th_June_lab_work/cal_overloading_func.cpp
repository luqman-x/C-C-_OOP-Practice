#include <iostream>
#include <math.h>
#include <string>

using namespace std;

class Calculator
{
public:
    void add(int a, int b)
    {
        //

        cout << a + b << endl;
    }

    void add(int a, int b, int c)
    {
        //
        cout << a + b + c << endl;
    }

    // converting int to stringm use strinf res = to_string(x) + to_string(y);
    //  if string to int, use int num = stoi(str)
    // nt a = stoi(str);
    // out << a + b << endl;

    void add(string s1, int a)
    {
        cout << s1 + to_string(a) << endl;
    }

    void add(float a, float b)
    {
        //
        cout << a + b << endl;
    }

    void add(string s1, string s2)
    {
        cout << s1 + s2 << endl;
    }
};
int main()
{
    Calculator cal;
    cal.add(1, 2);
    cal.add(2, 3, 4);
    cal.add("12", 2);
    cal.add("Hello", "Ama");

    return 0;
}
