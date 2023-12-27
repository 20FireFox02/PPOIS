#include "pch.h"
#include "Schoolboy.hpp"

std::string Schoolboy::Answer(std::string question)
{
	for (int i = 0; i < knowledge.size(); i++) {
		if (knowledge[i].question == question) {
			std::cout << knowledge[i].answer;
			return knowledge[i].answer;
		}
	}
	std::cout << "I can't answer" << std::endl;
	return NO_ANSWER;
}

int Schoolboy::Learn(Knowledge knowledge)
{
	for (int i = 0; i < this->knowledge.size(); i++) {
		if (this->knowledge[i].question == knowledge.question) {
			if (this->knowledge[i].answer == knowledge.answer) {
				std::cout << "I know it";
				return 0;
			}
			this->knowledge[i] = knowledge;
			return 1;
		}
	}
	this->knowledge.push_back(knowledge);
	return 1;
}

bool Schoolboy::Get_Book(std::string name, Librarian librarian, Library& library)
{
	Book book(NO_ANSWER);
	std::cout << "Hello, do you have book " << name << " ?";
	book = librarian.Give_Book(name, library);
	if (book.name == NO_ANSWER) {
		std::cout << "Oh, ok";
		return false;
	}
	else {
		std::cout << "Thank you";
		literature.push_back(book);
		return true;
	}
}

std::string Schoolboy::Return_Book(std::string name, Librarian librarian, Library& library)
{
	for (int i = 0; i < literature.size(); i++) {
		if (literature[i].name == name) {
			librarian.Get_Book(literature[i], library);
			literature.erase(literature.begin() + i);
			return "I return book " + name;
		}
	}
	return NO_ANSWER;
}

std::string Schoolboy::Go_To_Canteen(std::string food, Cook cook)
{
	std::cout << food << " please" << std::endl;
	if (cook.Give_Food(food)) return "Thank you\n";
	else {
		std::string str;
		str += "Can you cook it?\n";
		cook.Cook_Food(food);
		str += "Thank you\n";
		return str;
	}

}

