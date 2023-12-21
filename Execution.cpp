#include <windows.h>
#include "Execution.hpp"
#define LIMIT 100 

bool Turing_Mashine(Head& head, Tape& tape, Rules& rules)
{
    int travel = 0;
    while (travel < LIMIT) {                        // ѕроверка на количество ходов
        std::cout << tape.View(head);                                                                       // ¬ыводим в консоль состо€ние ленты
        Sleep(2000);
        int i = 0, j = 0;
        while (i < rules.Get_Amount_Of_States() && head.Get_State() != rules.Get_State(i)) i++;                  // »щем номер нужного нам состо€ни€ в векторе состо€ний
        if (i == rules.Get_Amount_Of_States()) return true;                                                    // ≈сли его не находим, то заканчиваем работу машины с возвращением true
        while (j < rules.Get_Amount_Of_Words() && tape.Get_Cell(head.Get_Position()) != rules.Get_Word(j)) j++;   // »щем номер нужного нам слова в векторе состо€ний
        if (j == rules.Get_Amount_Of_Words()) return true;                                                     // ≈сли его не находим, то заканчиваем работу машины с возвращением true
        if (rules.Get_Rule(i, j) == NULL) return true;                                                       // ≈сли правила под данными состо€нием и словом не существует, то то заканчиваем работу машины с возвращением true
        tape.Set_Cell(head.Get_Position(), rules.Get_Rule(i, j)->Get_New_Word());                                // »змен€ем слово по позиции головки на новое
        head.Set_State(rules.Get_Rule(i, j)->Get_New_State());                                                  // »змен€ем состо€ние головки на новое
        if (rules.Get_Rule(i, j)->Get_Move() == L) {                                                          // ≈сли головка передвигаетс€ налево
            if (head.Get_Position() == 0) tape.Add_Cell(0, VOID);                                             // ≈сли слева отсутствует элемент, то добавл€ем его
            else head.Set_Position(head.Get_Position() - 1);                                                  // ƒвигаем головку
        }
        else if (rules.Get_Rule(i, j)->Get_Move() == R) {                                                     // ≈сли головка передвигаетс€ направо
            if (head.Get_Position() == tape.Get_Size()) tape.Add_Cell(VOID);                                   // ≈сли справа отсутствует элемент, то добавл€ем его
            head.Set_Position(head.Get_Position() + 1);                                                       // ƒвигаем головку
        }
        travel++;
    }
    return false;
}
