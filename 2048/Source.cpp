#include <iostream>					//for input, output stream
#include <iomanip>					//for std::setw command
#include <ctime>					//time seed for random
#include <cstdlib>					//for rand function
#include <conio.h>					//for _getch
#include <fstream>					//for reading 2048.txt
#include "rlutil.h"					//custom library for text color
#pragma comment(lib, "winmm.lib")	//for the playsound function	

void game();
void gridf2();
void help();
void exit();
void choose(int);
void random();
void ChoiceProcess(int);
void welcome(std::string,int);
void check();
void a();
void m();
void s();
void again();
unsigned int tmp[5][5], grid2[5][5], tmpi, tmpj, i, j, n = 10, count;
char block = 219;
int main()
{
	srand(time(NULL));
	int x=0;
	PlaySound("boom.wav", NULL, SND_ASYNC | SND_FILENAME | SND_SYSTEM);
	std::string txt;
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n" << std::setw(24);
	txt = "A game created by M. Shahid Hussain";
	x = 2700;
	welcome(txt,x);
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n" << std::setw(28);
	txt = " And some other guy too";
	x = 2900;
	welcome(txt,x);
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n" << std::setw(35);
	txt = "From EME hell";
	x = 3350;
	welcome(txt,x);
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n" << std::setw(32);
	txt = "Made not for you";
	x = 3400;
	welcome(txt, x);
	std::string getcontent;
	std::ifstream openfile("2048.txt");
	if (openfile.is_open())
	{
		while (getline(openfile, getcontent))
		{
			std::cout << getcontent << std::endl;
		}
	}
	Sleep(800);

	std::cout << "\n\n\n\t\t\t\tLoading Please wait...\n";
	std::cout << "\t\t\t\t";
		for (int Z = 0; Z < 22;Z++)
	{
		std::cout << block;
		Sleep(100);
	}
	Sleep(1000);
	system("cls");
	PlaySound("loop.wav", NULL, SND_ASYNC | SND_LOOP | SND_FILENAME | SND_SYSTEM);
	x = 0;
	choose(x);
	Sleep(1000);
	return 0;
}
void choose(int x)
{
	int choice;
	count = 0;
	std::cout << "\n\n\n\n\n" << std::setw(30);
	std::string txt = "Now you get to choose\n\t\t\t\t1. Game\n\t\t\t\t2. Help\n\t\t\t\t3. Exit";
	for (int i = 0; i < txt.length(); i++)
	{
		std::cout << txt.at(i);
		Sleep(x);
	}
	std::cout << "\n\t\t\t\t";
	std::cin >> choice;
	system("cls");
	ChoiceProcess(choice);
}
void welcome(std::string txt, int x)
{
	for (int i = 0; i < txt.length(); i++)
	{
		std::cout << txt.at(i);
		Sleep(65);
	}
	//if (x == 1850)
	//	s();
	//else if (x == 2400)
	//	a();
	//else if (x == 1800)
	//	m();
	Sleep(x);
	if (x!=1)
	system("cls");
}
void ChoiceProcess(int choice)
{
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			static int x = 1;
			grid2[i][j] = 1;
			x++;
		}
	}
	switch (choice)
	{
	case 1:
		game();
		break;
	case 2:
		help();
		break;
	case 3:
		exit();
		break;
	default:
		std::cout << "\n\n\n\t\t\t\t";
		std::cout << "Try again";
		Sleep(500);
		system("cls");
		choose(0);
	}
}
void random()
{
	int temp, gen;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j ++)
		{
			tmp[i][j]=1;
		}
	}
	tmpi = rand() % 4;
	tmpj = rand() % 4;
	temp = rand() % 2 + 1;
	if (temp == 1)
		gen = 2;
	else
		gen = 4;
	tmp[tmpi][tmpj] = gen;
}
void check()
{
	random();
	for (int x = 0; x < 1000; x++)
	{
		if (grid2[tmpi][tmpj]>1)
			random();
		else
		{
			grid2[tmpi][tmpj] = tmp[tmpi][tmpj];
			break;
		}
	}
}
void again()
{
	char c;
	system("cls");
	std::cout << "\n\n\n\n\n" << std::setw(22);
	std::string x = "Would you like to play again? Y/N\n";
	welcome(x, 1);
	std::cout << std::setw(22);
	std::cin >> c;
	if ((c == 'y') || (c == 'Y'))
	{
		system("cls");
		PlaySound("loop.wav", NULL, SND_ASYNC | SND_LOOP | SND_FILENAME | SND_SYSTEM);
		choose(0);
	}
	else if ((c == 'n') || (c == 'N'))
		exit();
	else
	{
		std::cout << "Try again";
		Sleep(500);
		again();
	}
}
void game()
{
	int limit;
	bool chk = false, chk2 = true, chk3 = true;
	std::string str;
	std::cout << "\n\t\t\tInput the max value you wish to go to. \n\t\t\tThe value can only be a power of 2.\n\n\t\t\tThe minimum limit is 16. Max is 2^32: ";
	std::cin >> limit;
	for (int i = 4; i <= 32; i++)
	{
		if (limit == pow(2, i))
			chk = true;
	}
	if (chk != true)
	{
		std::cout << "\nTry again";
		Sleep(500);
		system("cls");
		game();
	}
	check();
	gridf2();
	char c;
	while (1)
	{
		chk2 = true;
		chk3 = true;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				{
					if (j >= 1)
					{
						int l = j - 1;
						if ((grid2[i][j] == 1) || (grid2[i][l] == 1) || (grid2[i][j] == grid2[i][l]))
							chk3 = false;
					}
					if (i >= 1)
					{
						int k = i - 1;
						if ((grid2[i][j] == 1) || (grid2[k][j] == 1) || (grid2[i][j] == grid2[k][j]))
							chk2 = false;
					}
				}
			}
		}
		if ((chk2 == true) && (chk3 == true))
		{
			std::cout << "\n\n\t\t\t\tYou have lost..."; 
			PlaySound("fail.wav", NULL, SND_ASYNC | SND_FILENAME | SND_SYSTEM);
			Sleep(5000);
			again();
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (grid2[i][j] == limit)
				{
					std::cout << "\n\n\t\t\t\tYou have won!";
					PlaySound("win.wav", NULL, SND_ASYNC | SND_FILENAME | SND_SYSTEM);
					Sleep(5000);
					again();
				}
			}
		}
		c = 0;
		bool c2 = false, c3 = false, c4 = false;
		switch ((c = _getch()))
		{
		case 72:	//UP
			for (int x = 0; x < 4; x++)
			{
				for (int j = 1; j < 4; j++)
				{
					for (int i = 0; i < 4; i++)
					{
						int l = j - 1;
						if ((grid2[j][i]>1) && (grid2[l][i] == 1))
						{
							grid2[l][i] = grid2[j][i];
							grid2[j][i] = 1;
							c2 = true;
						}
					}
				}
			}
			for (int j = 1; j < 4; j++)
			{
				for (int i = 0; i < 4; i++)
				{
					int l = j - 1;
					if ((grid2[j][i]>1) && (grid2[j][i] == grid2[l][i]))
					{
						grid2[l][i] += grid2[j][i];
						grid2[j][i] = 1;
						c3 = true;
						count += grid2[l][i];
					}
				}
			}
			for (int x = 0; x < 4; x++)
			{
				for (int j = 1; j < 4; j++)
				{
					for (int i = 0; i < 4; i++)
					{
						int l = j - 1;
						if ((grid2[j][i]>1) && (grid2[l][i] == 1))
						{
							grid2[l][i] = grid2[j][i];
							grid2[j][i] = 1;
							c4 = true;
						}
					}
				}
			}
			if ((c2 == true) || (c3 == true) || (c4 == true))
			{
				random();
				check();
				gridf2();
				break;
			}
			else
			{
				gridf2();
				break;
			}
		case 80:	//DOWN
			for (int x = 0; x < 4; x++)
			{
				for (int j = 2; j >= 0; j--)
				{
					for (int i = 0; i < 4; i++)
					{
						int l = j + 1;
						if ((grid2[j][i]>1) && (grid2[l][i] == 1))
						{
							grid2[l][i] = grid2[j][i];
							grid2[j][i] = 1;
							c2 = true;
						}
					}
				}
			}
			for (int j = 2; j >= 0; j--)
			{
				for (int i = 0; i < 4; i++)
				{
					int l = j + 1;
					if ((grid2[j][i]>1) && (grid2[j][i] == grid2[l][i]))
					{
						grid2[l][i] += grid2[j][i];
						grid2[j][i] = 1;
						c3 = true;
						count += grid2[l][i];
					}
				}
			}
			for (int x = 0; x < 4; x++)
			{
				for (int j = 2; j >= 0; j--)
				{
					for (int i = 0; i < 4; i++)
					{
						int l = j + 1;
						if ((grid2[j][i]>1) && (grid2[l][i] == 1))
						{
							grid2[l][i] = grid2[j][i];
							grid2[j][i] = 1;
							c4 = true;
						}
					}
				}
			}
			if ((c2 == true) || (c3 == true) || (c4 == true))
			{
				random();
				check();
				gridf2();
				break;
			}
			else
			{
				gridf2();
				break;
			}
		case 75:	//LEFT
			for (int x = 0; x < 4; x++)
			{
				for (int i = 1; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						int l = i - 1;
						if ((grid2[j][i]>1) && (grid2[j][l] == 1))
						{
							grid2[j][l] = grid2[j][i];
							grid2[j][i] = 1;
							c2 = true;
						}
					}
				}
			}
			for (int i = 1; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					int l = i - 1;
					if ((grid2[j][i]>1) && (grid2[j][i] == grid2[j][l]))
					{
						grid2[j][l] += grid2[j][i];
						grid2[j][i] = 1;
						c3 = true;
						count += grid2[j][l];
					}
				}
			}
			for (int x = 0; x < 4; x++)
			{
				for (int i = 1; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						int l = i - 1;
						if ((grid2[j][i]>1) && (grid2[j][l] == 1))
						{
							grid2[j][l] = grid2[j][i];
							grid2[j][i] = 1;
							c4 = true;
						}
					}
				}
			}
			if ((c2 == true) || (c3 == true) || (c4 == true))
			{
				random();
				check();
				gridf2();
				break;
			}
			else
			{
				gridf2();
				break;
			}
		case 77:	//RIGHT
			for (int x = 0; x < 4; x++)
			{
				for (int i = 2; i >= 0; i--)
				{
					for (int j = 0; j < 4; j++)
					{
						int l = i + 1;
						if ((grid2[j][i]>1) && (grid2[j][l] == 1))
						{
							grid2[j][l] = grid2[j][i];
							grid2[j][i] = 1;
							c2 = true;
						}
					}
				}
			}
			for (int i = 2; i >= 0; i--)
			{
				for (int j = 0; j < 4; j++)
				{
					int l = i + 1;
					if ((grid2[j][i]>1) && (grid2[j][l] == grid2[j][i]))
					{
						grid2[j][l] += grid2[j][i];
						grid2[j][i] = 1;
						c3 = true;
						count += grid2[j][l];
					}
				}
			}
			for (int x = 0; x < 4; x++)
			{
				for (int i = 2; i >= 0; i--)
				{
					for (int j = 0; j < 4; j++)
					{
						int l = i + 1;
						if ((grid2[j][i]>1) && (grid2[j][l] == 1))
						{
							grid2[j][l] = grid2[j][i];
							grid2[j][i] = 1;
							c4 = true;
						}
					}
				}
			}
			if ((c2 == true) || (c3 == true) || (c4 == true))
			{
				random();
				check();
				gridf2();
				break;
			}
			else
			{
				gridf2();
				break;
			}
		case 'e':
			system("cls");

			std::cout << "\n\n\n\n\n" << std::setw(22) << "Are you sure you want to exit? Y/N\n" << std::setw(22);
			std::cin >> str;
			if ((str == "y") || (str == "Y"))
			{
				system("cls");
				choose(0);
			}
			else if ((str == "n") || (str == "N"))
			{
				system("cls");
				gridf2();
			}
			else
			{
				std::cout << "Try again";
				Sleep(500);
				again();
			}
			break;
		case 'm':
			PlaySound(NULL, 0, 0);
			break;
		case 'p':
			PlaySound("loop.wav", NULL, SND_ASYNC | SND_LOOP | SND_FILENAME | SND_SYSTEM);
			break;
		}//switch end
	}//while end
}
void help()
{
	std::cout << "\n\n\tThe game starts with 1 or 2 randomly placed numbers in a 4x4 grid \n\t(16 cells).\n\t> Use the arrow keys to move the cells.\n\t> 2 cells of the same number will merge and add up.\n\t> New 2s and 4s will appear randomly on an empty cell with each \n\tmove you make.\n\t> Your objective is to make 2048 in a cell without getting stuck!";
	std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<<std::setw(79)<<"Press any key to go back.";
	_getch();
	system("cls");
	choose(0);
}
void exit()
{
	system("cls");
	std::cout << "\n\n\n\n\n" << std::setw(35);
	std::string x = "\t\t\t\t\t\tHasta la Vista, baby...";
	std::cout << "\n\n\t\t\t\t\t\t\t\t\t";
	std::string getcontent;
	std::ifstream openfile("term.txt");
	if (openfile.is_open())
	{
		while (getline(openfile, getcontent))
		{
			std::cout << getcontent << std::endl;
		}
	}
	welcome(x, 2000);
	exit(EXIT_SUCCESS);
}
void gridf2()
{
	system("cls");
	std::cout << std::setw(74) << "Press e to exit at any time";
	std::cout << "\n" << std::setw(79) << "Press m to mute, p to play music";
	std::cout << std::setw(55) << "Score: " << count;
	std::cout << "\n\n\n\t\t\t";	rlutil::setColor(11);
	for (int i = 0; i < 17; i++)
		std::cout << "1 ";
	for (int j = 0; j < 4; j++)
	{
		rlutil::setColor(11);
		std::cout << "\n\t\t\t";
		for (int i = 0; i < 5; i++)
			std::cout << "1       ";
		std::cout << "\n\t\t\t";
		for (int i = 0; i < 5; i++)
		{
			if (grid2[j][i] == 2)
			{
				rlutil::setColor(11);
				std::cout << "1   ";
				rlutil::setColor(14);
				std::cout << grid2[j][i] << "   ";
			}
			else if (grid2[j][i] == 4)
			{
				rlutil::setColor(11);
				std::cout << "1   ";
				rlutil::setColor(2);
				std::cout << grid2[j][i] << "   ";
			}
			else if (grid2[j][i] == 8)
			{
				rlutil::setColor(11);
				std::cout << "1   ";
				rlutil::setColor(3);
				std::cout << grid2[j][i] << "   ";
			}
			else if (grid2[j][i] == 16)
			{
				rlutil::setColor(11);
				std::cout << "1  ";
				rlutil::setColor(4);
				std::cout << grid2[j][i] << "   ";
			}
			else if (grid2[j][i] == 32)
			{
				rlutil::setColor(11);
				std::cout << "1  ";
				rlutil::setColor(5);
				std::cout << grid2[j][i] << "   ";
			}
			else if (grid2[j][i] == 64)
			{
				rlutil::setColor(11);
				std::cout << "1  ";
				rlutil::setColor(6);
				std::cout << grid2[j][i] << "   ";
			}
			else if (grid2[j][i] == 128)
			{
				rlutil::setColor(11);
				std::cout << "1  ";
				rlutil::setColor(7);
				std::cout << grid2[j][i] << "  ";
			}
			else if (grid2[j][i] == 256)
			{
				rlutil::setColor(11);
				std::cout << "1  ";
				rlutil::setColor(8);
				std::cout << grid2[j][i] << "  ";
			}
			else if (grid2[j][i] == 512)
			{
				rlutil::setColor(11);
				std::cout << "1  ";
				rlutil::setColor(9);
				std::cout << grid2[j][i] << "  ";
			}
			else if (grid2[j][i] == 1024)
			{
				rlutil::setColor(11);
				std::cout << "1 ";
				rlutil::setColor(10);
				std::cout << grid2[j][i] << "  ";
			}
			else if (grid2[j][i] == 2048)
			{
				rlutil::setColor(11);
				std::cout << "1 ";
				rlutil::setColor(12);
				std::cout << grid2[j][i] << "  ";
			}
			else if (grid2[j][i] > 2048)
			{
				rlutil::setColor(11);
				std::cout << "1 ";
				rlutil::setColor(13);
				std::cout << grid2[j][i] << "  ";
			}
			else
			{
				rlutil::setColor(11);
				std::cout << "1       ";
			}
		}
		rlutil::setColor(11);
		std::cout << "\n\t\t\t";
		for (int i = 0; i < 5; i++)
			std::cout << "1       ";
		std::cout << "\n\t\t\t";
		for (int i = 0; i < 17; i++)
			std::cout << "1 ";
	}
	_getch();
}
void a()
{
	for (i = 0; i < n; i++)
	{
		std::cout << "\n\t\t\t\t\t ";
		for (j = 0; j < 2 * n - 1; j++)
		{
			if (j == (n - 1) - i || j == (n - 1) + i || i == n / 2 && (j >= n / 2 && j <= (n - 1) + (n / 2)))
			{
				std::cout << block;
			}
			else
			{
				std::cout << " ";
			}
		}
		Sleep(100);
	}
}
void m()
{
	for (i = 0; i < n; i++)
	{
		std::cout << "\n\t\t\t\t\t\t  ";
		for (j = 0; j < 2 * n - 1; j++)
		{
			if (j == 0 || j == 2 * n - 2 || (i <= n / 2 && (j == 2 * i || j == (2 * n - 2) - 2 * i)))
			{
				std::cout << block;
			}
			else
			{
				std::cout << " ";
			}
		}
		Sleep(100);
	}
}
void s()
{
	for (i = 0; i < n; i++)
	{
		std::cout << "\n\t\t\t\t\t\t\t ";
		for (j = 0; j < n; j++)
		{
			if (i == 0 || i == n - 1 || i == n / 2 || (i<n / 2 && j == 0) || (i>n / 2 && j == n - 1))
			{
				std::cout << block;
			}
			else
			{
				std::cout << " ";
			}
		}
		Sleep(100);
	}
}