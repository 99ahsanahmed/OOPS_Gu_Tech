#include "Ticket.h"
#include "ViolationType.h"
#include "Officer.h"
#include "Citizen.h"
#include "Vehicle.h"
#include <iostream>
#include <cstdlib>

Ticket::Ticket(ViolationType* v, Officer* o, Citizen* c, Vehicle* ve)
    : violation(v), officer(o), citizen(c), vehicle(ve), isPaid(false) {
    ticketID = "T" + to_string(rand() % 10000);
    time(&timestamp);
    dueDate = timestamp + 15 * 24 * 3600;
}

void Ticket::viewDetails() {
    cout << "Ticket ID: " << ticketID << endl;
    cout << "Violation: " << violation->getName() << endl;
    cout << "Due Date: " << ctime(&dueDate);
    cout << "Fine: Rs." << violation->calculateFine() << endl;
}

string Ticket::getID() {
    return ticketID;
}