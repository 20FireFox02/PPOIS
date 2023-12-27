#include "pch.h"
#include "Library.hpp"

Book Library::Get_Book(std::string name) const
{
	for (int i = 0; i < literature.size(); i++) {
		if (literature[i].Get_Name() == name) {

			return literature[i];
		}
	}
	return Book(NO_ANSWER);
}

void Library::Add_Book(Book book)
{
	literature.push_back(book);
}