#include "Speeding.h"

Speeding::Speeding() {
    name = "Speeding";
    baseFine = 1500;
}

double Speeding::calculateFine() {
    return baseFine + (baseFine * 0.1);
}