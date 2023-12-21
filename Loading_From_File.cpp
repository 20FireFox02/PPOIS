#include "Loading_From_File.hpp"

bool Edit_Head(std::string str, Head& head, Tape& tape) {
    int position = 0;
    head.Set_State(Get_Word(str, position));                      // Указываем состояние головки из строки
    if (position >= str.size()) {                               // Если строка полностью пройдена
        head.Set_Position(0);                                    // Позиция головки приравнивается нулю
        return false;
    }
    else {
        try { head.Set_Position(stoi(Get_Word(str, position))); } // Пробуем указать позицию головки
        catch (...) {                                           // Если это не получилось
            head.Set_Position(0);                                // Позиция головки приравнивается нулю
            return false;
        }
    }
    if (head.Get_Position() < 0) {                               // Если позици головки меньше нуля
        tape.Add_Cell(head.Get_Position(), VOID);                   // Редактируем нашу ленту
        head.Set_Position(0);                                    // Позиция головки приравнивается нулю
    }
    else if (head.Get_Position() >= tape.Get_Size()) { tape.Add_Cell(head.Get_Position(), VOID); } // Редактируем нашу ленту
    return true;
}

bool New_Rule(std::string str, Rules& rules) {
    int amount = 0, tmp = 0;
    for (int i = 0; i < str.size(); i++) {
        if (amount == 4) {                          // Проверяем корректность ввода
            rules.New_Rule(str[tmp], Get_Word(str, tmp), Get_Word(str, tmp), Get_Word(str, tmp), Get_Word(str, tmp)); // Добавление правила
            amount = 0;
            i++;
            tmp = i;
        }
        if (str[i] == '|') amount++;                // Подсчёт количества разграничителей
    }
    if (amount == 0) return true;                   // Проверка "отрубков" от строки
    return false;
}
std::string Get_Word(std::string str, int& position) {
    std::string word = VOID;
    while (str[position] == ' ') position++;                    // Игнорируем пробелы в начале слова

    while (position < str.size() && str[position] != '|') {     // Покуда не дойдём до конца строки или символа разграничителя
        word += str[position];                                  // Записываем слово
        position++;
    }
    position++;
    return word;                                                // Возвращаем полученное слово
}
bool Loading_From_File(std::string file_name, Head& head, Tape& tape, Rules& rules)
{
    std::ifstream file(file_name);                                      // Открываем файл
    if (!file) {                                                        // Если данного файла не существует
        std::cout << "Error: such file do not exsist..." << std::endl;
        return false;
    }
    std::string str;
    std::getline(file, str);
    for (int i = 0; i < str.size();) tape.Add_Cell(Get_Word(str, i));     // Создаём ленту из файла
    std::getline(file, str);
    Edit_Head(str, head, tape);                                          // Создаём головку из файла
    std::getline(file, str);
    New_Rule(str, rules);                                                // Создаём правила из файла
    file.close();
    return true;
}