#include "manipulator.h"

Manipulator::Manipulator(double x, double y, double r) {
    O = {x, y};
    R = r;
}

double Manipulator::GetX() const {
    return O.X;
}

double Manipulator::GetY() const {
    return O.Y;
}

Point Manipulator::GetO() {
    return O;
}

double Manipulator::GetR() const {
    return R;
}

void Manipulator::SetX(double x) {
    O.X = x;
}

void Manipulator::SetY(double y) {
    O.Y = y;
}

void Manipulator::SetR(double r) {
    R = r;
}
