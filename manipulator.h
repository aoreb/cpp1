#ifndef MANIPULATOR_H
#define MANIPULATOR_H
#include "point.h"

class Manipulator {
private:
    double R;
    Point O;

public:
    Manipulator(double x, double y, double r);
    double GetX() const;
    double GetY() const;
    Point GetO();
    double GetR() const;
    void SetX(double x);
    void SetY(double y);
    void SetR(double r);
};

#endif // MANIPULATOR_H
