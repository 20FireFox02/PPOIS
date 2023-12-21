#pragma once
#include "Tape.hpp"
#include "Rules.hpp"
/*!
	Method for performing Turing machine simulation
	\param[in,out] head Mashine head
	\param[in,out] tape Machine tape
	\param[in] rules Machine rules
	\return FALSE if the number of steps is more than 100 else TRUE
*/
bool Turing_Mashine(Head& head, Tape& tape, Rules& rules);