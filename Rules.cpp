#include "Rules.hpp"

Rules::~Rules() {                                           //������� ������ ������� ������
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
    while (i < states.size() && state != states[i]) i++;                    // ���� ����� ��������� ������� ������� � ������� ���������
    if (i == states.size()) {                                               // ���� ������ ���
        states.push_back(state);                                            // ��������� ����� ��������� � ������
        table.push_back(std::vector <Action*>());
        for (int k = 0; k < words.size(); k++) table[i].push_back(NULL);    // ��������� ����� ������� � ������� ������
    }
    while (j < words.size() && word != words[j]) j++;                       // ���� ����� ����� ������� ������� � ������� ����
    if (j == words.size()) {                                                // ���� ������ ���
        words.push_back(word);                                              // ��������� ����� ����� � ������
        for (int k = 0; k < states.size(); k++) table[k].push_back(NULL);   // ��������� ����� ������ � ������� ������
    }
    if (table[i][j] != NULL) delete table[i][j];                            // ���� ������� ��� ������� ������ � ���������� ����������, �� ������� ���
    table[i][j] = new Action;                                               // ��������� ����� �������
    table[i][j]->Set_New_State(new_state);
    table[i][j]->Set_New_Word(new_word);
    if (move != R && move != L) table[i][j]->Set_Move(N);                    // ����� ������ ������, �� ������������ �������� ����� L ������ R, ������������� � �������� N
    else table[i][j]->Set_Move(move);
}
bool Rules::Remove_Rule(std::string word, std::string state) {
    int state_number = 0, word_number = 0;
    while (state_number < states.size() && state != states[state_number]) state_number++;   // ���� ����� ������� ��� ��������� � ������� ���������
    if (state_number == states.size()) return false;                                        // ���� ��� �� �������, �� ����������� ����� ������� ������� � ���������� false
    while (word_number < states.size() && word != words[word_number]) word_number++;        // ���� ����� ������� ��� ����� � ������� ����
    if (word_number == words.size()) return false;                                          // ���� ��� �� �������, �� ����������� ����� ������� ������� � ���������� false
    if (table[state_number][word_number] == NULL) return false;                             // ����� ������� ��� ������ ���������� � ������ ����������� -- ���������� false
    else {                                                                                  // ���� �������
        delete table[state_number][word_number];                                            //������� ������ �������
        table[state_number][word_number] = NULL;
        int i;
        for (i = 0; i < words.size(); i++) if (table[state_number][i] != NULL) break;       // ���� ������ ������� ��� ������ ����������
        if (i == words.size()) {                                                            // ���� ������ ���
            table.erase(table.begin() + state_number);                                      // ������� ������� ������� ��������� �� ������� ������
            states.erase(states.begin() + state_number);                                    // ������� ������ ��������� �� ������� ���������
        }
        for (i = 0; i < states.size(); i++) if (table[i][word_number] != NULL) break;       // ���� ������ ������� ��� ������ ������
        if (i == states.size()) {                                                           // ���� ������ ���
            for (i = 0; i < states.size(); i++) table[i].erase(table[i].begin() + word_number); // ������� ������ ������� ����� �� ������� ������
            words.erase(words.begin() + word_number);                                       // ������� ������ ����� �� ������� ����
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