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
        std::cin >> input;                                  // Ввод значений
        int position, i = 0;
        try { position = stoi(Get_Word(input, i)); }         // Попытка получения позиции
        catch (...) { position = tape.Get_Size(); }          // Если позиция не получена -- позиция указывает на конец
        if (i >= input.size()) tape.Add_Cell(position, VOID);  // Проверка конца строки. Если конец, то добавляем пустую ячейку
        for (i; i < input.size();) {                        // Добавляем ячейки на выбранную позицию
            tape.Add_Cell(position, Get_Word(input, i));
            position++;
        }
    }
    else if (choice == SET_CELL) {
        std::cout << "WORD|POSITION" << std::endl;
        std::cin >> input;                                  // Ввод значений
        int position, i = 0;
        try { position = stoi(Get_Word(input, i)); }         // Попытка получения позиции
        catch (...) { position = tape.Get_Size(); }          // Если позиция не получена -- позиция указывает на конец ленты
        if (i >= input.size()) tape.Add_Cell(position, VOID);  // Проверка конца строки. Если конец, то добавляем пустую ячейку
        for (i; i < input.size();) {                        // Заменяем ячейки по выбранной позиции
            tape.Set_Cell(position, Get_Word(input, i));
            position++;
        }
    }
    else if (choice == REMOVE_CELL) {
        std::cout << "POSITION" << std::endl;
        std::cin >> input;                                          // Ввод значений
        int position = 0;
        try { tape.Remove_Cell(stoi(Get_Word(input, position))); }    // Пробуем передать позицию ячейки
        catch (...) { tape.Remove_Cell(); }                          // Если позиция не получена -- удаляется последняя ячейка
    }
    else if (choice == NEW_RULE) {
        std::cout << "STATE|WORD|NEWSTATE|NEWWORD|MOVE" << std::endl;
        std::cin >> input;                                              // Ввод значений
        New_Rule(input, rules);                                          //Добавление правила
    }
    else if (choice == REMOVE_RULE) {
        std::cout << "STATE|WORD" << std::endl;
        std::cin >> input;                                                  // Ввод значений
        bool error = true;
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '|') {                                      // Проверка корректности ввода
                i = 0;
                rules.Remove_Rule(Get_Word(input, i), Get_Word(input, i)); // Удаления правила
                error = false;
                break;
            }
        }
        if (error) std::cout << "Error: invalide argument..." << std::endl; // Если правило не удалось удалить
    }
    else if (choice == EDIT_HEAD) {
        std::cout << "STATE|POSITION" << std::endl;
        std::cin >> input;                          // Ввод значений
        Edit_Head(input, head, tape);                // Задаём свойства головки
    }
    else if (choice == VIEW_RULES) {
        std::cout << rules.View();                  // Вывод правил
    }
    else if (choice == VIEW_TAPE) {
        std::cout << tape.View(head);               // Вывод ленты
    }
    else if (choice == EXIT) { return true; }       // Конец программы
    else if (choice == HELP) std::cout << "Commands:\n\tGo\n\tAddCell\n\tSetCell\n\tRemoveCell\n\tNewRule\n\tRemoveRule\n\tEditHead\n\tViewTape\n\tViewRules\n\tHelp\n\tExit" << std::endl;
    else std::cout << "Input error..." << std::endl;    // Ввод других данных
    return false;
}