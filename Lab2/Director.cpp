#include "pch.h"
#include "Director.hpp"
#include "Wachman.hpp"

std::string Director::Fire(Staff staff, School& school)
{
	for (int i = 0; i < school.staff.size(); i++) {
		if (staff.name == school.staff[i].name)
			if (staff.surname == school.staff[i].surname)
				if (staff.age == school.staff[i].age) {
					school.staff.erase(school.staff.begin() + i);
					return staff.name + " " + staff.surname + " you are fired";
				}
	}
	return "Who?";
}

void Director::Hire(Person new_staff, class School& school, int work, int salary, Cabinet cabinet)
{
	std::cout << new_staff.name << new_staff.surname << "you are hired as a ";
	if (work == 0) {
		std::cout << "cook";
		Cook staff(new_staff.name, new_staff.surname, new_staff.age, cabinet, salary);
		school.staff.push_back(staff);
	}
	else {
		std::cout << "wachman";
		Watchman staff(new_staff.name, new_staff.surname, new_staff.age, cabinet, salary);
		school.staff.push_back(staff);
	}


}

void Director::Hire(Person new_staff, class School& school, Subject subject, int salary, Cabinet cabinet)
{
	std::cout << "you are hired as a " << subject.name << "theacher";
	Theacher staff(new_staff.name, new_staff.surname, new_staff.age, cabinet, salary, subject);
	school.staff.push_back(staff);
}

bool Director::Buy_Equipment(Equipment equipment, int price, Cabinet& cabinet, class School& school)
{
	std::cout << "I need to buy " << equipment.name;
	if (school.budget - price > 200) {
		cabinet.inventory.push_back(equipment);
		return true;
	}
	else {
		return false;
	}
}

bool Director::Salary(School& school)
{
	for (int i = 0; i < school.staff.size(); i++) {
		school.budget -= school.staff[i].salary;
		if (school.budget < 0) {
			std::cout << "Sorry school budget is NULL";
			return false;
		}
	}
	return true;
}