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
	OutputDebugStringA("boss : Shoot!!!\n");
}

bool Boss::isCollision(SHORT x, SHORT y) {
	// Boss size : x = 1, y = 4   "Boss"
	if (this->pos.X == x && 
		this->pos.Y <= y && this->pos.Y >= y+4) 
		return true;
	else return false;
}