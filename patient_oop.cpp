#include <iostream>
using std::cout;
using std::endl;
using std::string;

class Patient
{
public:
    string Name;
    string Ward;
    int Age;

    void IntroduceYourself()
    {
        cout << " \n*** PATIENT INFO *** " << endl;
        cout << "Name - " << Name << endl;
        cout << "Ward - " << Ward << endl;
        cout << "Age - " << Age << endl;
    }
};

int main()
{
    Patient Patient_1;
    Patient_1.Name = "Lukmanu";
    Patient_1.Ward = "Male-Ward";
    Patient_1.Age = 21;
    Patient_1.IntroduceYourself();

    Patient Patient_2;
    Patient_1.Name = "Rahma";
    Patient_1.Ward = "Female-Ward";
    Patient_1.Age = 20;
    Patient_1.IntroduceYourself();

    return 0;
}