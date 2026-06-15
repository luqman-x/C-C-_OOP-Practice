#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    string Name;
    int Age;
    double Score;

public:
    // Setter of Secret Variables
    void SetName(string name)
    {
        Name = name;
    }

    void SetAge(int age)
    {
        if (age >= 16)
        {
            Age = age;
        }
        else
        {
            cout << "Invalid age. Age must be at least 16." << endl;
        }
    }

    void SetScore(double score)
    {
        if (score >= 0 && score <= 100)
        {
            Score = score;
        }
        else
        {
            cout << "Invalid Score. Score must be between 0 and 100." << endl;
        }
    }

    // Getter of Secret Variables
    string GetName()
    {
        return Name;
    }

    int GetAge()
    {
        return Age;
    }

    double GetScore()
    {
        return Score;
    }

    char getGrade()
    {
        if (Score >= 80)
        {
            return 'A';
        }
        else if (Score >= 70)
        {
            return 'B';
        }
        else if (Score >= 60)
        {
            return 'C';
        }
        else if (Score >= 50)
        {
            return 'D';
        }
        else
        {
            return 'F';
        }
    }

    void displayInfo()
    {
        cout << "Name: " << Name << endl;
        cout << "Age: " << Age << endl;
        cout << "Score: " << Score << endl;
        cout << "Grade: " << getGrade() << endl;
    }

    Student(string name, int age, double score)
    {
        SetAge(age);
        SetName(name);
        SetScore(score);
    }
};

int main()
{

    Student s1("Ali", 20, 87.5);

    s1.displayInfo();

    cout << endl;

    s1.SetAge(15);
    s1.SetScore(120);

    cout << endl;

    s1.SetAge(21);
    s1.SetScore(95);

    s1.displayInfo();
    return 0;
}