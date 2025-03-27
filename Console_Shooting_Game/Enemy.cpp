#include "ConsoleRenderer.h"
#include "Input.h"
#include "Time.h"
#include "Enemy.h"

Enemy::Enemy(int x, int y) {
	this->pos.X = x;
	this->pos.Y = y;
}

/// 이동
void Enemy::Move(const wchar_t** playMap)
{
	
}

/// 충돌 체크
//bool Player::CheckCollision(int targetX, int targetY) {
//	return (this->pos.X <= targetX && this->pos.X >= targetX)
//		&& (this->pos.Y <= targetY && this->pos.Y  >= targetY);
//}

/// 피격
void Enemy::TakeDamaged(int damage) {
	this->hp -= damage;
}