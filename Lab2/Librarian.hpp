#include "Library.hpp"
class Librarian : public Staff {
public:
	Librarian(std::string name, std::string surname, int age, class Cabinet work_place, int salary);
	Book Give_Book(std::string name, Library& library);
	void Get_Book(Book book, Library& library);
};