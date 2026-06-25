
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



    };
int main(){


    return 0;
}
