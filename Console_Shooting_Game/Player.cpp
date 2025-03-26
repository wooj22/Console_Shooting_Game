#include "ConsoleRenderer.h"
#include "Input.h"
#include "Time.h"
#include "Player.h"
#include "Bullet.h"

void Player::Move(const wchar_t** playMap)
{
	// 임시값 저장
	int nextX = pos.X;
	int nextY = pos.Y;

	// input에 따른 이동, 벽 경계 제어
	if (Input::IsKeyDown(VK_LEFT) &&
		playMap[pos.Y][pos.X - 1] != L'▓') {
		nextX--;
	}
	if (Input::IsKeyDown(VK_RIGHT) &&
		playMap[pos.Y][pos.X + 1] != L'▓') {
		nextX++;
	}
	if (Input::IsKeyDown(VK_UP)) { nextY--; }
	if (Input::IsKeyDown(VK_DOWN) &&
		playMap[pos.Y + 1][pos.X] != L'▓') {
		nextY++;
	}

	// 상단 경계 제어
	if (nextY < 0) nextY = 0;

	// 최종 포지션
	pos.X = nextX;
	pos.Y = nextY;
}

void Player::Shoot() {
	if (Input::IsKeyDown(VK_SPACE)) {
		Bullet bullet;

		while (bullet.pos.Y <= 0) {
			if (Time::GetTotalTime() >= 0.1f) {
				bullet.SetPos(this->pos.X, this->pos.Y - 1);
				ConsoleRenderer::ScreenDrawChar(bullet.pos.X, bullet.pos.Y, bullet.bulletChar, FG_RED);
			}
		}
	}
}