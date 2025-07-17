#include<iostream>
using namespace std;
// Task 3: Create a Time class that represents time in hours and minutes. Implement operators to
// add times, compare times, and increment/decrement by minutes.
class Time{
    private:
    int hours, minutes;
    public:
    Time(int h, int m) : hours(h), minutes(m) {}
    Time operator+(const Time& other) const{
        int totalHours,totalMinutes,remMinutes;
        totalMinutes = minutes + other.minutes;
        totalHours = hours + other.hours + (totalMinutes / 60);
        remMinutes = totalMinutes % 60; // Other than multiples of 60
        return Time(totalHours, remMinutes);
    }
    bool operator<(const Time& other) const{
        return (hours < other.hours && minutes < other.minutes);
    }
    void operator++(){
        minutes++;
    }
    void operator--(){
        minutes--;
    }
    void display() const{
        cout << hours << " hours and " << minutes << " minutes" << endl;
    }
};

int main(){
    Time t1(2, 30);
    Time t2(1, 45);
    Time sum = t1 + t2;
    cout << "Sum of times: ";
    sum.display();
    if(t1 < t2){
        cout << "t1 is less than t2" << endl;
    }else{
        cout << "t1 is greater than t2" << endl;
    }
    ++t1;
    cout << "t1 minutes after increment: ";
    t1.display();
    --t1;
    cout << "t1 minutes after decrement: ";
    t1.display();
    return 0;
}