#include "pch.h"
#include "Knowledge.hpp"

Knowledge::Knowledge(Subject theme, std::string question, std::string answer, int schoolyer_knowledge)
{
	this->subject = theme;
	this->question = question;
	this->answer = answer;
	this->schoolyer_knowledge = schoolyer_knowledge;
}

std::string Knowledge::Get_Question() const
{
	return question;
}

std::string Knowledge::Get_Answer() const
{
	return answer;
}

Subject Knowledge::Get_Subject() const
{
	return subject;
}
