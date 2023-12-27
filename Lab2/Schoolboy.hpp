#pragma once
#include "Librarian.hpp"
#include "Cook.hpp"

class Schoolboy : public Person {
public:
	using Person::Person;
	std::string Answer(std::string question);
	int Learn(Knowledge knowledge);
	bool Get_Book(std::string name, Librarian librarian, Library& library);
	std::string Return_Book(std::string name, Librarian librarian,Library& library);
	std::string Go_To_Canteen(std::string food, Cook cook);
	std::vector<Book> literature;
};