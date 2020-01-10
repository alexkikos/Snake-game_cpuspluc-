#pragma once
#include "GameButton.h"
#include <conio.h>
#include "Snake.h"


using namespace std;
class Menu
{

	GameButton newgame, stat, snake_speed, enter_name, b1, b2, b3;
	int current_pos;
	string strelka;
	string strelka2;
	string user;
	int speed;
	bool first;
	///////////////////////////////////////////////////////////////
	void SetColor(int text, int background);
	void SetCurrentPos(int n);
	int GetCurrenPos() const;
	void SetStrelka1(const char* a);
	string GetStrelka1() const;
	void SetStrelka2(const char* a);
	string GetStrelka2() const;
	void SetFirstStart(bool first = false);
	bool GetFirstStartStatus() const;
	void SetUser(string str);
	string GetUser() const;
	int SwitchMenu();
	void ClearPosition();
	void CleArea();
	void Show();
	void AddUser();
	void SetMenuSnakeSpeed(int n);
	int GetMenusSnakeSpeed() const;
	void ClearMenusSpeed(int cur);
	void MenuChangeSpeed();
	void SaveResults(string name, int speed, int length) const;
	void LoadResults();
	void AddRes(string*& s, string name, int& size);
	void AddRes2(int**& s, int& rows,  int sp, int ln);
	void GotoXy(int x, int y);
	void Sort(string* names, int size_names, int** users, int s_rows);
	//////////////////////////////////////////////////////////
public:
	bool StartGame();
	Menu();

};

