#include "pch.h"
#include "Header.h"
#include "LoadingFromFile.h"
#include "Execution.h"

TEST(LoadingFromFileTest, OpenFile_InvalideFileName_ReturnFalse) {	
	rules r;
	head h;
	tape t;
  EXPECT_EQ(LoadingFromFile("D:\\3.txt", h, t, r), false);
}

TEST(LoadingFromFileTest, GetWord_InputStringOfSomeWords_GetSecondWord) {
	std::string s = "Word|    SecondWord|word";
	int i = 0;
	GetWord(s, i);
	EXPECT_EQ(GetWord(s, i), "SecondWord");
}

TEST(LoadingFromFileTest, ReadingHeadPosition_InvalideValue_PositionIsNULL) {
	rules r;
	head h;
	tape t;
	LoadingFromFile("Position.txt", h, t, r);
	EXPECT_EQ(h.GetPosition(), 0);
}

TEST(HadeTest, InputPosition_InputPosition_ReturnTrue) {
	head h;
	EXPECT_EQ(h.SetPosition(4), true);
}

TEST(HadeTest, InputState_InputState_ReturnTrue) {
	head h;
	EXPECT_EQ(h.SetState("state"), true);
}

TEST(HadeTest, GetPosition_InputPosition_Return4) {
	head h;
	h.SetPosition(4);
	EXPECT_EQ(h.GetPosition(), 4);
}

TEST(HadeTest, GetState_InputState_Returnstate) {
	head h;
	h.SetState("state");
	EXPECT_EQ(h.GetState(), "state");
}

TEST(TapeTest, RemoveCell_RemoveFirstCell_FirstCellWasBeenSeconde) {
	tape t;
	t.AddCell("remove");
	t.AddCell("first");
	EXPECT_EQ(t.RemoveCell(0), true);
	EXPECT_EQ(t.GetCell(0), "first");
}

TEST(TapeTest, RemoveCell_RemoveNotExistingCell_ReturnFalse) {
	tape t;
	t.AddCell("first");
	EXPECT_EQ(t.RemoveCell(6), false);
}

TEST(TapeTest, AddCell_AddCellByPosition_GetWord) {
	tape t;
	t.AddCell(4, "Word");
	EXPECT_EQ(t.GetCell(4), "Word");
}

TEST(TapeTest, SetCell_AddCellByExistPosition_GetNewWord) {
	tape t;
	t.AddCell(2, "OldWord");
	t.SetCell(2, "NewWord");
	EXPECT_EQ(t.GetCell(2), "NewWord");
}

TEST(TapeTest, GetCell_GetCellByNotExistPosition_GetVoidString) {
	tape t;
	EXPECT_EQ(t.GetCell(-3), "");
}

TEST(RulesTest, AddRule_AddNewRule_NewWord) {
	rules r;
	r.NewRule('R', "NewW", "NewS", "OldW", "OldS");
	EXPECT_EQ(r.GetRule(0, 0)->GetNewWord(), "NewW");
}

TEST(RulesTest, AddRule_AddNewRuleToExistingRule_NewState) {
	rules r;
	r.NewRule('L', "OldW", "OldS", "OldW", "OldS");
	r.NewRule('R', "NewW", "NewS", "OldW", "OldS");
	EXPECT_EQ(r.GetRule(0, 0)->GetNewState(), "NewS");
}

TEST(RulesTest, RemoveRule_RemoveExistingRule_Returntrue) {
	rules r;
	r.NewRule('L', "OldW", "OldS", "OldW", "OldS");
	EXPECT_EQ(r.RemoveRule("OldW", "OldS"), true);
}

TEST(RulesTest, RemoveRule_RemoveNotExistingRule_ReturnFalse) {
	rules r;
	r.NewRule('L', "Old", "Old", "Old", "Old");
	EXPECT_EQ(r.RemoveRule("Other", "Other"), false);
}
/*
TEST(Execution, Travel_TravelIsMoreThem2_ReturnFalse) {
	rules r;
	head h;
	tape t;
	h.SetPosition(0);
	h.SetState("Stand");
	t.AddCell("Cicle");
	r.NewRule('N', "Cicle", "Stand", "Cicle", "Stand");
	EXPECT_EQ(Execution(h, t, r), false); //Количество шагов уменьшено до 2, так как выполнение теста при количестве шагов 100 займёт  более 3 минут
}

TEST(Head, NewPosition_PositionLessThanNULL_PositionIsNull) {
	tape t;
	t.AddCell("remove");
	t.AddCell("first");
	EXPECT_EQ(t.RemoveCell(0), true);
	EXPECT_EQ(t.GetCell(0), "first");
}
*/

//TEST(TestCaseName, T) {
//	head h;
//	h.SetState("q");
//	EXPECT_EQ(h.GetPosition(), "q");
//}