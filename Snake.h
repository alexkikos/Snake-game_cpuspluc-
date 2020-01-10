#pragma once
#include <iostream>
#include "Map2.h"
#include "GameButton.h"
#include <Windows.h>
#include <string>
#include <conio.h>
#include <fstream>
using namespace std;

class Snake
{
	GameButton bspeed, blength, bhp, baddspeed, syspause, show_menu, btimetochange;
	Map2 map;	
	char head;
	int current;
	char* snake;
	char snake_syvol;
	int length;
	int** coord;//храню координаты х у
	int sizecoord;
	int coorx;
	int coory;
	int speed;
	int hp_points;
	void Clear();	
	void AddCoord(int x, int y);
	void RemoveLastCoord();
	void AddSizeSnake();
public:
	void SetHead(char s);
	char GetHead() const;
	void ChangePosition(string s);
	void SetSnake(int size);
	char& GetSnake() const;
	void SetLength(int size);
	int GetLength() const;
	void SetCoorX(int coor);
	int GetCoorX() const;
	void SetCoorY(int coor);
	int GetCoorY() const;
	void Speed(int coor);
	int GetSpeed() const;	
	void SetSizeCoord(int size);
	int GetSizeCoord() const;
	void SetSymvolSnake(char symv);
	char GetSymvolSnake() const;

	void SetHp(int hp);
	int GetHp() const;

	bool CheckCollision();
	void ShowApple();
	void UpdateMapInfo();
	void UpdateTicksApple();	

	explicit Snake(int length = 3,  int coorx=5, int coory=5, int speed = 65, char snake_syvol= '#', char head ='@', int hp = 3);
	Snake(const Snake& src) = delete;
	Snake(const Snake&& src) = delete;
	Snake& operator = (const Snake &src) = delete;
	~Snake();

};

