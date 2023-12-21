#pragma once
#include "Loading_From_File.hpp"
#include "Execution.hpp"
#define ADD_CELL "AddCell"
#define GO "Go"
#define SET_CELL "SetCell"
#define REMOVE_CELL "RemoveCell"
#define NEW_RULE "NewRule"
#define REMOVE_RULE "RemoveRule"
#define EDIT_HEAD "EditHead"
#define VIEW_RULES "ViewRules"
#define VIEW_TAPE "ViewTape"
#define HELP "Help"
#define EXIT "Exit"

/*!
    Method for interaction between user and program
    \param[in,out] head Mashine head
    \param[in,out] tape Machine tape
    \param[in, out] rules Machine rules
    \param[in] choice Action choice string
    \return FALSE if such action do not exist, TRUE if Action choice string is Exit
*/

bool Interface(Head& head, Tape& tape, Rules& rules, std::string choice);