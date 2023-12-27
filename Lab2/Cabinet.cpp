#include "pch.h"
#include "Cabinet.hpp"

Cabinet::Cabinet()
{
}

Cabinet::Cabinet(std::string number)
{
	this->number = number;
}

std::string Cabinet::Get_Number() const
{
	return number;
}

Equipment Cabinet::Get_Equipment(std::string name) const
{
	for (int i = 0; i < inventory.size(); i++) {
		if (name == inventory[i].Get_Name()) return inventory[i];
	}
	return Equipment(NO_ANSWER);
}

void Cabinet::New_Equipment(Equipment equipment)
{
	inventory.push_back(equipment);
}
