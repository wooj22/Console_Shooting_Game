#pragma once

class Player {
private:
	bool isHit;
	float hitTimer = 0.0f;
	const float invincibleDuration = 2.0f;

public:
	COORD pos;
	char body = 'P';
	int hp;
	int attackDamege;
	bool isDie ;
	Player(SHORT x = 30, SHORT y = 55) : pos({ x, y }), body('P'),
		hp(100), attackDamege(10), isDie(false), isHit(false) {};
	void Initialization();
	void Move(const wchar_t** playMap);
	void Hit(int damage);
	void HitTimer();
};
