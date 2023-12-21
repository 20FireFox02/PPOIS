#include "Head.hpp"

void Head::Set_Position(int position) { this->position = position; }
void Head::Set_State(std::string state) { this->state = state; }
int Head::Get_Position() const { return position; }
std::string Head::Get_State() const { return state; }