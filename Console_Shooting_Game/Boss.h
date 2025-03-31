#pragma once
#include <windows.h>

class Boss {
public:
	COORD pos;
	int hp;
	const wchar_t* body =  L"Boss" ;
	int attackDamege;
	float moveCycle;
	float shootCycle;
	bool isDie;

	Boss() : pos({ 28, 0 }), hp(10000), body( L"Boss" ), attackDamege(20),
		moveCycle(0.2f), shootCycle(1.0f), isDie(false){};
	void Move();
	void Hit(int damage);
	bool isCollision(SHORT x, SHORT y);
};