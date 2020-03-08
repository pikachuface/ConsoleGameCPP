#ifdef WIN32
#include<conio.h>
#else
#include <termios.h>
#include <unistd.h>
#include<pthread.h>
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
static GameObject makeGameObject(int posX, int posY, char render, Colors colorTxt = Colors::WHITE_TXT, Colors colorBck = Colors::BLACK_BKG);

Snake snake(makeGameObject(Settings::mapWidth / 2, Settings::mapHeight / 2, '#', Colors::CYAN_TXT, Colors::CYAN_BKG));
Food food(10, 10, 0, 0, '@', Colors::RED_TXT, Colors::RED_BKG);

Timer timer;
thread keyregister;
thread rendering;
double timeDelta;


bool gameOver = false;
int score = 0;


int main()
{
	Settings::MakeBorder(Colors::YELLOW_TXT, YELLOW_BKG);
	keyregister = thread(&KeyRegistering);
	rendering = thread(&Rendering);
	timer.restart();
	GameLoop();
	return 0;
}

void GameLoop()
{
	while (!gameOver)
	{
		if (timeDelta * 1000 > Settings::timerInterval)
		{
			timeDelta = 0;
			if (snake.Move()) gameOver = true;
			if (snake.body[0].posX == food.posX && snake.body[0].posY == food.posY)
			{
				snake.addBodyPart(makeGameObject(Settings::mapWidth / 2, Settings::mapHeight / 2, '#', Colors::GREEN_TXT, Colors::GREEN_BKG));
				score += food.getEaten();
			}
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
		switch (tolower(getInput()))
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


GameObject makeGameObject(int posX, int posY, char render, Colors colorTxt, Colors colorBck)
{
	GameObject temp(posX, posY, render, colorTxt, colorBck);
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
	char input = static_cast<char>(ch);
	return input;
}
#endif 


