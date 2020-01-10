#include "Menu.h"

void Menu::MenuChangeSpeed()
{
	system("cls");

	int cur = 1;
	b1.ShowButton();
	b2.ShowButton();
	b3.ShowButton();
Start1:

	if (cur == 1)
	{
		b1.GotoXY(b1.GetXpos() - strelka.length() - 1, b1.GetYpos() + 1);
		SetColor(rand() % 15, 0);
		cout << strelka;
		b1.GotoXY(newgame.GetXpos() + b1.GetLength() + 1, b1.GetYpos() + 1);
		b1.SetColorText(rand() % 15);
		cout << strelka2;
	}
	else
		if (cur == 2)
		{
			SetColor(rand() % 15, 0);
			b2.GotoXY(b1.GetXpos() - strelka.length() - 1, b2.GetYpos() + 1);
			cout << strelka;
			b2.GotoXY(newgame.GetXpos() + b2.GetLength() + 1, b2.GetYpos() + 1);
			cout << strelka2;
		}
		else
			if (cur == 3)
			{
				SetColor(rand() % 15, 0);
				b3.GotoXY(b1.GetXpos() - strelka.length() - 1, b3.GetYpos() + 1);
				cout << strelka;
				b3.GotoXY(newgame.GetXpos() + b3.GetLength() + 1, b3.GetYpos() + 1);
				cout << strelka2;
			}

	char g = '1';
	do
	{


		if (_kbhit())
		{

			g = _getch();
			switch (g)
			{
			case 's': ClearMenusSpeed(cur); cur++; break;
			case 'w':  ClearMenusSpeed(cur); cur--; break;
			}

			if (cur > 3) cur = 1;
			else if (cur < 1) cur = 3;
			if (g != 27 and g != 13) goto Start1;
		}

	} while (g != 27 and g != 13);



	if (cur == 1) speed = 70;
	else
		if (cur == 2) speed = 60;
		else
			if (cur == 3) speed = 45;

	ClearMenusSpeed(cur);
	Show();
	SwitchMenu();
}

void Menu::SaveResults(string name, int speed, int length) const
{
	ofstream save("userd.dat", ios::app);
	if (save.is_open())
	{
		save << name << " " << speed << " " << length << endl;
	}
	save.close();
}

void Menu::LoadResults()
{
	system("cls");
	int max_length = 0;
	int count = 0;
	string* names = nullptr;
	int** resul = nullptr;
	int row = 0;
	int size = 0;
	ifstream load("userd.dat");
	if (load.is_open())
	{
		while (!load.eof())
		{
			string s;
			int a, b;
			load >> s >> a >> b;
			if (s.length() > 0)
			{
				AddRes(names, s, size);
				AddRes2(resul, row, a, b);
				if (s.length() >= max_length)
				{
					max_length = s.length();
				}
			}

		}
	}
	load.close();
	int count_max = 0;
	int tmp = row;
	while (tmp != 0)
	{
		tmp /= 10;
		count_max++;
	}
	GotoXy(62, 1);
	SetColor(11, 0);
	cout << "Press \"ESC\" back to menu\n";
	GotoXy(62, 2);
	Sort(names, size, resul, row);
	(row > 44) ? row = 44 : row = row;
	for (int i = 0; i <= row+3; i++)
	{

		if (i < 3 or i == row+3)
		{
			if (i < 3)
			{
				for (int c = 0; c < max_length + 22+ count_max; c++)
				{
					if (i == 0 or i + 1 == 3 or c == 0)
					{
						cout << "#";
					}
					else
						if (i == 1 and c == max_length / 2 - 4+ count_max+2)
						{
							cout << "User name";
							c += 10;
						}
						else
							if (i == 1 and c == max_length + 2+ count_max+3) cout << " #" << " Speed " << "# Length #";
							else
								cout << " ";
				}
			}
			else
			{
				for (int c = 0; c < max_length + 22+ count_max; c++)
				{

					cout << "#";
				}

			}

		}
		else
		{
			if (names[i-3] == user) SetColor(6, 0);
			GotoXy(62, 2 + i);
			cout << "# " << i-2<< ". "<<  names[i-3];
			GotoXy(62 + max_length + 1+ count_max+3, 2 + i);
			cout << "#";
			GotoXy(62 + max_length + 4+ count_max+3, 2 + i);
			cout << resul[i-3][0];
			GotoXy(62 + max_length + 9+ count_max+3, 2 + i);
			cout << "#";
			GotoXy(62 + max_length + 13+ count_max+3, 2 + i);
			cout << resul[i-3][1];
			GotoXy(62 + max_length + 8 + 10+ count_max+3, 2 + i);
			cout << "#";
			SetColor(11, 0);
		}
		GotoXy(62, i+3);
	}
	char a;
	do
	{
		a = _getch();

	} while (a != 27);

	system("cls");

}

void Menu::AddRes(string*& s, string name, int& size)
{
	if (s == nullptr)
	{
		s = new string[1];
		size++;
		s[0] = name;
		return;
	}
	else
	{
		string* temp = new string[size + 1];
		for (int i = 0; i < size; i++)
		{
			temp[i] = s[i];
		}
		temp[size] = name;
		size++;
		delete[] s;
		s = temp;
	}
}

void Menu::AddRes2(int**& s, int& rows, int sp, int ln)
{
	if (s == nullptr)
	{
		s = new int* [1];
		rows++;
		s[0] = new int[2];
		s[0][0] = sp;
		s[0][1] = ln;
		return;
	}
	else
	{

		int** temp = new int* [rows + 1];
		for (int i = 0; i < rows + 1; i++)
		{
			temp[i] = s[i];
		}
		temp[rows] = new int[2];
		temp[rows][0] = sp;
		temp[rows][1] = ln;
		rows++;
		delete[] s;
		s = temp;

	}

}

void Menu::GotoXy(int x, int y)
{
	COORD coordinates;     // coordinates is declared as COORD
	coordinates.X = x;     // defining x-axis
	coordinates.Y = y;     //defining  y-axis
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void Menu::Sort(string* names, int size_names, int** users, int s_rows)
{
	for (int i = 0; i < s_rows-1; i++)
	{
		int max = i;
		for (int c = i+1; c < s_rows; c++)
		{
			if (users[c][1] > users[max][1])
			{
				max = c;
			}
		}
		swap(users[i], users[max]);
		swap(names[i], names[max]);
	}

}




bool Menu::StartGame()
{
Start:
	Show();
	int result = SwitchMenu();
	cin.clear();
	if (result == 1)
	{
		if (user.length() == 0) AddUser();
		Snake snake;
		snake.Speed(speed);
		snake.UpdateMapInfo();
		char k;
		k = _getch();
		bool d1 = false;
		bool s1 = true;
		bool w = false;
		bool a = false;
		bool pause = false;
		do
		{
			cin.clear();
			if (pause == false) snake.ShowApple();
			if (snake.GetHp() < 1)
			{
				SaveResults(user, speed, snake.GetLength());
				SetFirstStart(true);
				goto Start;
			}
			if (_kbhit() > 0)
			{
				k = _getch();
				switch (k)
				{
				case 'd': if (pause == true) continue; snake.ChangePosition("d"); s1 = false; d1 = true; w = false; a = false; break;
				case 's': if (pause == true) continue; snake.ChangePosition("s"); s1 = true; d1 = false; w = false; a = false; break;
				case 'w': if (pause == true) continue; snake.ChangePosition("w"); s1 = false; d1 = false; w = true; a = false; break;
				case 'a': if (pause == true) continue;  snake.ChangePosition("a"); s1 = false; d1 = false; w = false; a = true; break;
				case 27: first = true; goto Start;
				case 'i': if (pause == true) continue;  snake.Speed(speed - 1); --speed;	snake.UpdateMapInfo(); break;
				case 'o': if (pause == true) continue; snake.Speed(speed + 1); ++speed;	snake.UpdateMapInfo(); break;
				case 'p':  (pause == false) ? pause = true : pause = false; break;
				default: cin.clear();		break;
				}

			}
			else
			{
				if (pause == true) continue;
				if (d1) snake.ChangePosition("d");
				if (s1) snake.ChangePosition("s");
				if (a) snake.ChangePosition("a");
				if (w) snake.ChangePosition("w");
			}
		} while (true);
	}
	else
		if (result < 0)
		{
			return false;
		}
		else
			if (result == 2)
			{
				LoadResults();
				goto Start;
			}
			else
				if (result == 3)
				{
					MenuChangeSpeed();
					goto Start;
				}
				else
					if (result == 4)
					{
						AddUser();
						goto Start;
					}
					else
						return true;
}

void Menu::SetColor(int text, int background)
{
	if (text == 0 or text == 7 or text == 8) text = 6;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void Menu::SetCurrentPos(int n)
{
	if (n > 0 and n < 5) current_pos = n;
	else
		if (n < 1) current_pos = 4;
		else	current_pos = 1;
}

int Menu::GetCurrenPos() const
{
	return current_pos;
}

void Menu::SetStrelka1(const char* a)
{
	if (strlen(a) > 0)	strelka = a;
}

string Menu::GetStrelka1() const
{
	return strelka;
}

void Menu::SetStrelka2(const char* a)
{
	if (strlen(a) > 0) strelka2 = a;
}

string Menu::GetStrelka2() const
{
	return strelka2;
}

void Menu::SetFirstStart(bool first)
{
	this->first = first;
}

bool Menu::GetFirstStartStatus() const
{
	return first;
}

void Menu::SetUser(string str)
{
	if (str.length() > 0) user = str;
	else user = "default";
}

string Menu::GetUser() const
{
	return user;
}

int Menu::SwitchMenu()
{

	char k = '1';

	do
	{
		k = _getch();

		switch (k)
		{
		case 13: return current_pos; break;
		case 27: return -1; break;
		case 's': ClearPosition(); current_pos++; SetCurrentPos(current_pos); Show(); break;
		case 'w': ClearPosition(); current_pos--; SetCurrentPos(current_pos); Show();  break;
		default: k = '1'; break;

		}

	} while (k != 13 and k != 27);



}

void Menu::ClearPosition()
{

	if (current_pos == 1)
	{
		newgame.GotoXY(newgame.GetXpos() - strelka.length() - 1, newgame.GetYpos() + 1);
		for (int i = 0; i < strelka.length(); i++)
		{
			cout << " ";
		}
		newgame.GotoXY(newgame.GetXpos() + newgame.GetLength() + 1, newgame.GetYpos() + 1);
		for (int i = 0; i < strelka2.length(); i++)
		{
			cout << " ";
		}
	}
	else
		if (current_pos == 2)
		{
			stat.GotoXY(stat.GetXpos() - strelka.length() - 1, stat.GetYpos() + 1);
			for (int i = 0; i < strelka.length(); i++)
			{
				cout << " ";
			}
			stat.GotoXY(stat.GetXpos() + stat.GetLength() + 1, stat.GetYpos() + 1);
			for (int i = 0; i < strelka2.length(); i++)
			{
				cout << " ";
			}
		}
		else
			if (current_pos == 3)
			{
				snake_speed.GotoXY(snake_speed.GetXpos() - strelka.length() - 1, snake_speed.GetYpos() + 1);
				for (int i = 0; i < strelka.length(); i++)
				{
					cout << " ";
				}
				snake_speed.GotoXY(snake_speed.GetXpos() + snake_speed.GetLength() + 1, snake_speed.GetYpos() + 1);
				for (int i = 0; i < strelka2.length(); i++)
				{
					cout << " ";
				}
			}
			else
				if (current_pos == 4)
				{
					enter_name.GotoXY(enter_name.GetXpos() - strelka.length() - 1, enter_name.GetYpos() + 1);
					for (int i = 0; i < strelka.length(); i++)
					{
						cout << " ";
					}
					enter_name.GotoXY(enter_name.GetXpos() + enter_name.GetLength() + 1, enter_name.GetYpos() + 1);
					for (int i = 0; i < strelka2.length(); i++)
					{
						cout << " ";
					}
				}

	cin.clear();
}

void Menu::CleArea()
{
	for (int i = 0; i < 50; i++)
	{
		for (int c = 0; c < 180; c++)
		{
			cout << " ";
		}
		cout << endl;
	}
	first = false;
}

void Menu::Show()
{
	newgame.GotoXY(0, 0);
	if (first) CleArea();
	newgame.ShowButton();
	stat.ShowButton();
	snake_speed.ShowButton();
	enter_name.ShowButton();
	if (current_pos == 1)
	{
		newgame.GotoXY(newgame.GetXpos() - strelka.length() - 1, newgame.GetYpos() + 1);
		SetColor(rand() % 14, 0);
		cout << strelka;
		newgame.GotoXY(newgame.GetXpos() + newgame.GetLength() + 1, newgame.GetYpos() + 1);
		SetColor(rand() % 14, 0);
		cout << strelka2;
	}
	else
		if (current_pos == 2)
		{
			stat.GotoXY(stat.GetXpos() - strelka.length() - 1, stat.GetYpos() + 1);
			SetColor(rand() % 14, 0);
			cout << strelka;
			stat.GotoXY(stat.GetXpos() + stat.GetLength() + 1, stat.GetYpos() + 1);
			SetColor(rand() % 14, 0);
			cout << strelka2;
		}
		else
			if (current_pos == 3)
			{
				snake_speed.GotoXY(snake_speed.GetXpos() - strelka.length() - 1, snake_speed.GetYpos() + 1);
				SetColor(rand() % 14, 0);
				cout << strelka;
				snake_speed.GotoXY(snake_speed.GetXpos() + snake_speed.GetLength() + 1, snake_speed.GetYpos() + 1);
				SetColor(rand() % 14, 0);
				cout << strelka2;
			}
			else
				if (current_pos == 4)
				{
					enter_name.GotoXY(enter_name.GetXpos() - strelka.length() - 1, enter_name.GetYpos() + 1);
					SetColor(rand() % 14, 0);
					cout << strelka;
					enter_name.GotoXY(enter_name.GetXpos() + enter_name.GetLength() + 1, enter_name.GetYpos() + 1);
					SetColor(rand() % 14, 0);
					cout << strelka2;
				}


	cin.clear();
}

void Menu::AddUser()
{
	GameButton users{ "Enter Name: ", '~', 75,31, 5,1, 3, 19, 3,7 };

	users.ShowButton();
	users.GotoXY(users.GetXpos() + users.GetLength() + 1, users.GetYpos() + 1);
	cin >> user;
	users.GotoXY(users.GetXpos(), users.GetYpos());
	for (int c = 0; c < users.GetWidth(); c++)
	{
		for (int i = 0; i < users.GetLength() + user.length() + 1; i++)
		{
			cout << " ";
		}
		users.GotoXY(users.GetXpos(), users.GetYpos() + c + 1);
	}
}

void Menu::SetMenuSnakeSpeed(int n)
{
	if (n > 0) speed = n;
}

int Menu::GetMenusSnakeSpeed() const
{
	return speed;
}

void Menu::ClearMenusSpeed(int cur)
{
	if (cur == 1)
	{
		b1.GotoXY(b1.GetXpos() - strelka.length() - 1, b1.GetYpos() + 1);
		for (int i = 0; i < strelka.length(); i++)
		{
			cout << " ";
		}
		b1.GotoXY(newgame.GetXpos() + b1.GetLength() + 1, b1.GetYpos() + 1);
		for (int i = 0; i < strelka2.length(); i++)
		{
			cout << " ";
		}
	}
	else
		if (cur == 2)
		{
			b2.GotoXY(stat.GetXpos() - strelka.length() - 1, b2.GetYpos() + 1);
			for (int i = 0; i < strelka.length(); i++)
			{
				cout << " ";
			}
			b2.GotoXY(b2.GetXpos() + b2.GetLength() + 1, b2.GetYpos() + 1);
			for (int i = 0; i < strelka2.length(); i++)
			{
				cout << " ";
			}
		}
		else
			if (cur == 3)
			{
				b3.GotoXY(b3.GetXpos() - strelka.length() - 1, b3.GetYpos() + 1);
				for (int i = 0; i < strelka.length(); i++)
				{
					cout << " ";
				}
				b3.GotoXY(b3.GetXpos() + b3.GetLength() + 1, b3.GetYpos() + 1);
				for (int i = 0; i < strelka2.length(); i++)
				{
					cout << " ";
				}
			}
}

Menu::Menu()
{
	//текс, хпос, упос, отсуп_х, отступ_н, ширина, длина, текст цвет, цвет бек
	newgame = { "New Game", '#', 75,20, 6,1, 3, 19, 10,4 };
	stat = { "Show Statistics", '#', 75,23, 2,1, 3, 19, 11,5 };
	snake_speed = { "Snake speed", '#',75, 26, 4,1, 3, 19, 12,1 };
	enter_name = { "New User", '#', 75,29, 6,1, 3, 19, 13,7 };
	b1 = { "Low", '#', 75,20, 5,1, 3, 19, 3,7 };
	b2 = { "Normal", '#', 75,23, 5,1, 3, 19, 3,7 };
	b3 = { "Fast", '#', 75,26, 5,1, 3, 19, 3,7 };
	current_pos = 1;
	strelka = "WA--->>>>";
	strelka2 = "<<<<---SD";
	first = false;
	user = "";
	speed = 60;
}
