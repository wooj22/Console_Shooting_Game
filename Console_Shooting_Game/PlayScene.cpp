#include <stdio.h>
#include <string>
#include <vector>
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
	// player data
	Player player(30, 55);
	float playerMoveCycle = 0.1f;
	float playerMoveTimer = 0.0f;
	float playerShootCycle = 0.2f;
	float playerShootTimer = 0.0f;

	// Bullet data
	BulletList playerBulletList;
	float bulletMoveCycle = 0.05f;
	float bulletMoveTimer = 0.0f;

	// enemy data
	std::vector<Enemy> enemyList;
	float enemySpawnCycle = 2.5f;
	float enemySpawnTimer = 0.0f;
	float enemyMoveCycle = 0.2f;
	float enemyMoveTimer = 0.0f;

	// Start
	void Initalize() {
		Time::Initialize();
	}

	// Update
	void Update() {
		// TimeControll
		Time::UpdateTime();
		player.HitTimer();
		playerMoveTimer += Time::GetElapsedTime();
		playerShootTimer += Time::GetElapsedTime();
		bulletMoveTimer += Time::GetElapsedTime();
		enemySpawnTimer += Time::GetElapsedTime();
		enemyMoveTimer += Time::GetElapsedTime();

		// Player move
		if (playerMoveTimer >= playerMoveCycle) {
			player.Move(playMap);
			playerMoveTimer = 0.0f;
		}

		// Player shoot
		if (playerShootTimer >= playerShootCycle && Input::IsKeyDown(VK_SPACE)) {
			playerBulletList.insert(new PlayerBullet(player.pos.X, player.pos.Y - 1));
			playerShootTimer = 0.0f;
		}

		// BUllet move & collision
		if (bulletMoveTimer >= bulletMoveCycle) {
			for (Bullet* current = playerBulletList.head; current != NULL; current = current->next) {
				current->SetPos(current->GetPos().X, current->GetPos().Y - 1);

				// 적과 닿았을 경우 remove (다운캐스팅 했는데 이제 EnemyBullet안써서.. 바꿔도됨)
				if (((PlayerBullet*)current)->OnTriggerEnter2D()) {
					//playerBulletList.remove(current);   // 예외발생 에러잇음
				}
			}
			bulletMoveTimer = 0.0f;
		}
		
		// Enemy spawn
		if (enemySpawnTimer >= enemySpawnCycle) {
			enemyList.push_back(Enemy(rand() % 58 + 1, 1));
			enemySpawnTimer = 0.0f;
		}

		// Enemy move & collision
		if (enemyMoveTimer >= enemyMoveCycle) {
			for (auto enemy = enemyList.begin(); enemy != enemyList.end(); ) {
				enemy->Move();
				if (enemy->PlayerCollision(&player)) 
					enemy = enemyList.erase(enemy);
				else 
					enemy++;
				
			}
			enemyMoveTimer = 0.0f;
		}
		
		// Debug player.hp
		/*std::string str = std::to_string(player.hp);
		const char* cstr = str.c_str();
		OutputDebugStringA(cstr);*/
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
		for (auto& enemy : enemyList) {
			ConsoleRenderer::ScreenDrawChar(enemy.pos.X, enemy.pos.Y, enemy.body, FG_BLUE);
		}
	}
}

