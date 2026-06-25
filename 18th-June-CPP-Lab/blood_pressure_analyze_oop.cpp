#include <iostream>
using std::cin;
using std::cout;
using std::endl;

/*
Question 2
Write a program that assesses a patient's blood pressure based on their systolic and
diastolic readings.
a. The program must prompt the user to enter their systolic and diastolic pressures,
both in mmHg, one after the other. It should then display both readings and their
classification.
b. If the systolic reading is below 90 or the diastolic is below 60, respond with "You
have low blood pressure (Hypotension)."
c. If the systolic is between 90 and 120 and the diastolic is between 60 and 80,
respond with "Your blood pressure is normal."
d. A systolic between 121 and 139 or a diastolic between 81 and 89 should
respond with "You have prehypertension."
e. A systolic between 140 and 179 or a diastolic between 90 and 119 should
respond with "You have high blood pressure (Hypertension)."
f. For a systolic of 180 and above or a diastolic of 120 and above, respond with
"You are in a hypertensive crisis. Seek emergency medical care
immediately."
*/

class PressureCalc
{
private:
    double systolic;
    double diastolic;

    void getinput()
    {
        cout << "Enter systolic pressures: ";
        cin >> systolic;

        cout << "Enter diastolic pressures: ";
        cin >> systolic;
    }

    void DisplayResults()
    {
        if (systolic < 90 || diastolic < 60)
        {
            cout << "You have low blood pressure (Hypotension)." << endl;
        }

        else if ((systolic >= 90 && systolic <= 120) &&
                 (diastolic >= 60 && diastolic <= 80))
        {
            cout << "Your blood pressure is normal." << endl;
        }

        else if ((systolic >= 121 && systolic <= 139) || (diastolic >= 81 && diastolic <= 89))
        {

            cout << "You have prehypertension." << endl;
        }

        else if ((systolic >= 140 && systolic <= 179) || (diastolic >= 90 && diastolic <= 119))
        {

            cout << "You have high blood pressure (Hypertension)." << endl;
        }

        else if (systolic >= 180 || diastolic >= 120)
        {
            cout << "You are in a hypertensive crisis. " << "Seek emergency medical care immediately." << endl;
        }
    }

public:
    PressureCalc()
    {
        systolic = 0;
        diastolic = 0;
    }

    void run()
    {
        getinput();
        DisplayResults();
    }
};

int main_3()
{
    PressureCalc Pressure_1;
    Pressure_1.run();

    return 0;
}
