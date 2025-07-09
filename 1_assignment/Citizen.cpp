#include "Citizen.h"
#include "Ticket.h"
#include <iostream>

Citizen::Citizen(string n, string c, string p)
    : name(n), cnic(c), phone(p) {}

void Citizen::addTicket(Ticket* t) {
    tickets.push_back(t);
}

void Citizen::viewTickets() {
    for (auto t : tickets) {
        t->viewDetails();
    }
}