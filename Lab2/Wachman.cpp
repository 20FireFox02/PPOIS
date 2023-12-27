#include "pch.h"
#include "Wachman.hpp"

void Watchman::Pull_A_Bell(School& school)
{
	if (school.state == LESSON) school.state = BREAK;
	else if (school.lesson_number < 7) {
		school.lesson_number++;
		school.state = LESSON;
	}
	else {
		if (school.day < 5) school.day++;
		else school.day = 1;
		school.lesson_number = 0;
	}
}