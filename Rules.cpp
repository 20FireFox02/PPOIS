#include "Rules.hpp"

Rules::~Rules() {                                           //ќчищаем пам€ть таблицы правил
    for (int i = 0; i < states.size(); i++)
        for (int j = 0; j < words.size(); j++)
            if (table[i][j] != NULL) delete table[i][j];
}
std::string Rules::Get_State(int number) const {
    return states[number];
}
std::string Rules::Get_Word(int number) const { return words[number]; }
int Rules::Get_Amount_Of_States() const { return states.size(); }
int Rules::Get_Amount_Of_Words() const { return words.size(); }
Action* Rules::Get_Rule(int state, int word) const { return table[state][word]; }
void Rules::New_Rule(char move, std::string new_word, std::string new_state, std::string word, std::string state) {
    int i = 0, j = 0;
    while (i < states.size() && state != states[i]) i++;                    // »щем номер состо€ни€ данного правила в векторе состо€ний
    if (i == states.size()) {                                               // ≈сли такого нет
        states.push_back(state);                                            // ƒобавл€ем новое состо€ние в вектор
        table.push_back(std::vector <Action*>());
        for (int k = 0; k < words.size(); k++) table[i].push_back(NULL);    // ƒобавл€ем новый столбец в таблицу правил
    }
    while (j < words.size() && word != words[j]) j++;                       // »щем номер слова данного правила в векторе слов
    if (j == words.size()) {                                                // ≈сли такого нет
        words.push_back(word);                                              // ƒобавл€ем новое слово в вектор
        for (int k = 0; k < states.size(); k++) table[k].push_back(NULL);   // ƒобавл€ем новую строку в таблицу правил
    }
    if (table[i][j] != NULL) delete table[i][j];                            // ≈сли правило под данными словом и состо€нием существует, то удал€ем его
    table[i][j] = new Action;                                               // ƒобавл€ем новое правило
    table[i][j]->Set_New_State(new_state);
    table[i][j]->Set_New_Word(new_word);
    if (move != R && move != L) table[i][j]->Set_Move(N);                    // Ћюбой другой символ, не обозначающий движение влево L вправо R, преобразуетс€ в остатьс€ N
    else table[i][j]->Set_Move(move);
}
bool Rules::Remove_Rule(std::string word, std::string state) {
    int state_number = 0, word_number = 0;
    while (state_number < states.size() && state != states[state_number]) state_number++;   // »щем номер нужного нам состо€ни€ в векторе состо€ний
    if (state_number == states.size()) return false;                                        // ≈сли его не находим, то заканчиваем поиск нужного правила и возвращаем false
    while (word_number < states.size() && word != words[word_number]) word_number++;        // »щем номер нужного нам слова в векторе слов
    if (word_number == words.size()) return false;                                          // ≈сли его не находим, то заканчиваем поиск нужного правила и возвращаем false
    if (table[state_number][word_number] == NULL) return false;                             // ≈лсли правила под данным состо€нием и словом отсутствует -- возвращаем false
    else {                                                                                  // ≈сли находим
        delete table[state_number][word_number];                                            //”дал€ем данное правило
        table[state_number][word_number] = NULL;
        int i;
        for (i = 0; i < words.size(); i++) if (table[state_number][i] != NULL) break;       // »щем другие правила под данным состо€нием
        if (i == words.size()) {                                                            // ≈сли такого нет
            table.erase(table.begin() + state_number);                                      // ”дал€ем столбец данного состо€ни€ из таблицы правил
            states.erase(states.begin() + state_number);                                    // ”дал€ем данное состо€ние из вектора состо€ний
        }
        for (i = 0; i < states.size(); i++) if (table[i][word_number] != NULL) break;       // »щем другие правила под данным словом
        if (i == states.size()) {                                                           // ≈сли такого нет
            for (i = 0; i < states.size(); i++) table[i].erase(table[i].begin() + word_number); // ”дал€ем строку данного слова из таблицы правил
            words.erase(words.begin() + word_number);                                       // ”дал€ем данное слово из вектора слов
        }
    }
    return true;
}
std::string Rules::View() const {
    std::string str = "";
    for (int i = 0; i < states.size(); i++) {
        for (int j = 0; j < words.size(); j++) {
            if (table[i][j] == NULL) str += "VOID\t\t\t";
            else {
                str += states[i] + "|" + words[j] + "->" + table[i][j]->Get_New_State() + "|" + table[i][j]->Get_New_Word() + "|" + table[i][j]->Get_Move() + "\t\t";
            }
        }
        str += '\n';
    }
    return str;
}