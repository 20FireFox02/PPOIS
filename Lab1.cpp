// Lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Interface.hpp"

int main()
{
    Head head;
    Tape tape;
    Rules rules;
    std::string path;
    do {
        std::cout << "Input the path to the file:\t";
        std::cin >> path;
    } while (!Loading_From_File(path, head, tape, rules));
    std::string choice;
    std::cout << "Commands:\n\tGo\n\tAddCell\n\tSetCell\n\tRemoveCell\n\tNewRule\n\tRemoveRule\n\tEditHead\n\tViewTape\n\tViewRules\n\tHelp\n\tExit" << std::endl;
    while (true) {
        std::cout << "Input" << std::endl;
        std::cin >> choice;
        if (Interface(head, tape, rules, choice)) return 0;
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
