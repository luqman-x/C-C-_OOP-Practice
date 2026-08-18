// conversions: Distance to meters, meters to Distance

#include <iostream>
#include <string>
using namespace std;

class Distance
{
private:
    const float MTF;
    int feet;
    float inches;

public:
    // Constructor
    Distance() : feet(0), inches(0.0), MTF(3.280833) {}
    Distance(float meters) : MTF(3.280833)
    {
        float fltfeet = MTF * meters; // convert to float feet
        feet = int(fltfeet);          // feet is integer part

        inches = 12 * (fltfeet - feet); // inches is what’s left
    }

    Distance(int ft, float in) : feet(ft), inches(in), MTF(3.280833) {}
    void showdist() const
    {
        cout << feet << "\'-" << inches << "\"";
    }

    operator float() // conversion operator
    {
        float fracfeet = inches / 12;
        fracfeet += static_cast<float>(feet);
        return fracfeet / MTF;
    }
};
int main_9()
{
    Distance dist1 = 2.35;
    cout << "\ndist1 = ";
    dist1.showdist();

    float mtrs = static_cast<float>(dist1); // uses conversion operator
    cout << "\ndist1 = " << mtrs << " meters\n";

    Distance dist2(5, 10.25); // uses 2-arg constructor
    mtrs = dist2;             // also uses conversion op
    cout << "\ndist2 = " << mtrs << " meters\n";

    return 0;
}
