#include "Vehicle.h"

Vehicle::Vehicle(string p, string r, string t)
    : plateNumber(p), registration(r), type(t) {}

string Vehicle::getPlate() {
    return plateNumber;
}

// ===== Officer.h =====
#ifndef OFFICER_H
#define OFFICER_H

#include <string>
using namespace std;

class Officer {
private:
    int badgeNumber;
    string name;
public:
    Officer(int b, string n);
};

#endif
