#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));

    int SecretNumber = rand() % 100 +1;
    int guess;
    int attempts = 0;


    cout << "*** NUMBER GUESSING GAME ****" << endl;
    cout << "I have chosen a number between 1 and 100." << endl;
    cout << "Can you guess it?" << endl;

    do {
        cout <<  "\nEnter your guess: ";
        cin >> guess;


        attempts++;

        if (guess > SecretNumber){
            cout << "Too high! Try Again" << endl;

        }

        else if (guess < SecretNumber)
        {
            cout << "Too low! Try again." << endl;
        }
        else
        {
            cout << "Congratulations!" << endl;
            cout << "You guessed the number in "
                 << attempts
                 << " attempts." << endl;
        }
    }  while (guess != SecretNumber);

    return 0;
}

