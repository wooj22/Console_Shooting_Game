#include <stdio.h>
#include <string>
#include "ConsoleRenderer.h"
#include "Input.h"
#include "Time.h"
#include "GameManager.h"
#include "PlayScene.h"
#include "EndScene.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"


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

namespace Play {
	// player
	Player player(30, 55);
	BulletList playerBulletList;
	float playerTime = 0.0f;

	// enemy
	Enemy testEnemy(10, 10);

	// Start
	void Initalize() {
		Time::Initialize();
	}

	// Update
	void Update() {
		// TimeControll
		Time::UpdateTime();
		player.HitTimer();
		playerTime += Time::GetElapsedTime();

		// Move
		if (playerTime >= 0.1f) {
			// player
			player.Move(playMap);

			// player bullet
			for (Bullet* current = playerBulletList.head; current != NULL; current = current->next) {
				// 이동
				current->SetPos(current->GetPos().X, current->GetPos().Y - 1);

				// 적과 닿았을 경우 remove
				if (((PlayerBullet*)current)->OnTriggerEnter2D()) {
					//playerBulletList.remove(current);   // 예외발생 에러잇음
				}
			}

			// enemy
			testEnemy.Move();
			testEnemy.PlayerCollision(&player);

			playerTime = 0.0f;
		}

		// Debug player.hp
		std::string str = std::to_string(player.hp);
		const char* cstr = str.c_str();
		OutputDebugStringA(cstr);

		// Shoot
		if (Input::IsKeyDown(VK_SPACE)) {
			playerBulletList.insert(new PlayerBullet(player.pos.X, player.pos.Y - 1));
		}
	}

	// Render
	void Render() {
		// map
		for (int i = 0; i < mapHeight; i++)
		{
			ConsoleRenderer::ScreenDrawStringW(0, i, playMap[i], FG_YELLOW);
		}

		// player
		ConsoleRenderer::ScreenDrawChar(player.pos.X, player.pos.Y, player.body, FG_RED);

		// player bullet
		for (Bullet* current = playerBulletList.head; current != NULL; current = current->next) {
			ConsoleRenderer::ScreenDrawChar(current->GetPos().X, current->GetPos().Y, current->body, FG_RED);
		}

		// enemy
		ConsoleRenderer::ScreenDrawChar(testEnemy.pos.X, testEnemy.pos.Y, testEnemy.body, FG_BLUE);
	}
}

