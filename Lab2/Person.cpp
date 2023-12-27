#include "pch.h"
#include "Person.hpp"
#define NO_SUBJECT Subject(NO_ANSWER)

Person::Person()
{
}

Person::Person(std::string name, std::string surname, int age)
{
	this->name = name;
	this->surname = surname;
	this->age = age;
}
Knowledge Person::Get_Question(std::string question) const
{
	for (int i = 0; i < knowledge.size(); i++) {
		if (question == knowledge[i].Get_Question()) {
			return knowledge[i];
		}
	}
	return Knowledge(NO_SUBJECT, NO_ANSWER, NO_ANSWER, 0);
}
void Person::New_Knowledge(Knowledge knowledge)
{
	this->knowledge.push_back(knowledge);
}
std::string Person::Get_Name() const
{
	return name;
}
std::string Person::Get_Surname() const
{
	return surname;
}
int Person::Get_Age() const
{
	return age;
}