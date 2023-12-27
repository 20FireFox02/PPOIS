#include "pch.h"
#include "Director.hpp"
Subject math("math");
Subject english("english");
Subject history("history");
School school("12", "Where", 2023);
Equipment computer("computer");

TEST(TheacherTest, Question_CorrectAnswer_ReturnUn) {
	Knowledge q(math, "what is x", "x is 5", 3);
	Schoolboy s("Mish", "Dojdev", 7);
	Cabinet c("2");
	Theacher e("a", "c", 23, c, 2, math);
	Theacher t("Gricha", "Turuk", 43, c, 205, math);
	s.knowledge.push_back(q);
	t.knowledge.push_back(q);
	EXPECT_EQ(t.Ask_A_Question(s, "what is x", school), 1);
}

TEST(TheacherTest, Question_IncorrectAnswer_ReturnNull) {
	Knowledge correct_knowledge(history, "start of the WW2", "1939", 3), incorrect_knowledge(history, "start of the WW2", "1941", 3);
	Schoolboy s("Mish", "Dojdev", 7);
	Cabinet c("2");
	Theacher t("Svetlana", "Violetova", 29, c, 212, history);
	s.knowledge.push_back(incorrect_knowledge);
	t.knowledge.push_back(correct_knowledge);
	EXPECT_EQ(t.Ask_A_Question(s, "start of the WW2", school), 0);
}

TEST(TheacherTest, Theach_TheachingClass_UsefulIsFull) {
	Knowledge correct_knowledge(history, "start of the WW2", "1939", 3), incorrect_knowledge(history, "start of the WW2", "1941", 3);
	Class school_class;
	Schoolboy s1("Mish", "Dojdev", 7);
	Schoolboy s2("Katiy", "Korneeva", 8);
	Cabinet c("2");
	Theacher t("Svetlana", "Violetova", 29, c, 212, history);
	s1.knowledge.push_back(incorrect_knowledge);
	school_class.students.push_back(s1);
	school_class.students.push_back(s2);
	t.knowledge.push_back(correct_knowledge);
	EXPECT_EQ(t.Theach("start of the WW2", school_class), 1);
}

TEST(SchoolboyTest, Go_To_Canteen) {
	Cabinet q("2");
	Schoolboy s("Misha", "Sidorov", 12);
	Equipment t("sandwich");
	q.inventory.push_back(t);
	t.name = "dss";
	q.inventory.push_back(t);
	Cook c("Cricha", "Turuk", 43, q, 43);
	EXPECT_EQ(s.Go_To_Canteen("sandwich", c), "Thank you\n");
}

TEST(SchoolboyTest, Book_GetBook_ReturnTrue) {
	Library library("12");
	Book book("Supermath");
	library.literature.push_back(book);
	Schoolboy s("Misha", "Sidorov", 12);
	Librarian librarian("Cricha", "Turuk", 43, library, 203);
	EXPECT_EQ(s.Get_Book("Supermath", librarian, library), true);
}

TEST(SchoolboyTest, Book_GetBook_ReturnFalse) {
	Library library("12");
	Schoolboy s("Misha", "Sidorov", 12);
	Librarian librarian("Cricha", "Turuk", 43, library, 203);
	EXPECT_EQ(s.Get_Book("Supermath", librarian, library), false);
}

TEST(SchoolboyTest, Book_GiveBook_ReturLineAndBookName) {
	Library library("12");
	Book book("Supermath");
	Schoolboy s("Misha", "Sidorov", 12);
	s.literature.push_back(book);
	Librarian librarian("Cricha", "Turuk", 43, library, 203);
	EXPECT_EQ(s.Return_Book("Supermath", librarian, library), "I return book Supermath");
}

TEST(DirectorTest, Fire_StaffBadWork_PersonIsFired) {
	Cabinet q("2");
	Director d("Boriy", "Serov", 50, q, 400, math);
	Theacher t("Leha", "Qrivoy", 34, q, 200, history);
	school.staff.push_back(t);
	EXPECT_EQ(d.Fire(t, school), "Leha Qrivoy you are fired");
}

TEST(DirectorTest, Fire_StaffBadWork_ThereIsNotPerson) {
	Cabinet q("2");
	Director d("Boriy", "Serov", 50, q, 400, math);
	Theacher t("Leha", "Qrivoy", 34, q, 200, history);
	EXPECT_EQ(d.Fire(t, school), "Who?");
}

TEST(DirectorTest, Hire_StaffBadWork_PersonIsHiredAsTheacher) {
	Cabinet q("2");
	Director d("Boriy", "Serov", 50, q, 400, math);
	Person t("Leha", "Qrivoy", 34);
	d.Hire(t, school, english, 200, q);
	EXPECT_EQ(school.staff[school.staff.size() - 1].name, "Leha");
	EXPECT_EQ(school.staff[school.staff.size() - 1].surname, "Qrivoy");
}

TEST(DirectorTest, Hire_StaffBadWork_PersonIsHiredAsCook) {
	Cabinet q("2");
	Director d("Boriy", "Serov", 50, q, 400, math);
	Person t("Jora", "Molotov", 25);
	d.Hire(t, school, 0, 200, q);
	EXPECT_EQ(school.staff[school.staff.size() - 1].name, "Jora");
	EXPECT_EQ(school.staff[school.staff.size() - 1].surname, "Molotov");
}

TEST(DirectorTest, Buy_BuyEquipment_NoBudget) {
	Cabinet q("2");
	Director d("Boriy", "Serov", 50, q, 400, math);
	Person t("Jora", "Molotov", 25);
	school.budget = 643;
	d.Hire(t, school, 0, 200, q);
	EXPECT_EQ(d.Buy_Equipment(computer, 500, school.cabinets[2], school), false);
}

TEST(DirectorTest, Salary_Salary_NoBudget) {
	Cabinet q("2");
	Director d("Boriy", "Serov", 50, q, 400, math);
	Person t("Jora", "Molotov", 25);
	school.budget = 394;
	EXPECT_EQ(d.Salary(school), false);
}

TEST(WachmanTest, Salary_Salary_NoBudget) {
	Watchman w("Vera", "Utugova", 34, school.cabinets[0], 132);
	school.day = 3;
	school.state = BREAK;
	school.lesson_number = 4;
	w.Pull_A_Bell(school);
	EXPECT_EQ(school.day == 3, true);
	EXPECT_EQ(school.state == LESSON, true);
	EXPECT_EQ(school.lesson_number == 5, true);
}

int main(int argc, char** argv) {
	Cabinet w("0"), canteen("1"), classroom1("101"), classwroom2("102");
	Library library("2");
	school.cabinets.push_back(w);
	school.cabinets.push_back(canteen);
	school.cabinets.push_back(library);
	school.cabinets.push_back(classroom1);
	school.cabinets.push_back(classwroom2);
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}