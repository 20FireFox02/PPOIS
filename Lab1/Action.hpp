#pragma once
#include <string>
///< Class for storing actions
class Action {
public:
    /*!
        Method for setting a new state
        \param[in] newstate New state
    */
    void Set_New_State(std::string newstate);
    /*!
        Method for setting a new word
        \param[in] newword New word
    */
    void Set_New_Word(std::string newword);
    /*!
        Method for setting a move
        \param[in] move Move
    */
    void Set_Move(char move);
    /*!
        Method to get new state
        \return New state
    */
    std::string Get_New_State() const;
    /*!
        Method to get new word
        \return New word
    */
    std::string Get_New_Word() const;
    /*!
        Method to get move
        \return Move
    */
    char Get_Move() const;
private:
    std::string new_state;
    std::string new_word;
    char move;
};