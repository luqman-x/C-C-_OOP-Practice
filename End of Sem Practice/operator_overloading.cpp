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

using namespace std;

int main()
{
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
         float combinedScore = score + other.score;

         if (combinedScore > 100)
         {
            combinedScore = 100;
         }
      }

      bool operator>(const RecoveryScore &other)
      {
         return score > other.score;
      }
   };

   return 0;
}
