// Lab Task 2: Shipment Time Estimator
// A logistics system tracks parcels that are categorized as LocalParcel and InternationalParcel.
// Base class Parcel includes:

// ○ Private: parcelID (string)
// ○ Protected: weight (in kg)
// ○ Public:
// ■ Constructor to set parcelID and weight
// ■ GetParcelID() getter

// ● Class TimedParcel inherits from Parcel and adds:
// ○ Protected: deliverySpeed (in km/h)
// ○ Constructor to set all values
// ○ Method GetEstimatedTime(float distance) → returns time = distance /
// deliverySpeed

// ● Class InternationalParcel inherits from TimedParcel and adds:
// ○ Attribute: customsDelay (in hours)
// ○ Method GetTotalDeliveryTime(float distance) that adds customsDelay to time

// Implement all classes and write a main() function that creates an InternationalParcel and prints
// total delivery time for a given distance.

#include<iostream>
using namespace std;

class Parcel{
    private:
        string parcelId;
    protected:
        int weight;
    public:
        Parcel(string pd, int w){
            parcelId = pd;
            weight = w;
        }
        void getParcelId(){
            cout<<"parcel Id"<<parcelId<<endl;
        }
};

class TimedParcel : public Parcel{
    protected : 
        float deliverySpeed;
    public : 
        float distance;
        float time;
        TimedParcel(float deliverySpeed, float distance, string parcelId, int weight) : Parcel(parcelId, weight)
        {
            this->deliverySpeed = deliverySpeed;  
            this->distance = distance;  
        }
        float getEstimatedTime(){
            return time = deliverySpeed / distance;
        }
};

class InternationalParcel : public TimedParcel{
    public :
    int customsDelay;
     InternationalParcel(int cs, float deliverySpeed, float distance, string parcelId, int weight) : TimedParcel(deliverySpeed, distance, parcelId, weight) {
        customsDelay = cs;
     };
    float GetTotalDeliveryTime(){
        return getEstimatedTime() + customsDelay; 
    }
};  

int main()
{
    InternationalParcel ip(35, 1.53, 2456.6, "1", 10);
    cout<<ip.getEstimatedTime();
    cout<<ip.GetTotalDeliveryTime();
    return 0;
}