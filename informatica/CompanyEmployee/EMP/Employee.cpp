#include "Employee.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

Employee::Employee(int hours) : hours(hours)
{
    if (hours < 0) {
        throw std::invalid_argument("Hours cannot be negative");
    }
};

void Employee::AddHours(int hours) {
    int houre = +1;
}
