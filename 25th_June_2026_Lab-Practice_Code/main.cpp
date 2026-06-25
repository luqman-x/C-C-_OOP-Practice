#include <iostream>
#include <string>

using namespace std;

class SmartInfusionPump
{
private:
    string DrugName;
    float FlowRate;
    float VolumeRemaining;
    int BatteryLevel;
    bool IsRunning;

public:
    // Default constructor
    SmartInfusionPump()
    {
        DrugName = "";
        FlowRate = 0;
        VolumeRemaining = 0;
        BatteryLevel = 0;
        IsRunning = false;
    }

    void TakeInputs()
    {
        cout << "Enter Drug Name: ";
        cin.ignore();
        getline(cin, DrugName);

        do
        {
            cout << "Enter Flow Rate: ";
            cin >> FlowRate;
        } while (FlowRate < 0);

        do
        {
            cout << "Enter Drug Volume: ";
            cin >> VolumeRemaining;
        } while (VolumeRemaining < 0);

        do
        {
            cout << "Enter Battery Level (0-100): ";
            cin >> BatteryLevel;
        } while (BatteryLevel < 0 || BatteryLevel > 100);
    }

    void StartPump()
    {
        if (BatteryLevel >= 20 && VolumeRemaining > 0)
        {
            IsRunning = true;
            cout << "\nPump Started Successfully\n";
        }
        else
        {
            cout << "\nBattery too low or medication empty.\n";
        }
    }

    void StopPump()
    {
        IsRunning = false;
        cout << "Pump Stopped\n";
    }

    void DisplayStatus() const
    {
        cout << "\n===== PUMP STATUS =====\n";
        cout << "Drug Name: " << DrugName << endl;
        cout << "Flow Rate: " << FlowRate << endl;
        cout << "Volume Remaining: " << VolumeRemaining << endl;
        cout << "Battery Level: " << BatteryLevel << "%" << endl;
        cout << "Pump Status: ";

        if (IsRunning)
            cout << "Running\n";
        else
            cout << "Stopped\n";
    }

    void Run()
    {
        TakeInputs();
        StartPump();
        DisplayStatus();
    }
};

int main_2()
{
    SmartInfusionPump SIP;
    SIP.Run();

    return 0;
}
