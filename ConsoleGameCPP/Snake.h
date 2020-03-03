#pragma once
#include<vector>
#include"GameObject.h"
#include"directions.h"
class Snake
{
public:
	std::vector<GameObject> body;
	int lives;
private:
	Directions curDir = Directions::None;
	Directions lastDir = Directions::None;
public:
	Snake(GameObject head, int lives = 1);
	void ChangeDir(Directions newDir);
	void Move();
private:
	void addBodyPart();
};

