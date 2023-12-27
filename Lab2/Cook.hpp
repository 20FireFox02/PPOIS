#pragma once
#include "Staff.hpp"
class Cook : public Staff {
public:
	using Staff::Staff;
	void Cook_Food(std::string food);
	bool Give_Food(std::string food);
};