#include "Action.hpp"

void Action::Set_New_State(std::string newstate) { this->new_state = newstate; }
void Action::Set_New_Word(std::string newword) { this->new_word = newword; }
void Action::Set_Move(char move) { this->move = move; }
std::string Action::Get_New_State() const { return new_state; }
std::string Action::Get_New_Word() const { return new_word; }
char Action::Get_Move() const { return move; }