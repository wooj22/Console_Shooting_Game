#include "Boss.h"

void Boss::Move() {
	this->pos.Y++;
}

void Boss::Hit(int damage) {
	hp -= damage;
	if (hp <= 0) {
		hp = 0;
		isDie = true;
	}
}

void Boss::Attack() {
	OutputDebugStringA("boss : attack!\n");
}

bool Boss::isCollision(SHORT x, SHORT y) {
	// Boss size : x = 1, y = 4   "Boss"
	if (this->pos.Y == y && 
		this->pos.X <= x && this->pos.X+3 >= y) 
		return true;
	else return false;
}