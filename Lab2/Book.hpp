#pragma once
#include "Equipment.hpp"
class Book : public Equipment {
public:
	using Equipment::Equipment;
	Knowledge Get_Content(int i) const;
	std::vector<Knowledge> contents;
};