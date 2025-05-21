#include<iostream>
using namespace std;
class Room{
    public:
    int roomNo;
    string guest;
    bool isBooked;
    Room(int roomNo, string guest, bool isBooked){
        this->roomNo = roomNo;
        this->guest = guest;
        this->isBooked = isBooked;
    }
    
    void printRoomInfo(){
        cout<<"room no "<<roomNo<<endl;
        cout<<"guest "<<guest<<endl;
        cout<<(isBooked ? "booked" : "Available")<<endl;
    }
    void BookRoom(string newGuest){
        if (!isBooked)
        {
            this->isBooked = !isBooked;
            this->guest = newGuest;
            cout<<"Room booked for "<<guest<<endl; 
        }else{
            cout<<"Room is already booked";
        }
        
    }

};

int main()
{
    Room room1(101, "babar", false);
    Room room2(102, "faisal", true);

    room1.printRoomInfo();
    room1.BookRoom("ashfaq");
    room1.printRoomInfo();
    return 0;
}