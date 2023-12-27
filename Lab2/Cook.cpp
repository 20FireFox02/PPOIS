#include "pch.h"
#include "Cook.hpp"

void Cook::Cook_Food(std::string food)
{
	std::cout << "Wait" << std::endl;
}

bool Cook::Give_Food(std::string food)
{
	Equipment eat = Get_Work_Place().Get_Equipment(food);
	if (eat.Get_Name() == food) {
		std::cout << "Keep" << std::endl;
		return true;
	}

	std::cout << "Sorry now there isn't " << food << " in asortyment" << std::endl;
	return false;
}