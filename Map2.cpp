#include "Map2.h"

void Map2::SetRespTime(int n)
{
	if (n > 0)
	{
		time_resp_apple = n;
	}
}

int Map2::GetRespTime() const
{
	return time_resp_apple;
}

void Map2::SetApple(char symv)
{
	apple = symv;
}

char Map2::GetApple() const
{
	return apple;
}

void Map2::ShowMap(int number) const
{

	if (number == 1)
	{
		for (int i = 0; i < 44; i++)
		{
			for (int c = 0; c < 173; c++)
			{
				cout << map[i][c];
			}
			cout << endl;
		}
	}
	else
		if (number == 2)
		{
			for (int i = 0; i < 44; i++)
			{
				for (int c = 0; c < 173; c++)
				{
					cout << map2[i][c];
				}
				cout << endl;
			}
		}
		else
			if (number == 3)
			{
				for (int i = 0; i < 44; i++)
				{
					for (int c = 0; c < 173; c++)
					{
						cout << map3[i][c];
					}
					cout << endl;
				}
			}
}

char Map2::GetCurrentChar(int index, int index2, int current_map)
{
	if (current_map == 1)
	{
		return map[index2][index];
	}
	else
		if (current_map == 2) return map2[index2][index];
		else
			if (current_map == 3) return map3[index2][index];
}

void Map2::SetMap(int number)
{
	if (number < 4)
	{
		current_map = number;
	}
}

int Map2::GetMap() const
{
	return current_map;
}

void Map2::ChangeMap(int number)
{
	if (number < 4)
	{
		current_map = number;
		ShowMap(current_map);
	}
}

void Map2::ShowAplleOnMap()
{
	cin.clear();
	if (get_current_ticks >= time_resp_apple)
	{
		if (applex > 0 and appley > 0)
		{
			GotoXY(applex, appley);
			SetColor(6, 0);
			cout << " ";
		}
		int y = rand() % 44;
		int x = rand() % 173;
		char a = GetCurrentChar(x, y, current_map);
		while (a != ' ')
		{
			y = rand() % 44+1;
			x = rand() % 173+1;
			a = GetCurrentChar(x, y, current_map);
		}
		appley = y;
		applex = x;
		get_current_ticks = 0;
		GotoXY(x, y);
		SetColor(9, 0);
		cout << apple;
		SetColor(6, 0);
	}
	get_current_ticks++;
	if (applex > 0 and appley > 0)
	{
		GotoXY(applex, appley);
		SetColor(rand() % 15, 0);
		cout << apple;
	}
	else
	{
		int y = rand() % 44;
		int x = rand() % 173;
		char a = GetCurrentChar(x, y, current_map);
		while (a != ' ')
		{
			y = rand() % 44 + 1;
			x = rand() % 173 + 1;
			a = GetCurrentChar(x, y, current_map);
		}
		appley = y;
		applex = x;
		get_current_ticks = 0;
		GotoXY(x, y);
		SetColor(9, 0);
		cout << apple;
		SetColor(6, 0);
	}
}

void Map2::GotoXY(int x, int y)
{
	COORD coordinates;     // coordinates is declared as COORD
	coordinates.X = x;     // defining x-axis
	coordinates.Y = y;     //defining  y-axis
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void Map2::SetColor(int text, int background)
{

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));

}

Map2& Map2::operator=(const Map2& src)
{
	for (int i = 0; i < 44; i++)
	{
		for (int c = 0; c < 173; c++)
		{
			map[i][c] = src.map[i][c];
		}

	}
	return *this;
}

Map2::Map2(const Map2& src)
{
	for (int i = 0; i < 44; i++)
	{
		for (int c = 0; c < 173; c++)
		{

			map[i][c] = src.map[i][c];
		}

	}

}

Map2::Map2(int time_resp_apple, char apple,  int map)
{
 
	this->time_resp_apple = time_resp_apple;
	this->apple = apple;
	applex = 0;
	appley = 0;
	current_map = map;
	get_current_ticks = time_resp_apple;
}

ostream& operator<<(ostream& os, const Map2& src)
{
	src.ShowMap(src.current_map);
	return os;
}
