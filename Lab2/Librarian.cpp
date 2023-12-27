#include "pch.h"
#include "Librarian.hpp"

Librarian::Librarian(std::string name, std::string surname, int age, Cabinet work_place, int salary)
{
	this->name = name;
	this->surname = surname;
	this->age = age;
	this->work_place = work_place;
	this->salary = salary;
}

Book Librarian::Give_Book(std::string name, Library& library)
{
	Book book = library.Get_Book(name);
	if (book.Get_Name() == name) {
		std::cout << "Here";
		return book;
	}
	std::cout << "Sorry nothing";
	return book;
}

void Librarian::Get_Book(Book book, Library& library)
{
	std::cout << "Ok";
	library.Add_Book(book);
}
