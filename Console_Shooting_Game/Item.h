#pragma once
#include <windows.h>

class Item {
public:
	COORD pos;
	char body;

	Item(SHORT x, SHORT y, char body) : pos({ x, y }), body(body) {};
	void Move();
	bool isCollision(SHORT x, SHORT y);
};

class HpPosion : public Item{
public:
	int hpUp = 10;
};

class PowerUpPosion : public Item {
public:
	int powerUp = 5;
};
