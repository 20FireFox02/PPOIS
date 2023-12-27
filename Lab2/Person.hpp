#pragma once
#include <vector>
#include "Knowledge.hpp"
class Person {
public:
	Person();
	Person(std::string name, std::string surname, int age);
	Knowledge Get_Question(std::string question) const;
	void New_Knowledge(Knowledge knowledge);
	std::string Get_Name() const;
	std::string Get_Surname() const;
	int Get_Age() const;
	std::vector<Knowledge> knowledge;
	std::string name;
	std::string surname;
	int age;
};