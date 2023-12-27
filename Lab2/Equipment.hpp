#pragma once
#include "Person.hpp"
class Equipment {
public:
	std::string Get_Name() const;
	Equipment(std::string name);
	std::string name;
};