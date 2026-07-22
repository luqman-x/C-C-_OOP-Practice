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
