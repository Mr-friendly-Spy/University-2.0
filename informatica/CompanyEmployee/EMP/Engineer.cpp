#include "Engineer.h"
#include <iostream>
#include <stdexcept>


Engineer::Engineer(int hours, double rate) :Employee(hours), rate(rate)
{
	if (rate < 0) {
		throw std::invalid_argument("Rate cannot be negative");
	}
}

double Engineer::Salary() const {
	int S = hours * rate;
	return S;
}