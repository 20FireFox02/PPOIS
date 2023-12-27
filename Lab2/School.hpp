#pragma once
#include "Staff.hpp"
#include "Steam.hpp"
#define BREAK 0
#define LESSON 1
#define LAST_CLASS 11

//------------------------------------

class School {
public:
	School(std::string name, std::string adress, int yer);
	std::string New_Schoolyear();
	std::vector <Staff> staff;
	std::vector <Cabinet> cabinets;
	std::vector <Steam> steams;
	std::string name;
	std::string adress;
	int state;
	int lesson_number;
	int day;
	int budget;
};