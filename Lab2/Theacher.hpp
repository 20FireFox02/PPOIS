#include "School.hpp"
class Theacher : public Staff {
public:
	Theacher(std::string name, std::string surname, int age, Cabinet work_place, int salary, Subject subject);

	int Ask_A_Question(Schoolboy scholboy, std::string question, School school);
	double Theach(std::string question, Class school_class);
	Subject Get_Subject() const;
	Subject subject;
};