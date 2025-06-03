#ifndef TICKET_H
#define TICKET_H

#include <ctime>
#include <string>
using namespace std;

class ViolationType;
class Officer;
class Citizen;
class Vehicle;

class Ticket {
private:
    string ticketID;
    time_t timestamp;
    time_t dueDate;
    ViolationType* violation;
    Officer* officer;
    Citizen* citizen;
    Vehicle* vehicle;
    bool isPaid;
public:
    Ticket(ViolationType* v, Officer* o, Citizen* c, Vehicle* ve);
    void viewDetails();
    string getID();
};

#endif