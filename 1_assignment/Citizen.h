#ifndef CITIZEN_H
#define CITIZEN_H

#include <string>
#include <vector>
using namespace std;

class Ticket;

class Citizen {
private:
    string name;
    string cnic;
    string phone;
    vector<Ticket*> tickets;
public:
    Citizen(string n, string c, string p);
    void addTicket(Ticket* t);
    void viewTickets();
};

#endif
