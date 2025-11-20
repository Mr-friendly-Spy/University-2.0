#pragma once

class Employee {
public:
	Employee(int hours);
	void AddHours(int hours);
	double Salary();
	int hours;
};