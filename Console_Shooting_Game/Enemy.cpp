﻿#include "ConsoleRenderer.h"
#include "Input.h"
#include "Time.h"
#include "Enemy.h"

/// 이동
void Enemy::Move()
{
	this->pos.Y++;
	if (this->pos.Y >= 59)
		isDie = true;
}

/// 피격
void Enemy::Hit(int damage) {
	this->hp -= damage;
	if (hp <= 0) isDie = true;
}

// 플레이어와 닿았을 경우
bool Enemy::PlayerCollision(Player* player) { 
	if (player->pos.X == this->pos.X && player->pos.Y == this->pos.Y) 
		return true;
	else
		return false;
}

// 플레이어 총알과 닿았을 경우
bool Enemy::PlayerBulletCollision(const wchar_t** playMap) {
	if (playMap[this->pos.X][this->pos.Y] == L'!') 
		return true;
	else 
		return false;
}