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