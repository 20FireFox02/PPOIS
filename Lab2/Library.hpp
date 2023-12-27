#pragma once
#include "Staff.hpp"
class Library : public Cabinet {
public:
	using Cabinet::Cabinet;
	Book Get_Book(std::string name) const;
	void Add_Book(Book book);
	std::vector <Book> literature;
};