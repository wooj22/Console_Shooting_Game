#pragma once
#include "Player.h"

class Enemy {
public:
	COORD pos;
	char body;
	int hp;
	int attackDamege;
	bool isDie;
	
	Enemy(SHORT x, SHORT y) : pos({ x, y }), body('E'), hp(10), attackDamege(10), isDie(false) {};
	void Move();
	void Hit(int damage);
	bool PlayerCollision(Player* player);
	bool PlayerBulletCollision(const wchar_t** playMap);
};