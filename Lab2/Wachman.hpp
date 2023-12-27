#pragma once
#include "School.hpp"
class Watchman : public Staff {
public:
	using Staff::Staff;
	void Pull_A_Bell(School& school);
};