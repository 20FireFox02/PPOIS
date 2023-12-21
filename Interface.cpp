#include "Interface.hpp"

bool Interface(Head& head, Tape& tape, Rules& rules, std::string choice) {
    std::string input;
    if (choice == GO) {
        if (head.Get_Position() < 0 || head.Get_Position() >= tape.Get_Size()) {
            tape.Add_Cell(head.Get_Position(), "");
        }
        if (!Turing_Mashine(head, tape, rules)) std::cout << "Algorithm was stopped: more them 100 move..." << std::endl;
        else std::cout << "Algorithm is done!" << std::endl;
    }
    else if (choice == ADD_CELL) {
        std::cout << "POSITION|WORD" << std::endl;
        std::cin >> input;                                  // ���� ��������
        int position, i = 0;
        try { position = stoi(Get_Word(input, i)); }         // ������� ��������� �������
        catch (...) { position = tape.Get_Size(); }          // ���� ������� �� �������� -- ������� ��������� �� �����
        if (i >= input.size()) tape.Add_Cell(position, VOID);  // �������� ����� ������. ���� �����, �� ��������� ������ ������
        for (i; i < input.size();) {                        // ��������� ������ �� ��������� �������
            tape.Add_Cell(position, Get_Word(input, i));
            position++;
        }
    }
    else if (choice == SET_CELL) {
        std::cout << "WORD|POSITION" << std::endl;
        std::cin >> input;                                  // ���� ��������
        int position, i = 0;
        try { position = stoi(Get_Word(input, i)); }         // ������� ��������� �������
        catch (...) { position = tape.Get_Size(); }          // ���� ������� �� �������� -- ������� ��������� �� ����� �����
        if (i >= input.size()) tape.Add_Cell(position, VOID);  // �������� ����� ������. ���� �����, �� ��������� ������ ������
        for (i; i < input.size();) {                        // �������� ������ �� ��������� �������
            tape.Set_Cell(position, Get_Word(input, i));
            position++;
        }
    }
    else if (choice == REMOVE_CELL) {
        std::cout << "POSITION" << std::endl;
        std::cin >> input;                                          // ���� ��������
        int position = 0;
        try { tape.Remove_Cell(stoi(Get_Word(input, position))); }    // ������� �������� ������� ������
        catch (...) { tape.Remove_Cell(); }                          // ���� ������� �� �������� -- ��������� ��������� ������
    }
    else if (choice == NEW_RULE) {
        std::cout << "STATE|WORD|NEWSTATE|NEWWORD|MOVE" << std::endl;
        std::cin >> input;                                              // ���� ��������
        New_Rule(input, rules);                                          //���������� �������
    }
    else if (choice == REMOVE_RULE) {
        std::cout << "STATE|WORD" << std::endl;
        std::cin >> input;                                                  // ���� ��������
        bool error = true;
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '|') {                                      // �������� ������������ �����
                i = 0;
                rules.Remove_Rule(Get_Word(input, i), Get_Word(input, i)); // �������� �������
                error = false;
                break;
            }
        }
        if (error) std::cout << "Error: invalide argument..." << std::endl; // ���� ������� �� ������� �������
    }
    else if (choice == EDIT_HEAD) {
        std::cout << "STATE|POSITION" << std::endl;
        std::cin >> input;                          // ���� ��������
        Edit_Head(input, head, tape);                // ����� �������� �������
    }
    else if (choice == VIEW_RULES) {
        std::cout << rules.View();                  // ����� ������
    }
    else if (choice == VIEW_TAPE) {
        std::cout << tape.View(head);               // ����� �����
    }
    else if (choice == EXIT) { return true; }       // ����� ���������
    else if (choice == HELP) std::cout << "Commands:\n\tGo\n\tAddCell\n\tSetCell\n\tRemoveCell\n\tNewRule\n\tRemoveRule\n\tEditHead\n\tViewTape\n\tViewRules\n\tHelp\n\tExit" << std::endl;
    else std::cout << "Input error..." << std::endl;    // ���� ������ ������
    return false;
}