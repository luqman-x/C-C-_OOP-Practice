#include <iostream>
using namespace std;

int main()
{
    int bpm[10];
    int min, max, sum = 0;
    float avg;

    cout << "--- Heart Rate Array Analyzer ---" << endl;

    // 1. Input BPM readings
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter BPM reading " << i + 1 << ": ";
        cin >> bpm[i];
    }

    // 2. Find min, max, and sum
    min = bpm[0];
    max = bpm[0];

    for (int i = 0; i < 10; i++)
    {
        sum += bpm[i];

        if (bpm[i] > max)
        {
            max = bpm[i];
        }

        if (bpm[i] < min)
        {
            min = bpm[i];
        }
    }

    // 3. Calculate average and display results
    avg = static_cast<float>(sum) / 10;

    cout << "\n--- Analysis Results ---" << endl;
    cout << "Minimum BPM: " << min << endl;
    cout << "Maximum BPM: " << max << endl;
    cout << "Average BPM: " << avg << endl;

    // 4. Detect Tachycardia and Bradycardia
    cout << "\nTachycardia Readings (>100 BPM):" << endl;
    bool foundTachy = false;

    for (int i = 0; i < 10; i++)
    {
        if (bpm[i] > 100)
        {
            cout << "Reading " << i + 1 << ": " << bpm[i] << " BPM" << endl;
            foundTachy = true;
        }
    }

    if (!foundTachy)
    {
        cout << "None found." << endl;
    }

    cout << "\nBradycardia Warnings (<40 BPM):" << endl;
    bool foundBrady = false;

    for (int i = 0; i < 10; i++)
    {
        if (bpm[i] < 40)
        {
            cout << "Reading " << i + 1 << ": " << bpm[i] << " BPM" << endl;
            foundBrady = true;
        }
    }

    if (!foundBrady)
    {
        cout << "None found." << endl;
    }

    return 0;
}