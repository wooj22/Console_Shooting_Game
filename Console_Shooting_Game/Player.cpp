#include "ConsoleRenderer.h"
#include "Input.h"
#include "Time.h"
#include "Player.h"

/// 초기화 : 한번 죽고 retry시에
void Player::Initialization() {
	pos.X = 30;
	pos.Y = 53;
	hp = 100;
	attackDamege = 10;
	isDie = false;
	isHit = false;
}

/// 이동
void Player::Move(const wchar_t** playMap)
{
	// 임시값 저장
	int nextX = this->pos.X;
	int nextY = this->pos.Y;

	// input에 따른 이동, 벽 경계 제어
	if (Input::IsKeyDown(VK_LEFT) &&
		playMap[this->pos.Y][this->pos.X - 1] != L'▓') {
		nextX--;
	}
	if (Input::IsKeyDown(VK_RIGHT) &&
		playMap[this->pos.Y][this->pos.X + 1] != L'▓') {
		nextX++;
	}
	if (Input::IsKeyDown(VK_UP)) { nextY--; }
	if (Input::IsKeyDown(VK_DOWN) &&
		playMap[this->pos.Y + 1][this->pos.X] != L'▓') {
		nextY++;
	}

	// 상단 경계 제어
	if (nextY < 0) nextY = 0;

	// 최종 포지션 set
	this->pos.X = nextX;
	this->pos.Y = nextY;
}

// 충돌
bool Player::isCollision(SHORT x, SHORT y) {
	if (this->pos.X == x && this->pos.Y == y) return true;
	else return false;
}

/// 피격 : 1초간 무적
void Player::Hit(int damage) {
	if (!isHit) {
		isHit = true;
		hitTimer = invincibleDuration;
		hp -= damage;

		if (hp <= 0) {
			isDie = true;
			hp = 0;
		}
	}
}

void Player::HitTimer() {
	if (isHit) {
		hitTimer -= Time::GetDeltaTime();
		if (hitTimer <= 0.0f) {
			isHit = false;
		}
	}
}