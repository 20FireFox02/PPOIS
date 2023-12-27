#include "pch.h"
#include "Staff.hpp"

Staff::Staff()
{
}

Staff::Staff(std::string name, std::string surname, int age, Cabinet work_place, int salsry) : Person(name, surname, age) {
	this->work_place = work_place;
	this->salary = salary;
}

int Staff::Get_Salary() const
{
	return salary;
}

Cabinet Staff::Get_Work_Place() const
{
	return work_place;
}

