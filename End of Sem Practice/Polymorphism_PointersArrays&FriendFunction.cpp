/*
Question - Biomedical Signal Processing Workstation

You are developing software for a Biomedical Signal Processing Workstation
that processes raw data from various physiological sensors connected to a patient.

Requirements:

1. BASE & DERIVED CLASSES (POLYMORPHISM)

   Create an abstract base class called Biosensor with private members:

       string sensorID;
       double samplingRate;

   Include the following pure virtual function:

       virtual double processSignal(double rawVoltage) = 0;

   Create two derived classes:

       - ECGSensor (Electrocardiogram)
       - EEGSensor (Electroencephalogram)

   ECGSensor:
       Convert voltage to Heart Rate (BPM) using:

           Heart Rate = rawVoltage * 50.0

   EEGSensor:
       Convert voltage to Brainwave Frequency (Hz) using:

           Brainwave Frequency = (rawVoltage * 12.0) + 0.5

       The +0.5 represents a filtering noise offset.

   Override processSignal() dynamically in both derived classes.


2. FRIEND FUNCTION

   Implement a non-member friend function named:

       calibrateSensor(Biosensor& b, double newRate)

   The friend function must have direct access to the private members
   of the Biosensor class.

   The function should:

       - Update the sensor's samplingRate to newRate.
       - Print a calibration log message showing the sensor ID and
         its new sampling rate.


3. POLYMORPHIC POINTER ARRAY

   In the main() function:

       - Allocate an array of pointers to Biosensor:

           Biosensor* telemetryUnit[3];

       - Dynamically instantiate a mixture of ECGSensor and EEGSensor
         objects into the array.

   Using a single for loop, iterate through the pointer array and:

       1. Call the calibrateSensor() friend function to calibrate
          each sensor to 250.0 Hz.

       2. Polymorphically calculate and display the processed
          physiological measurement using a test input voltage of 1.5 V.

       3. Demonstrate runtime polymorphism by calling processSignal()
          through the Biosensor pointer.

   Finally:

       - Clean up all dynamically allocated memory properly using delete.
       - Exit the program successfully.


Expected calculations for a test voltage of 1.5 V:

   ECG:
       1.5 * 50.0 = 75 BPM

   EEG:
       (1.5 * 12.0) + 0.5 = 18.5 Hz
*/

#include <iostream>
#include <string>
using namespace std;

class Biosensor
{
private:
    string sensorID;
    double samplingRate;

public:
    // Constructor...
    Biosensor(string id, double rate)
        : sensorID(id), samplingRate(rate)
    {
    }

    // Virtual Destructor...
    virtual ~Biosensor() {}

    virtual double processingSignal(double rawVoltage)
    {
        return 0;
    }

    friend void callibrateSensor(Biosensor &b, double newRate)
    {
        b.samplingRate = newRate;

        cout << "Sensor " << b.sensorID << "calibrated to "
             << b.samplingRate << "Hz" << endl;
    }
};

class ECGSensor : public Biosensor
{
public:
    ECGSensor(string id, double rate)
        : Biosensor(id, rate)
    {
    }
    double processingSignal(double rawVoltage) override
    {
        return rawVoltage * 50.0;
    }
};

class EEGSensor : public Biosensor
{
public:
    EEGSensor(string id, double rate)
        : Biosensor(id, rate)
    {
    }
    double processingSignal(double rawVoltage) override
    {
        return (rawVoltage * 12.0) + 0.5;
    }
};
int main_8()
{
    Biosensor *telemetryUnit[3];

    // Dynamically create different sensor objects
    telemetryUnit[0] = new ECGSensor("ECG001", 100.0);
    telemetryUnit[1] = new EEGSensor("EEG001", 150.0);
    telemetryUnit[2] = new ECGSensor("ECG002", 200.0);

    // Test voltage
    double testVoltage = 1.5;

    for (int i = 0; i < 3; i++)
    {
        // Calibrate sensor
        callibrateSensor(*telemetryUnit[i], 250.0);

        double res = telemetryUnit[i]->processingSignal(testVoltage);

        cout << "Processed measurement: " << res;

        // Identify the unit based on sensor type
        if (i == 1)
            cout << "Hz";
        else
            cout << "BPM";

        cout << endl;
    }

    // Clean up dynamically allocated memory
    for (int i = 0; i < 3; i++)
    {
        delete telemetryUnit[i];
    }

    return 0;
}
