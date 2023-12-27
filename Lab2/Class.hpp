#pragma once
#include "Schoolboy.hpp"
class Class {
public:
	std::string New_Student(Person new_student);
	std::string Leave_Student(std::string name, std::string surname);
	Schoolboy Get_Schoolboy(int student) const;
	int Amount_of_Student() const;
	char letter;
	std::vector<Schoolboy> students;
};