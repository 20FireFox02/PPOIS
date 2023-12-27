#include "pch.h"
#include "School.hpp"

//Schoolboy-----------

//-----------------

//Knowledge--------


//-----------
//Equipment-------------------------




School::School(std::string name, std::string adress, int yer)
{
	this->name = name;
	this->adress = adress;
	state = BREAK;
	lesson_number = 0;
	
	for (int i = 0; i < LAST_CLASS; i++) {
		Steam steam(yer - i);
		steams.push_back(steam);
	}
}

std::string School::New_Schoolyear()
{
	Steam new_steam(steams[10].Get_Year_Of_Admission() + LAST_CLASS);
	std::string output = steams[10].High_School_Graduation();
	output += "! Good luck!";
	
	for (int i = 10; i >= 1; i--) {
		steams[i] = steams[i - 1];
		steams[i].New_Year();
	}
	
	steams[0] = new_steam;
	return output;
}













//Equipment Librarian::Give_Book(std::string name)
//{
//	std::cout << "Wait a minute" << std::endl;
//	for (int i = 0; i < work_place.size(); i++) {
//		if (work_place.inventory[i].name == name) {
//			std::cout << "Here" << std::endl;
//			return work_place.inventory[i];
//		}
//	}
//	std::cout << "Sorry, there is not " << name << std::endl;
//}





//Book Librarian::Give_Book(std::string name)
//{
//	std::cout << "Wait a minute" << std::endl;
//		for (int i = 0; i < work_place.size(); i++) {
//			if (work_place.literature[i].name == name) {
//				std::cout << "Here" << std::endl;
//				return work_place.inventory[i];
//			}
//		}
//		std::cout << "Sorry, there is not " << name << std::endl;
//	return Book();
//}




