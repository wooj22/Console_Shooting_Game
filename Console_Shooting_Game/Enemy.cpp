#include "ConsoleRenderer.h"
#include "Input.h"
#include "Time.h"
#include "Enemy.h"

/// 이동
void Enemy::Move()
{
	this->pos.Y++;
	if (this->pos.Y >= 59)
		isGoal = true;
}

/// 피격
void Enemy::Hit(int damage) {
	this->hp -= damage;
	if (hp <= 0) isDie = true;
}

// 충돌
bool Enemy::isCollision(SHORT x, SHORT y) {
	if (this->pos.X == x && this->pos.Y == y) return true;
	else return false;
}