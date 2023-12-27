#pragma once
#include "Cabinet.hpp"
class Staff : public Person {
public:
	Staff();
	Staff(std::string name, std::string surname, int age, Cabinet work_place, int salary);
	int Get_Salary() const;
	Cabinet Get_Work_Place() const;
	Cabinet work_place;
	int salary;
};