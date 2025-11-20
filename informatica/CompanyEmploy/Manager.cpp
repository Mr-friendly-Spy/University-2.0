#include "Manager.h"
#include <iostream>

Manager::Manager(int hours, double rate) {};

double Manager::Salary() {
	int S = base + bonus;
	std::cout << S;
}