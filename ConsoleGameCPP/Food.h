#pragma once
#include"GameObject.h"
#include"ansi_escapes.h"
#include"RandomNum.h"

class Food :GameObject
{
public:
	int value;
private:
	int valueRange[2];
public:
	Food(unsigned int maxValue, unsigned int minValue, int posX, int posY, char asciRender, Colors color=Colors::WHITE_TXT);
	//Changes location of object to random Pos
	void ChangeLoacation(unsigned int mapSize);
	//Changes Value to random number in range
	void ChangeValue();



};

