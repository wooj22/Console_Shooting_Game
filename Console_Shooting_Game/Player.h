#pragma once

class Player {
public:
	COORD pos = { 30, 55 };
	char body = 'P';

	int hp = 100;
	int attackDamege = 10;
	bool isDie = false;

	void Move(const wchar_t** playMap);
	//bool CheckCollision(int targetX, int targetY);
	void TakeDamaged(int damage);
};
