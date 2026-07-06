#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Person
{
private:
    string name;
    int age;

public:
    Person()
    {
        name = "";
        age = 0;
    }

    ~Person()
    {
    }

    void SetName(string Name)
    {
        name = Name;
    }

    string GetName()
    {
        return name;
    }

    void SetAge(int Age)
    {
        // condition should be in setters
        age = Age;
    }

    int GetAge()
    {
        return age;
    }

    void displayInfo(){
        cout << "Name:" << name << endl;
        cout << "Age:" << age<< endl;
    }
};

class Student : public Person
{
    private:
    string STudentID;
    double score;

    public:
    Student()
    {
        STudentID = "";
        score = 0.0;
    }

    void takeinput(){
        // read student details: name, age, ID and score
        string name;
        int age;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Student ID: ";
        cin >> STudentID;
        cout << "Enter Score: ";
        cin >> score;
        
        SetName(name);
        SetAge(age);
    }

    void GetGrade(){
        // determine and display grade based on score
        string grade;
        if(score >= 90 && score <= 100) grade = "A";
        else if(score >= 80) grade = "B";
        else if(score >= 70) grade = "C";
        else if(score >= 60) grade = "D";
        else if(score >= 0) grade = "F";
        else grade = "Invalid";

        // display student info and grade
        displayInfo();
        cout << "StudentID: " << STudentID << endl;
        cout << "Score: " << score << endl;
        cout << "Grade: " << grade << endl;
    }


};

int main()
{
    Student student;
    student.takeinput();
    student.GetGrade();

    return 0;
}