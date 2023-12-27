#include "pch.h"
#include "Subject.hpp"

Subject::Subject()
{
}

Subject::Subject(std::string name)
{
	this->name = name;
}

std::string Subject::Get_Name() const
{
	return name;
}
