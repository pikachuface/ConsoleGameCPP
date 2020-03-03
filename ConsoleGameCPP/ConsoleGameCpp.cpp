#include<iostream>
#include<thread>
#include<conio.h>
//Tools
#include"Tools.h"
#include"Settings.h"
//Game Objects
#include"Snake.h"
#include"Food.h"

using namespace std;

void GameLoop();
void Rendering();
void KeyRegistering();
GameObject makeGameObject(int posX, int posY, char render, Colors color);

Snake snake(makeGameObject(Settings::mapWidth/2, Settings::mapHeight/2, '#', Colors::GREEN_TXT));
Food food(10,20,0,0,'@',Colors::RED_TXT, Colors::RED_BKG);


bool gameOver = false;
thread keyregster;
thread rendering;

int main()
{
	Settings::MakeBorder(Colors::YELLOW_TXT, YELLOW_BKG);

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
		food.render();
		

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


