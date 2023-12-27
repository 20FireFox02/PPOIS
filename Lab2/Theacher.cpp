#include "pch.h"
#include "Theacher.hpp"



Theacher::Theacher(std::string name, std::string surname, int age, Cabinet work_place, int salary, Subject subject) : Staff(name, surname, age, work_place, salary)
{
	this->subject = subject;
}

int Theacher::Ask_A_Question(Schoolboy scholboy, std::string quesition, School school)
{
	for (int i = 0; i < knowledge.size(); i++) {
		if (knowledge[i].question == quesition) {
			if (knowledge[i].subject.name == subject.name) {
				std::cout << scholboy.surname << " please answer " << quesition;
				if (scholboy.Answer(quesition) == knowledge[i].answer) {
					std::cout << "Great";
					return 1;
				}
				else std::cout << "Bad";
				return 0;
			}
		}
	}
	return -1;
}

double Theacher::Theach(std::string question, Class school_class)
{
	int utility = 0;
	Knowledge material = Get_Question(question);
	for (int j = 0; j < school_class.Amount_of_Student(); j++)
		utility += school_class.Get_Schoolboy(j).Learn(material);
	return (double)utility / school_class.Amount_of_Student();
}

Subject Theacher::Get_Subject() const
{
	return subject;
}