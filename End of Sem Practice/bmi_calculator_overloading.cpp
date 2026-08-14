/*
        Function Overloading

A diagnostic lab system needs to calculate the Body Mass Index (BMI) of patients.
Patient data may be recorded in different units: kilograms/metres or pounds/inches.

Write a class BMICalculator with an overloaded function calculate() that handles
both cases:

1. calculate(float weightKg, float heightM)
   - Uses the metric formula:
     BMI = weight / (height * height)

2. calculate(float weightLbs, float heightInches, string unit)
   - Use "imperial" as the third argument to distinguish it from the metric version.
   - Uses the imperial formula:
     BMI = (weight / (height * height)) * 703

Each version should print the BMI value and its classification:

- Below 18.5       -> "Underweight"
- 18.5 to 24.9     -> "Normal"
- 25.0 to 29.9     -> "Overweight"
- 30.0 and above   -> "Obese"

Write a main() function that tests both overloaded functions with different
patient data.
*/

#include <iostream>
#include <string>

using namespace std;

class bmi_calculator
{
private:
    // Classify BMI:
    void printClassification(float bmi)
    {
        if (bmi < 18.5)
        {
            cout << "Classification: Underweight" << endl;
        }
        if (bmi <= 29.9)
        {
            cout << "Classification: Overweight" << endl;
        }
        else
        {
            cout << "Classification: Obese" << endl;
        }
    }

public:
    void calculate(float weightKg, float heightM)
    {
        float bmi = weightKg / (heightM * heightM);

        cout << "BMI(Metric): " << bmi << endl;

        printClassification(bmi);
    }

    // Imperial Version:
    void calculate(float weightLbs, float heightInches, string unit)
    {
        if (unit == "imperial")
        {
            float bmi = (weightLbs / (heightInches * heightInches)) * 703;

            cout << "BMI (Imperial): " << bmi << endl;
            printClassification(bmi);
        }
        else
        {
            cout << "Invalid unit!" << endl;
        }
    }
};

int main()
{

    bmi_calculator patient;

    // Patient 1: Metric:
    cout << "Patient 1" << endl;
    patient.calculate(50.0f, 1.70f);

    // Patient 2: Metric
    cout << "Patient 2" << endl;
    patient.calculate(50.0f, 1.70f);

    // Patient 3: Imperial
    cout << "Patient 3" << endl;
    patient.calculate(180.0f, 70.0f, "imperial");

    // Patient 4: Imperial
    cout << "Patient 4" << endl;
    patient.calculate(220.0f, 68.0f, "imperial");

    return 0;
}
