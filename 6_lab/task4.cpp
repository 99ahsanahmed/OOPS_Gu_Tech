#include<iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;

class NotificationHandler{
    public : 
    virtual void sendNotification(string userId, string message) = 0;
};

class EmailNotificationHandler : public NotificationHandler{
    public : 
    void sendNotification(string userId, string message) override {
        cout << message << " : Sending Email to " << userId << "\n";
    }
};

class SMSNotificationHandler : public NotificationHandler{
    public : 
    void sendNotification(string userId, string message) override {
        cout << message << " : Sending SMS to  " << userId << "\n";
    }
};
class AppNotificationHandler : public NotificationHandler{
    public : 
    void sendNotification(string userId, string message) override {
        cout << message << " : Pushing App notification to " << userId << "\n";
    }
};

class Dispatcher{ //TOOK HELP FROM CHATGPT TO CREATE RANDOM FUNCTION
    public : 
    NotificationHandler *sender1;
    NotificationHandler *sender2;
    NotificationHandler *sender3;
    
   void sendRandomNotification(string userId, string message) {
        int choice = rand() % 3; 

        if (choice == 0 && sender1)
            sender1->sendNotification(userId, message);
        else if (choice == 1 && sender2)
            sender2->sendNotification(userId, message);
        else if (choice == 2 && sender3)
            sender3->sendNotification(userId, message);
    }
};
int main()
{
    srand(time(0)); 
    Dispatcher d;
    d.sender1 = new EmailNotificationHandler();
    d.sender2 = new SMSNotificationHandler();
    d.sender3 = new AppNotificationHandler();

    d.sendRandomNotification("232" , "You are fired!");

    delete d.sender1;
    delete d.sender2;
    delete d.sender3;

    return 0;
}