#include <windows.h>
#include "Execution.hpp"
#define LIMIT 100 

bool Turing_Mashine(Head& head, Tape& tape, Rules& rules)
{
    int travel = 0;
    while (travel < LIMIT) {                        // �������� �� ���������� �����
        std::cout << tape.View(head);                                                                       // ������� � ������� ��������� �����
        Sleep(2000);
        int i = 0, j = 0;
        while (i < rules.Get_Amount_Of_States() && head.Get_State() != rules.Get_State(i)) i++;                  // ���� ����� ������� ��� ��������� � ������� ���������
        if (i == rules.Get_Amount_Of_States()) return true;                                                    // ���� ��� �� �������, �� ����������� ������ ������ � ������������ true
        while (j < rules.Get_Amount_Of_Words() && tape.Get_Cell(head.Get_Position()) != rules.Get_Word(j)) j++;   // ���� ����� ������� ��� ����� � ������� ���������
        if (j == rules.Get_Amount_Of_Words()) return true;                                                     // ���� ��� �� �������, �� ����������� ������ ������ � ������������ true
        if (rules.Get_Rule(i, j) == NULL) return true;                                                       // ���� ������� ��� ������� ���������� � ������ �� ����������, �� �� ����������� ������ ������ � ������������ true
        tape.Set_Cell(head.Get_Position(), rules.Get_Rule(i, j)->Get_New_Word());                                // �������� ����� �� ������� ������� �� �����
        head.Set_State(rules.Get_Rule(i, j)->Get_New_State());                                                  // �������� ��������� ������� �� �����
        if (rules.Get_Rule(i, j)->Get_Move() == L) {                                                          // ���� ������� ������������� ������
            if (head.Get_Position() == 0) tape.Add_Cell(0, VOID);                                             // ���� ����� ����������� �������, �� ��������� ���
            else head.Set_Position(head.Get_Position() - 1);                                                  // ������� �������
        }
        else if (rules.Get_Rule(i, j)->Get_Move() == R) {                                                     // ���� ������� ������������� �������
            if (head.Get_Position() == tape.Get_Size()) tape.Add_Cell(VOID);                                   // ���� ������ ����������� �������, �� ��������� ���
            head.Set_Position(head.Get_Position() + 1);                                                       // ������� �������
        }
        travel++;
    }
    return false;
}
