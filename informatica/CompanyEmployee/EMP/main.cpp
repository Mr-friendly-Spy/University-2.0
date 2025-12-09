#include <iostream>

#include "Engineer.h"
#include "Manager.h"

int main() {

	try
	{
		Engineer engineer1(160, 25.5);  // 160 часов, ставка 25.5
		Engineer engineer2(140, 30.0);  // 140 часов, ставка 30.0
		Manager manager1(0, 5000.0, 1000.0);  // оклад 5000, премия 1000
		Manager manager2(0, 6000.0, 1500.0);  // оклад 6000, премия 1500

		std::cout << "Engineer1 salary: $" << engineer1.Salary() << std::endl;
		std::cout << "Engineer2 salary: $" << engineer2.Salary() << std::endl;
		std::cout << "Manager1 salary: $" << manager1.Salary() << std::endl;
		std::cout << "Manager2 salary: $" << manager2.Salary() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;

	}
	return 0;
}