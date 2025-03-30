#pragma once
#include <windows.h>

class Player {
private:
	float hitTimer = 0.0f;
	const float invincibleDuration = 1.0f;

public:
	COORD pos;
	char body;
	int hp;
	int attackDamege;
	bool isHit;
	bool isDie ;
	Player(SHORT x = 30, SHORT y = 53) : pos({ x, y }), body('A'),
		hp(100), attackDamege(10), isDie(false), isHit(false) {};
	void Initialization();
	void Move(const wchar_t** playMap);
	bool isCollision(SHORT x, SHORT y);
	void Hit(int damage);
	void WallHit();
	void HitTimer();
	void Recover();
	void PowerUp();
};
