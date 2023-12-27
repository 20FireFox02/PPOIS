#pragma once
#include "Class.hpp"
class Steam {
public:
	std::string High_School_Graduation();
	Steam(int year_of_admission);
	int Get_Year_Of_Admission() const;
	void New_Year();
	int year_of_admission;
	int year_of_study;
	std::vector <Class> classes;
};