#include "pch.h"
#include "Equipment.hpp"

std::string Equipment::Get_Name() const
{
	return name;
}

Equipment::Equipment(std::string name)
{
	this->name = name;
}