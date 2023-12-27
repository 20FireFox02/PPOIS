#include "pch.h"
#include "Class.hpp"

std::string Class::New_Student(Person new_student)
{
	Schoolboy new_schoolboy(new_student.name, new_student.surname, new_student.age);
	students.push_back(new_schoolboy);
	return "Let's say Hello the new classmate " + new_schoolboy.name + " " + new_schoolboy.surname + " !";
}

std::string Class::Leave_Student(std::string name, std::string surname)
{
	for (int i = 0; i < students.size(); i++) {
		if (name == students[i].name) {
			if (surname == students[i].surname) {
				students.erase(students.begin() + i);
				return "Goodbye " + name + " " + surname;
			}
		}
	}
	return NO_ANSWER;
}

Schoolboy Class::Get_Schoolboy(int student) const
{
	if (student > 0 && student < students.size()) return students[student];
	return Schoolboy();
}

int Class::Amount_of_Student() const
{
	return students.size();
}
