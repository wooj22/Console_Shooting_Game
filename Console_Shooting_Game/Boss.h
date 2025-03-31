#pragma once
#include <windows.h>

class Boss {
public:
	COORD pos;
	const wchar_t* body;
	int hp;
	int attackDamege;
	float moveCycle;
	float shootCycle;
	bool isDie;

	void Move();
	void Hit(int damage);
	bool isCollision(SHORT x, SHORT y);
};