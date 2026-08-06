#include <iostream>

using namespace std;

class Number{
private:
    int n;
public:
    Number(int num) : n(num){} //contstructor

    int get_n()
    {
        return n;
    }
};
int main_1()
{

    Number a = 223;
    cout << a.get_n() << endl;

    int x = a.get_n();
    cout <<"x:" << x << endl;

    return 0;
}
