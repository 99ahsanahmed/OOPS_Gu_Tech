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
            cout<<value<<endl;
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
                cout<<"ALERT: temperature exceeded!";
                //ID cannot be printed here, because it is private attribute
            }
            else{
                cout<<"chill scene";
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