#include<iostream>
#include<thread>
#include<conio.h>
#include"Snake.h"
#include"Food.h"
#include"ansi_escapes.h"
#include"RandomNum.h"

using namespace std;

void GameLoop();
void Rendering();
void KeyRegistering();
GameObject makeGameObject(int posX, int posY, char render, Colors color);

Snake snake(makeGameObject(Settings::mapWidth/2, Settings::mapHeight/2, '#', Colors::GREEN_TXT));
Food food();


bool gameOver = false;
thread keyregster;
thread rendering;

int main()
{
	Settings::MakeBorder();

	keyregster = thread(&KeyRegistering);
	rendering = thread(&Rendering);
	GameLoop();
	return 0;
}

void GameLoop()
{
	while (!gameOver)
	{




	}
}

void Rendering()
{
	while (!gameOver)
	{


	}
}

void KeyRegistering()
{
	while (!gameOver)
	{


	}
}



GameObject makeGameObject(int posX, int posY, char render, Colors color)
{
	GameObject temp(posX, posY, render, color);
	return temp;
}


