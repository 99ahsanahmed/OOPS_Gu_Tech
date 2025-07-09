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