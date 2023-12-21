#pragma once
#include <vector>
#include "Head.hpp"
#define VOID ""
/*!
    \brief Class for implementing the machine tape
*/
class Tape {
public:
    /*!
        Method for adding a cell to the end of a tape
        \param[in] word Added cell
    */
    void Add_Cell(std::string word);
    /*!
        Method for adding a cell by position
        \param[in] position Cell position
        \param[in] word Added cell
    */
    void Add_Cell(int position, std::string word);
    /*!
        Method to delete the last cell
        \return TRUE if such a cell exists else FALSE
    */
    bool Remove_Cell();
    /*!
        Method to delete a cell by position
        \param[in] position Cell position
        \return TRUE if such a cell exists else FALSE
    */
    bool Remove_Cell(int position);
    /*!
        Method for cell replacement
        \param[in] position Cell position
        \param[in] word New cell
    */
    void Set_Cell(int position, std::string word);
    /*!
        Method for receiving cell
        \param[in] position Cell position
        \return A cell
    */
    std::string Get_Cell(int position) const;
    /*!
        Method for obtaining tape length
        \return A tape lenght
    */
    int Get_Size() const;
    /*!
        Method for viewing tape with head position
        \param[in] head Machine head
        \retutn Tape recorded in string
    */
    std::string View(Head head) const;
private:
    std::vector <std::string> cells;
    /*!
        Helper method for adding cells when the head position extends beyond the tape
        \param[in,out] position Required position
    */
    void Search(int& position);
};