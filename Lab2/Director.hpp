#pragma once
#include "Theacher.hpp"
#include "Wachman.hpp"
#include <string>
class Director : public Theacher {
public:
	using Theacher::Theacher;
	std::string Fire(Staff staff, School& school);
	void Hire(Person new_staff, School& school, int work, int salary, Cabinet cabinet);
	void Hire(Person new_staff, School& school, Subject subject, int salary, Cabinet cabinet);
	bool Buy_Equipment(Equipment equipment, int price, Cabinet& cabinet, School& school);
	bool Salary(School& school);
};