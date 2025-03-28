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

	Player(SHORT x, SHORT y) : pos({ x, y }), body('P'),
		hp(10), attackDamege(10), isDie(false), isHit(false) {};
	void Move(const wchar_t** playMap);
	void Hit(int damage);
	void HitTimer();
};
