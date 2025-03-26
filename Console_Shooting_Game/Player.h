#pragma once
#include "Bullet.h"

class Player {
public:
	int hp = 100;
	int attackDamege = 10;
	char playerChar = 'P';
	bool isDie = false;
	COORD pos = { 30, 57 };

	Bullet* bullets[100];

	void Move(const wchar_t** playMap);
	bool CheckCollision(int targetX, int targetY);
	void Shoot();
	void TakeDamaged(int damage);
};
