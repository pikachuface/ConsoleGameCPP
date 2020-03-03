#pragma once
#include"ansi_escapes.h"
#include "Settings.h"

class GameObject
{
public:
	int posX, posY;
private:
	bool changedPos = false;
	int lastPosX, lastPosY;
	char asciRender;
	Colors color;
public:
	GameObject(int posX, int posY, char render, Colors color = Colors::WHITE_TXT);
	void moveTo(int posX, int PosY);
	void moveBy(int x, int y);
	void render();
private:
	void saveLastPos();
	
};

