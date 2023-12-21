#pragma once
#include <iostream>
///< Class for implementing the machine head
class Head {
public:
    /*!
        Method for setting the head position
        \param[in] position New position
    */
    void Set_Position(int position);
    /*!
        Method for setting the head state
        \param[in] state New state
    */
    void Set_State(std::string state);
    /*!
        Method to get head position
        \return Head position
    */
    int Get_Position() const;
    /*!
        Method to get head state
        \return Head state
    */
    std::string Get_State() const;
private:
    int position;
    std::string state;
};