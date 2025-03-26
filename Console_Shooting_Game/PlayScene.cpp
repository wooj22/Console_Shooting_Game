#include <stdio.h>
#include "ConsoleRenderer.h"
#include "Input.h"
#include "Time.h"
#include "GameManager.h"
#include "PlayScene.h"
#include "EndScene.h"

// Map Data
const wchar_t* playMap[] = {

L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"
};
const int mapHeight = sizeof(playMap) / sizeof(playMap[0]);

/*----------  Bullet Calss  ----------*/
class Bullet {
public:
	COORD pos;
	char bulletChar = 'o';

	void SetPos(int x, int y) {
		pos.X = x;
		pos.Y = y;
	}
};

/*----------  Player Calss  ----------*/
class Player {
public:
	COORD pos = { 30, 57 };
	char playerChar = 'P';

	/// Move
	void Move()
	{
		// 임시값 저장
		int nextX = pos.X;
		int nextY = pos.Y;

		// input에 따른 이동, 벽 경계 제어
		if (Input::IsKeyDown(VK_LEFT) && 
			playMap[pos.Y][pos.X - 1] != L'▓') { nextX--; }
		if (Input::IsKeyDown(VK_RIGHT) && 
			playMap[pos.Y][pos.X + 1] != L'▓') { nextX++; }
		if (Input::IsKeyDown(VK_UP)) { nextY--; }
		if (Input::IsKeyDown(VK_DOWN) &&
			playMap[pos.Y + 1][pos.X] != L'▓') { nextY++; }

		// 상단 경계 제어
		if (nextY < 0) nextY = 0;

		// 최종 포지션
		pos.X = nextX;
		pos.Y = nextY;
	}

	/// Attack
	void Shoot() {
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
};




namespace Play {
	Player player;

	// Start
	void Initalize() {
		Time::Initialize();
	}

	// Update
	void Update() {
		// input & playControll
		Time::UpdateTime();
		if (Time::GetTotalTime() >= 0.1f) {
			player.Move();
			Time::Initialize();
		}
		
		// scene change
		/*if (Input::IsKeyPressed(VK_SPACE)) {
			Game::g_SceneCurrent = Game::END_SCENE;
			End::Initalize();
		}*/
	}

	// Render
	void Render() {
		// map
		for (int i = 0; i < mapHeight; i++)
		{
			ConsoleRenderer::ScreenDrawStringW(0, i, playMap[i], FG_GRAY | FOREGROUND_INTENSITY);
		}

		// player
		ConsoleRenderer::ScreenDrawChar(player.pos.X, player.pos.Y, player.playerChar, FG_RED);
	}
}

