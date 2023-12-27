#pragma once
#include "Subject.hpp"
class Knowledge {
public:
	Knowledge(Subject theme, std::string question, std::string answer, int schoolyer_knowledge);
	std::string Get_Question() const;
	std::string Get_Answer() const;
	Subject Get_Subject() const;
	std::string question;
	std::string answer;
	Subject subject;
	int schoolyer_knowledge;
};