#pragma once
#include <iostream>
#define NO_ANSWER ""
class Subject {
public:
	Subject();
	Subject(std::string name);
	std::string Get_Name() const;
	std::string name;
};