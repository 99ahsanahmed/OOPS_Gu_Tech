#include<iostream>
using namespace std;
class Sensor{
    private : 
        string id;
        float value;
    public : 
        Sensor(string id){
            this->id = id;
        }
        void setValue(float val){
            value = val;
        }
        void getValue(){
            cout<< value << endl;
        }
        string getId(){
            return id;
        }
    protected : 
        float isThresholdExceeded(float threshold){
            return threshold;
        }
}; 

class TemperatureSensor : public Sensor{
    public : 
        float temperature;
        TemperatureSensor(float temp, string id) : Sensor(id){
            temperature = temp;
        }

        void TriggerAlarm(){
            if (temperature > isThresholdExceeded(70.5))
            {
                cout<< "ALERT: "<< getId() <<"temperature exceeded!";
            }
            else{
                cout<< "chill scene";
            }
        }
};

int main()
{
    TemperatureSensor ts(100,"453");
    ts.setValue(45.5);
    ts.TriggerAlarm();
    return 0;
}