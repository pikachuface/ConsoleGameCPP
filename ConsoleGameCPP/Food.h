#pragma once
#include"GameObject.h"
#include"ansi_escapes.h"
#include"RandomNum.h"

class Food : public GameObject
{
public:
	int value;
private:
	int valueRange[2];
public:
	//Ctor
	Food(int minValue, int maxvalue, int posX, int posY, char asciRender, Colors txtColor = Colors::WHITE_TXT, Colors bckColor = Colors::BLACK_BKG);
	//If food gets eaten
	void getEaten();
private:
	//Changes location of object to random Pos
	void changeLoacation();
	//Changes Value to random number in range
	void changeValue();
};

