#pragma once
#include "Book.hpp"
class Cabinet {
public:
	Cabinet();
	Cabinet(std::string number);
	std::string Get_Number() const;
	Equipment Get_Equipment(std::string name) const;
	void New_Equipment(Equipment equipment);
	std::string number;
	std::vector <Equipment> inventory;
};