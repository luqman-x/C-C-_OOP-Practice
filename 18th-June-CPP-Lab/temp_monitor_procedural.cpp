#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter the number of temperature readings (3 - 10): ";
    cin >> n;

    while (n < 3 || n > 10)
    {
        cout << "Invalid input. Enter a number between 3 and 10: ";
        cin >> n;
    }

    float temp[10];
    float sum = 0;

    cout << "\nEnter the temperature readings:\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Reading " << i + 1 << ": ";
        cin >> temp[i];

        sum += temp[i];
    }

    float average = sum / n;

    float highest = temp[0];
    float lowest = temp[0];

    for (int i = 1; i < n; i++)
    {
        if (temp[i] > highest)
        {
            highest = temp[i];
        }

        if (temp[i] < lowest)
        {
            lowest = temp[i];
        }
    }

    cout << "Average Temperature: "
         << average
         << " C" << endl;

    cout << "Highest Temperature: "
         << highest
         << " C" << endl;

    cout << "Lowest Temperature: "
         << lowest
         << " C" << endl;

    cout << "\nAbnormal Readings:\n";

    for (int i = 0; i < n; i++)
    {
        if (temp[i] >= 37.6)
        {
            cout << "Reading "
                 << i + 1
                 << ": "
                 << temp[i]
                 << " C"
                 << " - Abnormal reading."
                 << endl;
        }
    }

    return 0;

}
