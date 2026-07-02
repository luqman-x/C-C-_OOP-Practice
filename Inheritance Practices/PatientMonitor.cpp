#include <iostream>
#include <string>
using namespace std;

class PatientMonitor {
private:
    string PatientID;
    float batteryLife;

public:
    void getdata(){
    cout << "Enter Patient ID: "; cin >> PatientID;
    cout << "Battery Percentage: "; cin >> batteryLife;
}

void putdata(){
    cout << "=== PATIENT INFO ===" << endl;
    cout << "Battery: " << batteryLife << "%" << endl;
    cout << "Patient ID:" << PatientID <<endl;
}

string getPatientID(){
    return PatientID;

}

};

class ECGMonitor: public PatientMonitor{
private:
    int leadCount;

public:
    bool isFullDiagnostic(){
    if(leadCount == 12){
        return true;
    }
    else
        return false;

    }
void getdata(){
    PatientMonitor::getdata();
    cout << "Enter Lead Count value: "; cin >> leadCount;
}

void putdata(){
    PatientMonitor::putdata();
    cout << "Lead Count:" << leadCount <<endl;

}

};

class Spirometer: public PatientMonitor{
private:
    float peakFlowRate;

public:
    bool hashObstraction(){
        if(peakFlowRate < 300){
            return true;
        }
        else
            return false;
    }

    void getdata(){
    PatientMonitor::getdata();
    cout << "Enter Peak FLow Rate value: "; cin >> peakFlowRate;
}

void putdata(){
    PatientMonitor::putdata();
    cout << "Peak Flow Rate:" << peakFlowRate <<endl;
}
};

int main(){
   bool val;
   ECGMonitor monitor_1;
   monitor_1.getdata();
   monitor_1.putdata();

   val = monitor_1.isFullDiagnostic();
   if (val == true){
    cout << "INFO" << endl;
    cout << "Full 12-lead diagnostic available for patient: " << monitor_1.getPatientID() << endl;

   }else
       {
        cout << "NOTE:Patient: " << monitor_1.getPatientID() <<  " is on a limited lead configuration. Consider Upgrading to 12-lead"<< endl;
       }


    Spirometer Spiro_1;
    Spiro_1.getdata();
    Spiro_1.putdata();

    val = Spiro_1.hashObstraction();
    if(val == true){
        cout << "ALERT: Possible airway obstraction detected  for patient: " << Spiro_1.getPatientID() << " Refer to pulmonologist"<< endl;
    }
    else
    {
        cout << "INFO: Patient: " << Spiro_1.getPatientID() << "peak flow within acceptable rage" <<endl;
    }



return 0;

}
