/*
Write a program that records and analyses a series of body temperature readings taken
from a patient over a monitoring session.

a. The program must first ask the user to enter the number of temperature readings
to be recorded (minimum 3, maximum 10). It should then use a loop to collect
each temperature reading from the user in degrees Celsius and store them all.

b. After all readings have been entered, the program must display the following:
i. The average temperature across all readings.
ii. The highest and lowest temperatures recorded during the session.

c. Finally, the program must loop through all recorded readings and print the
position (e.g., "Reading 2") and value of any individual reading that is 37.6°C or
above, labelling each as "Abnormal reading."
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class TemperatureMonitor
{
private:
    float temp[10];
    int n;

    void GetInput()
    {do
        {
        cout << "Enter number of readings (3 - 10): ";
        cin >> n;

        if (n < 3 || n > 10)
        {
            cout << "Invalid number! "
                 << "n must be between 3 and 10.\n";
        }

    } while (n < 3 || n > 10);

        for (int i = 0; i < n; i++)
        {
            cout << "Enter Reading " << i + 1 << ": ";
            cin >> temp[i];
        }
    }

    void analyse_and_display()
    {
        float sum = 0;
        float highest = temp[0];
        float lowest = temp[0];

        for (int i = 0; i < n; i++)
        {
            sum += temp[i];

            if (temp[i] > highest)
            {
                highest = temp[i];
            }

            if (temp[i] < lowest)
            {
                lowest = temp[i];
            }
        }

        float average = sum / n;
        cout << "\nAverage Temperature: "
             << average << " C" << endl;

        cout << "Highest Temperature: "
             << highest << " C" << endl;

        cout << "Lowest Temperature: "
             << lowest << " C" << endl;
    }

    void abnormalReading()
    {
        cout << "\nAbnormal Readings:\n";

        bool found = false;
        for (int i = 0; i < n; i++)
        {
            if (temp[i] >= 37.6)
            {
                cout << "Reading" << i + 1 << ": " << temp[i] << "C: Abnormal reading" << endl;

                found = true;
            }
        }

        if (found == false)
        {
            cout << "No abnormal readings found." << endl;
        }
    }

public:
    // Constructor:
    TemperatureMonitor()
    {
        n = 0;
        for (int i = 0; i < 10; i++)
    {
        temp[i] = 0;
    }
    }

    void coderunner()
    {
        GetInput();
        analyse_and_display();
        abnormalReading();
    }
};

int main_4()
{
    TemperatureMonitor Patient;
    Patient.coderunner();

    return 0;
}
