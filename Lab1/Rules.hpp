#pragma once
#include <vector>
#include "Action.hpp"
#define R 'R'
#define L 'L'
#define N 'N'
///< Rule class
class Rules {
public:
    /*!
        Destructor for clearing the rules table
    */
    ~Rules();
    /*!
        Method for obtaining the state of the number
        \param[in] position State number
        \return State
    */
    std::string Get_State(int position) const;
    /*!
        Method for obtaining the word of the number
        \param[in] position Word number
        \return Word
    */
    std::string Get_Word(int position) const;
    /*!
        Method for getting the amount of different states
        \return Amount of different states
    */
    int Get_Amount_Of_States() const;
    /*!
        Method for getting the amount of different words
        \return Amount of different states
    */
    int Get_Amount_Of_Words() const;
    /*!
        Method for obtaining actions based on specified conditions
        \param[in] state State number
        \param[in] word Word number
        \return Action
    */
    Action* Get_Rule(int state, int word) const;
    /*!
        Method for adding a new rule
        \param[in] move Symbol with move
        \param[in] newword String with new word
        \param[in] newstate String with new state
        \param[in] word String with word
        \param[in] state String with state
    */
    void New_Rule(char move, std::string newword, std::string newstate, std::string word, std::string state);
    /*!
        Method for deleting a rule
        \param[in] word Word of the rule to be deleted
        \param[in] state State of the rule to be deleted
        \return TRUE if such a rule exists else FALSE
    */
    bool Remove_Rule(std::string word, std::string state);
    /*!
        Method for viewing rules
        \return Rules recorded in string
    */
    std::string View() const;
private:
    std::vector <std::string> states;
    std::vector <std::string> words;
    std::vector <std::vector <Action*>> table;
};