#include "Snake.h"



bool Snake::CheckCollision()
{

	char a = map.GetCurrentChar(coorx, coory, map.current_map);
	if (coorx == map.applex and coory == map.appley)
	{
		AddSizeSnake();
		UpdateMapInfo();
		map.applex = 0;
		map.appley = 0;
	}
	else
		if (a == '#' or a == '=')
		{
			hp_points = 0;
		}
		else
			if (a != ' ')
			{
				hp_points--;
				UpdateMapInfo();
			}
			else
				return true;
}

void Snake::ShowApple()
{
	UpdateTicksApple();
	map.ShowAplleOnMap();
}

void Snake::UpdateMapInfo()
{
	bhp.GotoXY(bhp.GetXpos() + bhp.GetLength() + 1, bhp.GetYpos() + 1);
	cout << hp_points;
	blength.ShowButton();
	bhp.GotoXY(blength.GetXpos() + blength.GetLength() + 1, blength.GetYpos() + 1);
	cout << length;

	bspeed.ShowButton();
	bhp.GotoXY(bspeed.GetXpos() + bspeed.GetLength() + 1, bspeed.GetYpos() + 1);
	cout << speed;
	if (bspeed.GetLength() > 2) cout << "  ";


}

void Snake::UpdateTicksApple()
{
	btimetochange.ShowButton();
	btimetochange.GotoXY(btimetochange.GetXpos() + btimetochange.GetLength() + 1, bspeed.GetYpos() + 1);
	cout << map.time_resp_apple - map.get_current_ticks;
	cout << "   ";
}



void Snake::AddSizeSnake()
{
	char* temp = new char[length + 1];
	for (int i = 0; i < length + 1; i++)
	{
		temp[i] = snake_syvol;
	}
	delete[] snake;
	snake = temp;
	length++;
	AddCoord(coorx, coory);

}

void Snake::SetHead(char s)
{
	if (s < 126) head = s;
	else head = '#';
}

char Snake::GetHead() const
{
	return head;
}

void Snake::ChangePosition(string s)
{
	int tempx = coorx;
	int tempy = coory;
	if (s == "d")
	{
		coorx++;
	}
	else
		if (s == "a")
		{
			coorx--;
		}
		else
			if (s == "s")
			{
				coory++;
			}
			else
				if (s == "w")
				{

					coory--;
				}

	map.GotoXY(coorx, coory);
	cout << head;
	CheckCollision();
	RemoveLastCoord();
	coord[current][0] = tempx;
	coord[current][1] = tempy;
	map.GotoXY(coord[current][0], coord[current][1]);
	cout << snake[current];
	current++;
	if (current == length)
	{
		current = 0;
	}
	Sleep(speed);
}



void Snake::Clear()
{
	if (sizecoord > length)	RemoveLastCoord();
}

void Snake::AddCoord(int x, int y)
{
	int** temp;
	temp = new int* [sizecoord + 1];
	for (int i = 0; i < sizecoord+1; i++)
	{
		temp[i] = new int[2];
	}
	for (int i = 0; i < sizecoord; i++)
	{
		temp[i] = coord[i];
	}
	temp[sizecoord][0] = x;
	temp[sizecoord][1] = y;
	delete[] coord;	
	coord = temp;
	sizecoord++;

}

void Snake::RemoveLastCoord()
{

	map.GotoXY(coord[current][0], coord[current][1]);
	cout << " ";
}



void Snake::SetSnake(int size)
{
	length = size;
	if (length > 1) delete[] snake;
	snake = new char[length];
	for (int i = 0; i < length; i++)
	{
		snake[i] = snake_syvol;
	}
}

char& Snake::GetSnake() const
{
	return *snake;
}

void Snake::SetLength(int size)
{
	length = size;
}

int Snake::GetLength() const
{
	return length;
}

void Snake::SetCoorX(int coor)
{
	if (coor >= 0)
	{
		coorx = coor;
	}
}

int Snake::GetCoorX() const
{
	return coorx;
}

void Snake::SetCoorY(int coor)
{
	if (coor >= 0)
	{
		coory = coor;
	}
}

int Snake::GetCoorY() const
{
	return coory;
}

void Snake::Speed(int speed)
{
	if (speed > 0)
	{
		this->speed = speed;
	}
}

int Snake::GetSpeed() const
{
	return speed;
}

void Snake::SetSizeCoord(int size)
{
	if (size > 0)
	{
		sizecoord = size;
	}
}

int Snake::GetSizeCoord() const
{
	return sizecoord;
}

void Snake::SetSymvolSnake(char symv)
{
	if (symv < 128 and symv >= 0)
	{
		snake_syvol = symv;
	}
}

char Snake::GetSymvolSnake() const
{
	return snake_syvol;
}

void Snake::SetHp(int hp)
{
	if (hp > 0) hp_points = hp;
	else hp = 3;
}

int Snake::GetHp() const
{
	return hp_points;
}






Snake::Snake(int length, int coorx, int coory, int speed, char snake_symv, char head, int hp)
{
	this->sizecoord = length;
	hp_points = hp;
	this->head = head;
	current = 0;
	this->coorx = coorx;
	this->coory = coory;
	this->speed = speed;
	map.GotoXY(0, 0);
	int color;
	int randmap = rand() % 3+1;
	do
	{
		color = rand() % 14 + 1;
	} while (color == 0 or color == 7 or color == 8);
	map.SetColor(color, 0);
	map.SetMap(randmap);
	map.ShowMap(map.current_map);
	map.SetColor(6, 0);
	this->snake_syvol = snake_symv;
	coord = new int* [length];
	for (int i = 0; i < length; i++)
	{
		coord[i] = new int[2];
	}
	this->length = length;
	snake = new char[length];
	for (int i = 0; i < length; i++)
	{
		snake[i] = snake_syvol;
		map.GotoXY(coorx, this->coory);
		coord[i][0] = coorx;
		coord[i][1]  = this->coory;
		cout << snake[i];
		this->coory++;

	}
	map.GotoXY(coorx, this->coory);
	cout << head;

	//текс, хпос, упос, отсуп_х, отступ_н, ширина, длина, текст цвет, цвет бек
	bhp = { "Current HP", '#', 5,45, 1,1, 3, 12, 10,4 };
	blength = { "Score", '#', 25,45, 1,1, 3, 7, 11,5 };
	bspeed = { "Snake speed", '#', 38,45, 1,1, 3, 13, 12,1 };
	baddspeed = { "ADD/Lowest speed: i/o", '#', 58,45, 1,1, 3, 23, 10,4 };
	syspause = { "Pause: p", '#', 85,45, 1,1, 3, 11, 13,9 };
	show_menu = { "Menu: ESC", '#', 100,45, 1,1, 3, 11, 13,14 };
	btimetochange = { "Time to Change Apple pos: ", '#', 115,45, 1,1, 3, 28, 14,3 };
	bhp.ShowButton();
	bhp.GotoXY(bhp.GetXpos() + bhp.GetLength() + 1, bhp.GetYpos() + 1);
	cout << hp_points;
	blength.ShowButton();
	bhp.GotoXY(blength.GetXpos() + blength.GetLength() + 1, blength.GetYpos() + 1);
	cout << this->length;

	bspeed.ShowButton();
	bhp.GotoXY(bspeed.GetXpos() + bspeed.GetLength() + 1, bspeed.GetYpos() + 1);
	cout << this->speed;

	baddspeed.ShowButton();
	syspause.ShowButton();
	show_menu.ShowButton();
	btimetochange.ShowButton();
	btimetochange.GotoXY(btimetochange.GetXpos() + btimetochange.GetLength() + 1, btimetochange.GetYpos() + 1);
	cout << map.get_current_ticks;

}


Snake::~Snake()
{
	delete[] snake;
	for (int i = 0; i < sizecoord; i++)
	{
		delete[] coord[i];
	}
	delete[] coord;
}


