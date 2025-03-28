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


namespace Play {
	// Start
	void Initalize() {
		Time::Initialize();
	}

	// Update
	void Update() {
		if (!player.isDie) {
			// Timer += deltaTime
			Time::UpdateTime();
			player.HitTimer();
			playerMoveTimer += Time::GetElapsedTime();
			playerShootTimer += Time::GetElapsedTime();
			bulletMoveTimer += Time::GetElapsedTime();
			enemySpawnTimer += Time::GetElapsedTime();
			enemyMoveTimer += Time::GetElapsedTime();

			// Player move & collision
			if (playerMoveTimer >= playerMoveCycle) {
				player.Move(playMap);

				// collision(player - enemy) : player hp 감소(die), enemy destroy
				for (auto enemy = enemyList.begin(); enemy != enemyList.end(); ) {
					if (enemy->PlayerCollision(&player)) {
						player.Hit(enemy->attackDamege);
						enemy = enemyList.erase(enemy);
					}
					else
						enemy++;
				}
				playerMoveTimer = 0.0f;
			}

			// Player shoot
			if (playerShootTimer >= playerShootCycle && Input::IsKeyDown(VK_SPACE)) {
				playerBulletList.Insert(new PlayerBullet(player.pos.X, player.pos.Y - 1));
				playerShootTimer = 0.0f;
			}

			// Bullet move & collision
			if (bulletMoveTimer >= bulletMoveCycle) {
				for (Bullet* currentBullet = playerBulletList.head; currentBullet != NULL; currentBullet = currentBullet->next) {
					currentBullet->SetPos(currentBullet->GetPos().X, currentBullet->GetPos().Y - 1);

					// collision(playerbullet - enemy) : playerbullet destroy, enemy hp 감소(die)
					for (auto enemy = enemyList.begin(); enemy != enemyList.end(); ) {
						if ((*enemy).PlayerBulletCollision((*currentBullet).pos.X, (*currentBullet).pos.Y)) {
							//playerBulletList.Remove(currentBullet);	 // TODO :: BulletList Remove() 수정
							enemy->Hit(player.attackDamege);
							if (enemy->isDie)
								enemy = enemyList.erase(enemy);
							else enemy++;
						}
						else
							enemy++;
					}
				}
				bulletMoveTimer = 0.0f;
			}

			// Enemy spawn
			if (enemySpawnTimer >= enemySpawnCycle) {
				enemyList.push_back(Enemy(rand() % 58 + 1, 0));
				enemySpawnTimer = 0.0f;
			}

			// Enemy move
			if (enemyMoveTimer >= enemyMoveCycle) {
				for (auto enemy = enemyList.begin(); enemy != enemyList.end(); enemy++)
					enemy->Move();
				enemyMoveTimer = 0.0f;
			}

			// Debug player.hp
			/*std::string str = std::to_string(player.hp);
			const char* cstr = str.c_str();
			OutputDebugStringA(cstr);*/
		}
		else {
			Game::g_SceneCurrent = Game::END_SCENE;
			End::Initalize();
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
		ConsoleRenderer::ScreenDrawChar(player.pos.X, player.pos.Y, player.body, FG_YELLOW);

		// player bullet
		for (Bullet* current = playerBulletList.head; current != NULL; current = current->next) {
			ConsoleRenderer::ScreenDrawChar(current->GetPos().X, current->GetPos().Y, current->body, FG_YELLOW);
		}

		// enemy
		for (auto& enemy : enemyList) {
			ConsoleRenderer::ScreenDrawChar(enemy.pos.X, enemy.pos.Y, enemy.body, FG_RED);
		}
	}
}

