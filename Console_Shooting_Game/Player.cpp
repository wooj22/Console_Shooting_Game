#include "ConsoleRenderer.h"
#include "Input.h"
#include "Time.h"
#include "Player.h"

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

/// 충돌 체크
//bool Player::CheckCollision(int targetX, int targetY) {
//	return (this->pos.X <= targetX && this->pos.X >= targetX)
//		&& (this->pos.Y <= targetY && this->pos.Y  >= targetY);
//}

/// 피격
void Player::TakeDamaged(int damage) {
	this->hp -= damage;
}