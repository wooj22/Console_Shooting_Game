#pragma once

class Enemy {
public:
	COORD pos;
	char body;
	int hp;
	int attackDamege;
	bool isDie;
	
	Enemy(SHORT x, SHORT y, char body = 'o', int hp = 10, int attackDamege = 10) :
		pos({ x, y }), body(body), hp(hp), attackDamege(attackDamege), isDie(false) {};
	void Move();
	void Hit(int damage);
	bool isCollision(SHORT x, SHORT y);
};

class ShootingEnemy : public Enemy {
public:
	ShootingEnemy(SHORT x, SHORT y, char body = '0', int hp = 30, int attackDamege = 20) : Enemy(x, y, body, hp, attackDamege) {}
};

