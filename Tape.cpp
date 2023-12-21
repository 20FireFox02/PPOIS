#include "Tape.hpp"
void Tape::Add_Cell(std::string word) { cells.push_back(word); }
void Tape::Add_Cell(int position, std::string word) {
    Search(position);                                           // ����� ������ �������
    cells.insert(cells.begin() + position, word);
}
bool Tape::Remove_Cell() {
    if (cells.size() == 0) return false;                        // ��������� ����
    cells.pop_back();
    return true;
}
bool Tape::Remove_Cell(int position) {
    if (position < 0 || position >= cells.size()) return false; // ��������� ����
    else cells.erase(cells.begin() + position);
    return true;
}
void Tape::Set_Cell(int position, std::string word) {
    Search(position);                                           // ����� ������ �������
    cells[position] = word;
}
std::string Tape::Get_Cell(int position) const {
    if (position < 0 || position >= cells.size()) return VOID;    // ���� ������� ������� �� ��������� �����, �� ���������� VOID
    return cells[position];
}
int Tape::Get_Size() const { return cells.size(); }
std::string Tape::View(Head head) const {
    std::string str = "|";
    for (int i = 0; i < head.Get_Position(); i++) str += " " + cells[i] + " |";                  // ������� ��� ������ �� ������� �������
    str += " " + cells[head.Get_Position()] + " < " + head.Get_State() + " |";                    // ������� ������ �� ������� ������� � �������
    for (int i = head.Get_Position() + 1; i < cells.size(); i++) str += " " + cells[i] + " |";   // ������� ���������� ������
    str += '\n';
    return str;
}
void Tape::Search(int& position) {
    int size = cells.size();
    while (size < position) {               //������ ������� ������� ������ �����, ��������� ������ � �����
        cells.push_back(VOID);
        size++;
    }
    while (position < 0) {                  //������ ������� ������� ������ ����, ��������� ������ � ������
        cells.insert(cells.begin(), VOID);
        position++;
    }
}