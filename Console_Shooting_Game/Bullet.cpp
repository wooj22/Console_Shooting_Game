#include "ConsoleRenderer.h"
#include "Time.h"
#include "Bullet.h"

Bullet::Bullet(int x, int y) {
	this->pos.X = x;
	this->pos.Y = y;
}

void Bullet::SetPos(int x, int y) {
	this->pos.X = x;
	this->pos.Y = y;
}

COORD Bullet::GetPos() {
	return this->pos;
}