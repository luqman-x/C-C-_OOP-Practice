/*
                 MedicalDevice
                ----------------
                deviceID
                firmwareVersion
                selfTest()
                       ▲
                       │  Inheritance
                       │
                InfusionPump
                ----------------
                flowRate
                patient*
                assignPatient()
                administer()

          Association (1:1)
                 │
                 │
                 ▼
          PatientProfile
          ----------------
          patientID
          bedNumber

HospitalWard
------------------------
wardName
activePatients*
        ◇──────────────► PatientProfile
         Aggregation (1:*)

InfusionPump
------------- - - - - -► Drug
      Dependency


| Relationship | Classes Involved | Type | Real-World Justification |
| --- | --- | --- | --- |
| 1 | MedicalDevice ↔ InfusionPump | Inheritance | Pump is a specialized medical device |
| 2 | InfusionPump ↔ Drug | Dependency | Pump administers drugs temporarily |
| 3 | InfusionPump ↔ PatientProfile | Association (1–1) | Each pump serves one patient |
| 4 | HospitalWard ↔ PatientProfile | Aggregation (1–*) | Ward contains multiple patients |


## Summary of the relationships
| Relationship    | Meaning in this program                                    | Why it fits                                                                                         |
| --------------- | ---------------------------------------------------------- | --------------------------------------------------------------------------------------------------- |
| **Inheritance** | `InfusionPump` inherits from `MedicalDevice`               | An infusion pump **is a** medical device and reuses common attributes and behavior.                 |
| **Association** | `InfusionPump` points to a `PatientProfile`                | The pump is assigned to a patient, but neither object owns the other; both can exist independently. |
| **Aggregation** | `HospitalWard` stores pointers to `PatientProfile` objects | A ward groups patients, but patients can exist and move to other wards independently.               |
| **Dependency**  | `InfusionPump::administer(Drug d)` uses a `Drug` parameter | The pump only needs the drug while administering it and does not retain ownership afterward.        |

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MedicalDevice
{
private:
    string deviceID;
    string firmwareVersion;

public:
    MedicalDevice(string id, string fmw)
    {
        deviceID = id;
        firmwareVersion = fmw;
    }

    virtual bool selfTest()
    {
        cout << "Medical Device self-test successful..." << endl;
        return true;
    }

    virtual ~MedicalDevice() {}
};

class Drug
{
private:
    string drugName;
    double concentration;

public:
    Drug(string name, double conc)
    {
        drugName = name;
        concentration = conc;
    }

    string getDrugName() const
    {
        return drugName;
    }

    double getConcentration() const
    {
        return concentration;
    }
};

class PatientProfile
{
private:
    string patientID;
    int bedNumber;

public:
    PatientProfile(string id, int num)
    {
        patientID = id;
        bedNumber = num;
    }

    string getPatientID() const
    {
        return patientID;
    }

    int getBedNumber() const
    {
        return bedNumber;
    }
};

class InfusionPump : public MedicalDevice
{
private:
    double flowRate;
    PatientProfile *patient;

public:
    InfusionPump(string id, string fmw, double rate)
        : MedicalDevice(id, fmw), flowRate(rate), patient(nullptr)
    {
    }

    bool selfTest() override
    {
        cout << "Infusion Pump Self-Test Successful." << endl;
        return true;
    }

    void assignPatient(PatientProfile *p)
    {
        patient = p;
    }

    void administer(Drug d)
    {
        if (patient != nullptr)
        {
            cout << "Patient ID: "
                 << patient->getPatientID() << endl;

            cout << "Bed Number : "
                 << patient->getBedNumber() << endl;
        }
        else
        {
            cout << "No patient assigned." << endl;
        }

        cout << "Drug Name : "
             << d.getDrugName() << endl;

        cout << "Concentration : "
             << d.getConcentration()
             << " mg/mL" << endl;

        cout << "Flow Rate : "
             << flowRate
             << " mL/hr" << endl;
    }
};

class HospitalWard
{
private:
    string wardName;
    vector<PatientProfile *> activePatients;

public:
    HospitalWard(string name)
    {
        wardName = name;
    }

    void addPatient(PatientProfile *p)
    {
        activePatients.push_back(p);
    }

    void displayPatients()
    {
        cout << "\n== " << wardName << " ==" << endl;

        for (PatientProfile *p : activePatients)
        {
            cout << "Patient ID : "
                 << p->getPatientID()
                 << "\tBed : "
                 << p->getBedNumber()
                 << endl;
        }
    }
};

int main_7()
{
    Drug insulin("Insulin", 0.75);
    PatientProfile patient1("PAT1001", 12);
    HospitalWard ward("ICU");

    ward.addPatient(&patient1);

    InfusionPump pump("IP001", "V2.1", 12.5);
    pump.assignPatient(&patient1);
    pump.selfTest();
    pump.administer(insulin);
    ward.displayPatients();

    return 0;
}
