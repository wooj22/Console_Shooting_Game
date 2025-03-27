#pragma once

class Player {
public:
	COORD pos;
	char body = 'P';
	int hp;
	int attackDamege;
	bool isDie ;

	Player(int x, int y) : pos({ (SHORT)x, (SHORT)y }), body('P'), hp(100), attackDamege(10), isDie(false) {};
	void Move(const wchar_t** playMap);
	void Hit(int damage);
};
