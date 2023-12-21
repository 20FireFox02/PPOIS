#pragma once
#include <fstream>
#include "Tape.hpp"
#include "Rules.hpp"
/*!
    Method for setting the properties of the head, the value of which is taken from the string
    \param[in] str A string containing the properties of the machine head
    \param[out] head Machine head
    \param[out] tape Machine tape
    \retutn FALSE if there was an error reading from the string else TRUE
*/
bool Edit_Head(std::string str, Head&, Tape&);
/*!
    Method for adding a new rule from a string
    \param[in] str String with rules
    \param[out] rules Machine rules
    \retutn FALSE if there was an error reading from the string else TRUE
*/
bool New_Rule(std::string str, Rules& rules);
/*!
    Helper method to get a word from a string
    \param[in] str A string
    \param[in] position Position of the first letter of a word
    \retutn Received word
*/
std::string Get_Word(std::string str, int& position);
/*!
    Method for reading car data from a file
    \param[in] file File name
    \param[out] head Machine head
    \param[out] tape Machine tape
    \param[out] rules Machine rules
    \retutn TRUE if this file exist else FALSE
*/
bool Loading_From_File(std::string file, Head& head, Tape& tape, Rules& rules);