#include "Manager.h"
#include <iostream>
#include <stdexcept>

Manager::Manager(int hours, double base, double bonus) : Employee(hours), base(base), bonus(bonus)
{
    if (base < 0) {
        throw std::invalid_argument("Base salary cannot be negative");
    }
    if (bonus < 0) {
        throw std::invalid_argument("Bonus cannot be negative");
    }
}

double Manager::Salary() const {
    int S = base + bonus;
    return S;
}