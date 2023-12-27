#include "pch.h"
#include "Steam.hpp"

std::string Steam::High_School_Graduation()
{
	return "High school graduation " + year_of_admission + 11;
}

Steam::Steam(int year_of_admission)
{
	this->year_of_admission = year_of_admission;
	year_of_study = 1;
}

int Steam::Get_Year_Of_Admission() const
{
	return year_of_admission;
}

void Steam::New_Year()
{
	year_of_study++;
}
