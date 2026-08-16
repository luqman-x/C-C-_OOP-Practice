/*
Question 1 - Pointer to objects

Create a class for patients in a hospital. Include data members for the Patient class:
name and ID numbers.

- Write member functions to store data members and display them.

In main():

1. Create an array of pointers to Patient objects.
2. Using the new operator, let your user fill this array with as many patients as they want.
3. Display the details of all the patients in the array using a for loop.
*/

#include <iostream>
#include <string>

using namespace std;

class Patient
{
private:
    string name;
    int id;

public:
    void storeData()
    {
        cout << "Enter patient name: ";
        cin >> name;

        cout << "Enter patient ID: ";
        cin >> id;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
    }
};

int main()
{
    int n;
    cout << "Enter Number of Patients: ";
    cin >> n;

    Patient **patients = new Patient *[n];

    // create and fill data
    for (int i = 0; i < n; i++)
    {
        patients[i] = new Patient;
        cout << "Enter Details for Patient " << i + 1 << endl;
        patients[i]->storeData();
    }

    cout << "\nPatient Details:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Patient " << i + 1 << endl;
        patients[i]->display();
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete patients[i];
    }

    delete[] patients;


    return 0;
}
