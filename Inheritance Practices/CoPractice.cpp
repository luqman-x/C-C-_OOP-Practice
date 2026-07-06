#include <iostream>
using namespace std;

class Results
{
protected:
    int numCourses;
    double scores[100];
    double cwa;

public:
    Results()
    {
        numCourses = 0;
        cwa = 0;
    }

    void takeInput()
    {
        cout << "Enter number of courses: ";
        cin >> numCourses;

        if (numCourses > 100)
            numCourses = 100;

        for (int i = 0; i < numCourses; i++)
        {
            cout << "Enter score for course " << (i + 1) << ": ";
            cin >> scores[i];
        }
    }

    void calculateCWA()
    {
        double total = 0;

        for (int i = 0; i < numCourses; i++)
        {
            total += scores[i];
        }

        if (numCourses > 0)
            cwa = total / numCourses;
        else
            cwa = 0;
    }
};

class Classification : public Results
{
public:
    void displayResult()
    {
        cout << "CWA: " << cwa << endl;

        if (cwa >= 70)
            cout << "Classification: First Class" << endl;
        else if (cwa >= 60)
            cout << "Classification: Second Class Upper" << endl;
        else if (cwa >= 50)
            cout << "Classification: Second Class Lower" << endl;
        else if (cwa >= 40)
            cout << "Classification: Pass" << endl;
        else
            cout << "Classification: Fail" << endl;
    }
};

int main()
{
    Classification student;

    student.takeInput();
    student.calculateCWA();
    student.displayResult();

    return 0;
}
