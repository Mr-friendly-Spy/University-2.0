#pragma once
#include "Employee.h"

class Engineer : public Employee {
public:
	Engineer(int hours, double rate);
	double rate;
	double Salary() const override;
};
