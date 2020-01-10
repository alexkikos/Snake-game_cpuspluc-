#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;


class GameButton
{
	int xpos;
	int ypos;
	int width;
	int length;
	string text;
	char button_symvol;
	int color_text;
	int text_x_indent;
	int text_y_indent;
	int color_background;
	void SetColor(int text, int background);
public:

	void GotoXY(int x, int y);
	void SetXpos(int x);
	int GetXpos() const;

	void SetYpos(int y);
	int GetYpos() const;

	void SetWidth(int width);
	int GetWidth() const;

	void SetLength(int length);
	int GetLength() const;


	void SetText(string src);
	string Text() const;

	void SetColorText(int color);
	int GetColorText() const;

	void SetColorBackground(int back_color);
	int GetColorBackground() const;



	void SetXindent(int n);
	int GetXindent() const;

	void SetYindent(int n);
	int GetYindent() const;


	void ShowButton();
	//����, ����, ����, �����_�, ������_�, ������, �����, ����� ����, ���� ���
	GameButton(const char*, char button_symvol, int xpos, int ypos, int text_x_pos, int text_y_pos, int width, int length, int color_text, int color_background);
	GameButton() = default;
	~GameButton() = default;
};

