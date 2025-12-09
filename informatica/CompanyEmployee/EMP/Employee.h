#pragma once

class Employee {
public:
	Employee(int hours);
	void AddHours(int hours);
	virtual double Salary() const = 0;
	int hours;
};