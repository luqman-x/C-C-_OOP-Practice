/*
Question 1 - Pointer to objects
Create a class for patients in a hospital. Include data members for the Patient class: name and
ID numbers.
● Write member functions to store data members and display them.
In main():
1. Create an array of pointers to Patient objects.
2. Using the new operator, let your user fill this array with as many patients as they want.
3. Display the details of all the patients in the array using a for loop
*/

#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Patient
{
private:
    string name;
    int ID;

public:
    void take_inputs()
    {
        cout << "Enter Patient Name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);

        cout << "Enter Patient ID Number:";
        cin >> ID;
    }

    void display_info()
    {
        cout << "Patien Name: " << name << endl;
        cout << "Patient ID: " << ID << endl;
    }
};
int main()
{
    int n;

    cout << "How many patients do you want to enter? ";
    cin >> n;

    // Array of pointers to Patient objects
    Patient **patients = new Patient *[n];

    // Creating objects dynamically
    for (int i = 0; i < n; i++)
    {
        patients[i] = new Patient;
        cout << "\nPatient " << i + 1 << endl;
        patients[i]->take_inputs();
    }

    // Display all patients
    cout << "\nPatient Details\n";

    for (int i = 0; i < n; i++)
    {
        patients[i]->display_info();
        cout << endl;
    }

    // Free memory
    for (int i = 0; i < n; i++)
    {
        delete patients[i];
    }

    delete[] patients;

    return 0;
}