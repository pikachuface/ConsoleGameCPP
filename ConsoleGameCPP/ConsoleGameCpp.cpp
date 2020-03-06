#ifdef WIN32
#include<conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif 

#include<stdio.h>
#include<ctype.h>
#include<thread>
#include<chrono>
//Tools
#include"Tools.h"
#include"Settings.h"
#include"Timer.h"
//Game Objects
#include"Snake.h"
#include"Food.h"

using namespace std;


void GameLoop();
void Rendering();
void KeyRegistering();
char getInput();
GameObject makeGameObject(int posX, int posY, char render, Colors color);

Snake snake;
Food food(10, 20, 0, 0, '@', Colors::RED_TXT, Colors::RED_BKG);

Timer timer;
bool gameOver = false;
thread keyregster;
thread rendering;

double timeDelta;

int main()
{
	Settings::MakeBorder(Colors::YELLOW_TXT, YELLOW_BKG);
	keyregster = thread(&KeyRegistering);
	rendering = thread(&Rendering);
	snake = Snake::Snake(makeGameObject(Settings::mapWidth / 2, Settings::mapHeight / 2, '#', Colors::GREEN_TXT));
	timer.restart();
	GameLoop();
	return 0;
}

void GameLoop()
{
	while (!gameOver)
	{
		if (timeDelta*1000 > Settings::timerInterval)
		{
			timeDelta = 0;
			snake.Move();
		}
		timeDelta += timer.restart();
	}
}

void Rendering()
{
	while (!gameOver)
	{
		food.render();
		for (int i = 0; i < snake.body.size(); i++)
		{
			snake.body[i].render();
		}
	}
}

void KeyRegistering()
{
	while (!gameOver)
	{
		switch (tolower(_getch()))
		{
		case'a':
			snake.ChangeDir(Directions::Left);
			break;
		case'd':
			snake.ChangeDir(Directions::Right);
			break;
		case's':
			snake.ChangeDir(Directions::Down);
			break;
		case'w':
			snake.ChangeDir(Directions::Up);
			break;
		}
	}
}



GameObject makeGameObject(int posX, int posY, char render, Colors color)
{
	GameObject temp(posX, posY, render, color);
	return temp;
}

#if WIN32
char getInput()
{
	return _getch();
}
#else
char getInput() {
	struct termios oldattr, newattr;
	int ch;
	tcgetattr(STDIN_FILENO, &oldattr);
	newattr = oldattr;
	newattr.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
	return (char)ch;
}
#endif 


