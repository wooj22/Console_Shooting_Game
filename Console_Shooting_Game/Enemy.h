#pragma once

class Enemy {
public:
	COORD pos;
	char body = 'E';

	int hp = 10;
	int attackDamege = 10;
	bool isDie = false;
	
	Enemy(int x, int y);
	void Move(const wchar_t** playMap);
	void TakeDamaged(int damage);
};