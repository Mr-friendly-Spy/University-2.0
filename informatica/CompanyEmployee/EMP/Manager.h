#pragma once

#include "Employee.h"

class Manager : Employee {
public:
	Manager(int hours, double base, double bonus);
	double base;
	double bonus;
	double Salary() const override;

};