#ifndef SPEEDING_H
#define SPEEDING_H

#include "ViolationType.h"

class Speeding : public ViolationType {
public:
    Speeding();
    double calculateFine() override;
};

#endif
