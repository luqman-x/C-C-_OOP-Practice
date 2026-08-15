/*
          Overloading

A physiotherapy clinic tracks patient recovery progress using a RecoveryScore
class that stores:
- patientID (string)
- score (float, out of 100)

Write the RecoveryScore class with the following overloaded operators:

1. +
   - Adds the scores of two RecoveryScore objects.
   - Returns a new RecoveryScore.
   - Set the new patientID to "Combined".
   - Clamp the combined score to a maximum of 100.

2. >
   - Returns true if the left object's score is greater than the right object's
     score.

3. <<
   - Prints the patient ID and score in this format:
     "Patient: [patientID] | Score: [score]/100"

Write a main() function that:
- Creates two RecoveryScore objects.
- Uses << to print both objects.
- Uses > to determine and print which patient has the higher recovery score.
- Uses + to combine the two scores.
- Prints the combined result using <<.
*/

#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

class RecoveryScore
{
private:
   string patientID;
   float score;

public:
   // Constructor
   RecoveryScore(string id, float s)
   {
      patientID = id;
      score = s;
   }

   /*
   return_type operator symbol(parameter_list){
               custom implementation logic
   }
   */
   RecoveryScore operator+(const RecoveryScore &other)
   {
      return RecoveryScore("Combined", std::min(score + other.score, 100.0f));
   }

   bool operator>(const RecoveryScore &other)
   {
      return score > other.score;
   }

   /*
   ****Friend function decleration:
   friedn return_type functionname(ClassName &object)

   ****FRIEND FUNCTION DEFINITION (Outside the class scope)
   return_type functionName(ClassName &object)
   {
         // Can directly access private data using the object reference
   }
   */

   // Overload << operator
   friend ostream &operator<<(ostream &out, const RecoveryScore &patient)
   {
      out << "Patient: " << patient.patientID
          << " | Score: " << patient.score << "/100";

      return out;
   }
};

int main_2()
{

   RecoveryScore patient1("PT001", 75.5);
   RecoveryScore patient2("PT002", 82.0);

   // print both patients using <<
   cout << patient1 << endl;
   cout << patient2 << endl;

   cout << endl;

   // Compare the two patients using >
   if (patient1 > patient2)
   {
      cout << "Patient PT002 has the higher recovery score." << endl;
   }

   else if (patient2 > patient1)
   {
      cout << "Both patients have the higher recovery score" << endl;
   }
   else
   {
      cout << "Both patients have the same recovery score." << endl;
   }
   cout << endl;

   RecoveryScore combined = patient1 + patient2;

   cout << combined << endl;

   return 0;
}
