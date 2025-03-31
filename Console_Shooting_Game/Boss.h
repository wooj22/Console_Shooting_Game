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
		moveCycle(0.5f), shootCycle(2.0f), isDie(false){};
	void Move();
	void Hit(int damage);
	void Attack();
	bool isCollision(SHORT x, SHORT y);
};