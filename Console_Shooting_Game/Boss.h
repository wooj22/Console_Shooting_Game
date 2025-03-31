#pragma once
#include <windows.h>

class Boss {
public:
	COORD pos;
	int hp;
	const char* body = "Boss";
	int attackDamege;
	float moveCycle;
	float shootCycle;
	bool isDie;

	Boss() : pos({ 0, 28 }), hp(10000), body("Boss"), attackDamege(20), 
		moveCycle(0.5f), shootCycle(2.0f), isDie(false){};
	void Move();
	void Hit(int damage);
	bool isCollision(SHORT x, SHORT y);
};