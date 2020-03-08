#pragma once
#include "ansi_escapes.h"
#include "Settings.h"
#include "Tools.h"

class GameObject
{
public:
	int posX, posY;
private:
	bool changedPos = false;
	int lastPosX, lastPosY;
	char asciRender;
	Colors txtColor;
	Colors bckColor;
public:
	GameObject(int posX, int posY, char render, Colors txtColor = Colors::WHITE_TXT, Colors bckColor = Colors::BLACK_BKG);
	void moveTo(int posX, int PosY);
	void moveBy(int x, int y);
	void render(bool overrideRender = false, bool deleteOldOne = true);
private:
	void saveLastPos();

};

