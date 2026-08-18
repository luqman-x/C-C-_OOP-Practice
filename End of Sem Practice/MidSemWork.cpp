/*
MedicalSensor
-------------------
- sensorID : string
- unit : string
- reading : double

+ getReading() : double
+ calibrate() : void
        ▲
        │
        │ Inheritance
        │
PulseOximeter
-------------------
- spO2Level : int

+ checkHypoxia() : bool

*/


/*
Question 1

Using the UML diagram above, write the two classes in C++, expressing
the relationship shown.

The functions perform the following tasks:

a. The getReading() function returns the current sensor reading to the caller.

b. The calibrate() function resets the sensor reading to 0.0 and prints
   "Sensor [sensorID] calibrated" to the console.

c. The checkHypoxia() function returns true if spO2Level is below 90
   and false otherwise.


Question 2

a. Identify and name the relationship shown in the UML diagram.

b. Explain why the attributes of MedicalSensor are marked as private (-).
   What OOP principle does this demonstrate?


Question 3

Write a main() function that does the following:

a. Create a PulseOximeter object with:
   sensorID = "PO-201"
   unit = "%SpO2"
   reading = 88.5
   spO2Level = 88

b. Call checkHypoxia() on the PulseOximeter object.
   If it returns true, print:
   "ALERT: Check patient immediately!"
*/

#include <iostream>
#include <string>

using namespace std;


class MedicalSensor
{
private:
    string sensorID;
    string unit;
    double reading;

public:

    // Constructor
    MedicalSensor(string id, string u, double r)
    {
        sensorID = id;
        unit = u;
        reading = r;
    }


    double getReading()
    {
        return reading;
    }

    // Resets reading to 0.0 and displays calibration message
    void calibrate()
    {
        reading = 0.0;

        cout << "Sensor "
             << sensorID
             << " calibrated"
             << endl;
    }
};


class PulseOximeter : public MedicalSensor
{
private:
    int spO2Level;

public:

    // Constructor
    PulseOximeter(string id, string u, double r, int spO2)
        : MedicalSensor(id, u, r)
    {
        spO2Level = spO2;
    }

    // Checks whether oxygen saturation is below 90%
    bool checkHypoxia()
    {
        if (spO2Level < 90)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
