#include "Loading_From_File.hpp"

bool Edit_Head(std::string str, Head& head, Tape& tape) {
    int position = 0;
    head.Set_State(Get_Word(str, position));                      // ��������� ��������� ������� �� ������
    if (position >= str.size()) {                               // ���� ������ ��������� ��������
        head.Set_Position(0);                                    // ������� ������� �������������� ����
        return false;
    }
    else {
        try { head.Set_Position(stoi(Get_Word(str, position))); } // ������� ������� ������� �������
        catch (...) {                                           // ���� ��� �� ����������
            head.Set_Position(0);                                // ������� ������� �������������� ����
            return false;
        }
    }
    if (head.Get_Position() < 0) {                               // ���� ������ ������� ������ ����
        tape.Add_Cell(head.Get_Position(), VOID);                   // ����������� ���� �����
        head.Set_Position(0);                                    // ������� ������� �������������� ����
    }
    else if (head.Get_Position() >= tape.Get_Size()) { tape.Add_Cell(head.Get_Position(), VOID); } // ����������� ���� �����
    return true;
}

bool New_Rule(std::string str, Rules& rules) {
    int amount = 0, tmp = 0;
    for (int i = 0; i < str.size(); i++) {
        if (amount == 4) {                          // ��������� ������������ �����
            rules.New_Rule(str[tmp], Get_Word(str, tmp), Get_Word(str, tmp), Get_Word(str, tmp), Get_Word(str, tmp)); // ���������� �������
            amount = 0;
            i++;
            tmp = i;
        }
        if (str[i] == '|') amount++;                // ������� ���������� ���������������
    }
    if (amount == 0) return true;                   // �������� "��������" �� ������
    return false;
}
std::string Get_Word(std::string str, int& position) {
    std::string word = VOID;
    while (str[position] == ' ') position++;                    // ���������� ������� � ������ �����

    while (position < str.size() && str[position] != '|') {     // ������ �� ����� �� ����� ������ ��� ������� ��������������
        word += str[position];                                  // ���������� �����
        position++;
    }
    position++;
    return word;                                                // ���������� ���������� �����
}
bool Loading_From_File(std::string file_name, Head& head, Tape& tape, Rules& rules)
{
    std::ifstream file(file_name);                                      // ��������� ����
    if (!file) {                                                        // ���� ������� ����� �� ����������
        std::cout << "Error: such file do not exsist..." << std::endl;
        return false;
    }
    std::string str;
    std::getline(file, str);
    for (int i = 0; i < str.size();) tape.Add_Cell(Get_Word(str, i));     // ������ ����� �� �����
    std::getline(file, str);
    Edit_Head(str, head, tape);                                          // ������ ������� �� �����
    std::getline(file, str);
    New_Rule(str, rules);                                                // ������ ������� �� �����
    file.close();
    return true;
}