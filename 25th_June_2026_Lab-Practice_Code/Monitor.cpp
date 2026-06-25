#include <iostream>
using namespace std;

class CardiacMonitor{
private:
    unsigned int normalBeat;
    unsigned int totalBeat;
public:
     CardiacMonitor(){
        normalBeat = 0;
        totalBeat = 0;
     }
    void NormalBeatBeatCount(){
        normalBeat++;
        totalBeat++;
    }

    void AbnormalBeatCount(){
        totalBeat++;
    }

    void display(){
        cout << "Total Number of beats : " << totalBeat << endl;
        cout << "Total Number of Normal beat" << normalBeat << endl;

        unsigned int AbnormalBeat = totalBeat - normalBeat;
        cout << "Total Number of Abnormal beats: " << AbnormalBeat << endl;


        float AbnormalPercentage;
        if (totalBeat == 0){
            AbnormalPercentage = 0.0;
            //return AbnormalPercentage;
        }
        else{
            AbnormalPercentage = (AbnormalBeat * 100)/totalBeat ;
        }
        cout << "Total Number of Abnormal Percentages: " << AbnormalPercentage <<"%"<< endl;

        if(AbnormalPercentage >= 20){
            cout << "Clinical Warning. Readings must be reviewed" << endl;
        }
    }

    };
int main(){
    CardiacMonitor CM;
    char input;
    cout << "Enter N for Normal Count" << endl;
    cout << "Enter A for Abnormal Count" << endl;
    cout << "Enter E to end and Display" << endl;

    do{
        cin >> input;
        if(input == 'N' || input == 'n'){
            CM.NormalBeatBeatCount();
        }
        else if(input == 'A' || input == 'a'){
            CM.AbnormalBeatCount();
        }
        else if( input == 'E' || input == 'e'){
            CM.display();
            break;
        }
        else{
            cout << "You have entered the wrong input. Enter only N,A or E"<< endl;
        }

    }while(true);

    return 0;
}
