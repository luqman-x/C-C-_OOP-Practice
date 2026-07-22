#include <iostream>
#include <math.h>
/*
Exercise
A hospital system stores patient data across two separate classes: BloodPressure,
which holds systolic and diastolic readings (both int), and HeartRate, which holds a bpm reading (int).

Write the two classes with the following:

- Appropriate constructors to initialise the private members.
- A friend function isHealthy(BloodPressure, HeartRate)
  that returns true if the systolic reading is below 120, diastolic is below 80,
  and heart rate is between 60 and 100 bpm, and false otherwise.

Write a main() that creates a BloodPressure object and a HeartRate object, calls isHealthy(),
and prints either “Patient vitals are normal.” or “ALERT: Abnormal vitals detected.” based on the result.
*/

using namespace std;
class HeartRate; // Forward decleration

class BloodPressure
{
private:
    int systolic, diastolic;

public:
    BloodPressure(int s, int d)
    {
        systolic = s;
        diastolic = d;
    }

    friend bool isHealthy(BloodPressure bp, HeartRate hr);
};

class HeartRate
{
private:
    int bpm;

public:
    HeartRate(int BPM)
    {
        bpm = BPM;
    }

    friend bool isHealthy(BloodPressure bp, HeartRate hr);
};

bool isHealthy(BloodPressure bp, HeartRate hr)
{
    return (
        bp.systolic < 120 &&
        bp.diastolic < 80 &&
        hr.bpm >= 60 &&
        hr.bpm <= 100);
}

int main()
{
    int sys, dia, bpm;

    // Get input from user
    cout << "Enter systolic pressure: ";
    cin >> sys;

    cout << "Enter diastolic pressure: ";
    cin >> dia;

    cout << "Enter heart rate (bpm): ";
    cin >> bpm;

    // Create objects
    BloodPressure bp(sys, dia);
    HeartRate hr(bpm);

    // Check health status
    if (isHealthy(bp, hr))
    {
        cout << "\nPatient vitals are normal." << endl;
    }
    else
    {
        cout << "\nALERT: Abnormal vitals detected." << endl;
    }
    return 0;
}