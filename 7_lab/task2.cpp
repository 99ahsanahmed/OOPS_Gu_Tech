#include<iostream>
using namespace std;
class Light{
    private:
        bool status;
        string location;
    public:
        Light(string l){
            location = l;
        }
        
        void turnOn(){
            status = true;
            return;
        }

        void turnOff(){
            status = true;
            return;
        } 

        void getStatus(){
            cout << location << "'s light is truned" << (status? "On" : "Off");
            cout << endl;
            return;
        }
};

class Thermostat {
    private:
        float temperature;
    public:
        Thermostat() : temperature(0.0) {}

        void updateTemperature(float t) {
            temperature = t;
        }

        float getTemperature() const {
            return temperature;
        }
};

class SmartHome{
    private:
        Light bedroomLight; 
        Light LoungeLight; 
        Thermostat thermostat;
    public:
        SmartHome() : LoungeLight("Lounge Light"), bedroomLight("Bedroom") {} 

        void onAllLight(){
            LoungeLight.turnOn();
            bedroomLight.turnOn();
        }

        void offAllLight(){
            LoungeLight.turnOff();
            bedroomLight.turnOff();
        }

        void setHomeTemperature(float temp) {
            thermostat.updateTemperature(temp);
        }

        void HomeReport(){
            LoungeLight.getStatus();
            bedroomLight.getStatus();
            cout << "Thermostat is set to " << thermostat.getTemperature() << "°C" << endl;
        }
};
int main()
{
    SmartHome home;

    home.onAllLight();
    home.setHomeTemperature(22.5);

    cout << "Smart Home Report" << endl;
    home.HomeReport();
    return 0;
}