#include <iostream>
using std::cin;
using std::cout;
using std::endl;


/*
Question 1
Build a body mass index calculator.
a. The program must ask for a person’s height in centimeters and weight in
kilograms, one after the other. It should then display the BMI in kg/m2.
b. If the BMI is less than 18.5, the program should also respond with “You are
underweight.”
c. If BMI falls within the range 18.5-24.9, the program should respond with “Your
weight is normal.”
d. Between 25 and 29.9, it should respond with “You are overweight.”
e. Between 30 and 39.9, the expected response should be “You are obese.”
f. For a BMI of 40 and above, the program’s response should be “You are
morbidly obese.

 */

class bmi_analyst{

private:
    double Height;
    double Weight;
    double BMI;



    void getinput(){
        cout << "Enter your height (cm): ";
        cin >> Height;

        cout << "Enter your weight (Kg): ";
        cin >> Weight;

    }

    void CalculateBMI(){
        float heightM = Height / 100;
        BMI = Weight/ (heightM*heightM);
    }

    void displayResults(){
        cout << "Your BMI is "<< BMI << " kg/m^2" << endl;

        if (BMI < 18.5){
            cout << " You are underweight " << endl;
        }
        else if ( BMI >= 18.5 && BMI <= 24.9){
            cout << "Your weight is normal" << endl;

        }
        else if (BMI >= 25 && BMI <= 29.9 ) {
            cout << " You are overweight. " << endl;

        } else if (BMI >= 30 &&  BMI<= 39.9)

        {
            cout << "You are obese." << endl;
        }

        else
        {
            cout << "You are morbidly obese." << endl;
        }
    }
public:
    bmi_analyst(){
       Height = 0;
       Weight = 0;
       BMI = 0;
    }

    void runcode(){

        getinput();
        CalculateBMI();
        displayResults();
    }

 };
int main_2(){

    bmi_analyst person;
    person.runcode();
    return 0;

}
