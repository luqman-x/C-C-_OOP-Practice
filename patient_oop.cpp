#include <iostream>
using std::cout;
using std::endl;
using std::string;

// Abstraction
class AbstractPatient
{
    virtual void AskForDischarge() = 0;
};
class Patient : AbstractPatient
{
private:
    string Name;
    string Ward;
    int Age;

public:
    // Setter
    void SetName(string name)
    {
        Name = name;
    }
    // Getter
    string GetName()
    {
        return Name;
    }

    void SetWard(string ward)
    {
        Ward = ward;
    }
    string GetWard()
    {
        return Ward;
    }

    void SetAge(int age)
    {
        if (age >= 18)
            Age = age;
    }
    int GetAge()
    {
        return Age;
    }

        void IntroduceYourself()
    {
        cout << " \n*** PATIENT INFO *** " << endl;
        cout << "Name - " << Name << endl;
        cout << "Ward - " << Ward << endl;
        cout << "Age - " << Age << endl;
    }

    // Abstraction function Implementation

    void AskForDischarge()
    {
        if (Age > 30)
            cout << "\n"
                 << Name << " got discharged 🥳 " << "\n"
                 << endl;
        else
            cout << "\n"
                 << Name << " sorry, can't discharge you 🥲 " << "\n"
                 << endl;
    }
    /*
    Constructor:
    Constructor must be Publice
    Same name as class
    Does not Return
    */

    Patient(string name, string ward, int age)
    {
        Name = name;
        Ward = ward;
        Age = age;
    }
};

int main()
{
    Patient Patient_1 = Patient("Lukmanu", "Male-Ward", 25);
    Patient_1.IntroduceYourself();

    Patient Patient_2 = Patient("Rahma", "Female-Ward", 18);
    Patient_2.IntroduceYourself();

    Patient_1.SetAge(45);
    cout << Patient_1.GetName() << " is " << Patient_1.GetAge() << " years old" << endl;

    Patient_1.AskForDischarge();
    Patient_2.AskForDischarge();

    return 0;
}