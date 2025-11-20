#include "Engineer.h"
#include <iostream>

Engineer::Engineer(int hours, double rate);

double Engineer::Salary() {
	int S = hours * rate;
	std::cout << S; 
}
