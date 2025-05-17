// Bonus:
// Why should maxLimit be read-only after construction? What OOP principle does this follow?
//It Follows encapsulation, it doesn't want ths user to edit private attribute which is max limit. But still use it in methods

#include<iostream>
using namespace std;

class TimedCounter{
    private : 
        int counter;  
        int maxLimit;  
        int resetInterval;
    public :
        TimedCounter(int c, int ml, int rI){
            counter = c;
            resetInterval = rI;
            if (ml<1){
                maxLimit = 10;
            }
            else{
                maxLimit = ml;
            }  
        }

        void increment(){
            if (counter < maxLimit)
            {
                counter+=1;
                cout<<"counter value increased from "<<counter-1 <<" to "<<counter<<endl;
            }   
        }

        void ResetIfDue(int secondsElapsed){
            if (secondsElapsed >= resetInterval)
            {
                cout<<"secondsElapsed is less than resetInterval, counter is reset to 0"<<endl;
                counter=0;
                return;
            }
            else{
                cout<<"secondsElapsed is greater than resetInterval, counter is not reset"<<endl;
                return;  
            } 
        }

        int getCounter() {
            return counter;
        };

        int getMaxLimit() {
            return maxLimit;
        };
};

int main()
{
    TimedCounter TimedCounter1(2, 0, 6);
    cout<<TimedCounter1.getCounter()<<endl;
    cout<<TimedCounter1.getMaxLimit()<<endl;
    TimedCounter1.increment();
    TimedCounter1.ResetIfDue(6);
    cout<<TimedCounter1.getCounter()<<endl;
    

    return 0;
}