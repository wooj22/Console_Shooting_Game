#include "ConsoleRenderer.h"
#include "Time.h"
#include "Bullet.h"

/*-------------- Player Bullet ---------------*/
PlayerBullet::PlayerBullet(int x, int y) {
	this->pos.X = x;
	this->pos.Y = y;
}

void PlayerBullet::SetPos(int x, int y) {
	this->pos.X = x;
	this->pos.Y = y;
}

COORD PlayerBullet::GetPos() {
	return this->pos;
}

/*-------------- Enemy Bullet ---------------*/
EnemyBullet::EnemyBullet(int x, int y) {
	this->pos.X = x;
	this->pos.Y = y;
}

void EnemyBullet::SetPos(int x, int y) {
	this->pos.X = x;
	this->pos.Y = y;
}

COORD EnemyBullet::GetPos() {
	return this->pos;
}