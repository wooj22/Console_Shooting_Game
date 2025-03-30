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
#include "UIManager.h"


/* --------------------- Play Data ------------------------*/
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
L"▓  HP                                                      ▓",
L"▓  Power                                                   ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"
};
const int mapHeight = sizeof(playMap) / sizeof(playMap[0]);

// game & level data
float gamePlayTimer = 0.0f;

// player data
Player player;
float playerMoveCycle = 0.1f;
float playerMoveTimer = 0.0f;
float playerShootCycle = 0.2f;
float playerShootTimer = 0.0f;

// player bullet data
BulletList playerBulletList;
float bulletMoveCycle = 0.05f;
float bulletMoveTimer = 0.0f;

// enemy data
std::vector<Enemy> enemyList;
float enemySpawnCycle = 2.5f;
float enemySpawnTimer = 0.0f;
float enemyMoveCycle = 0.8f;
float enemyMoveTimer = 0.0f;

// shooting enemy data
std::vector<ShootingEnemy> shootingEnemyList;
float s_nemeyCreatStartTime = 20.0f;
float s_enemySpawnCycle = 4.0f;
float s_enemySpawnTimer = 0.0f;
float s_enemyMoveCycle = 0.5f;
float s_enemyMoveTimer = 0.0f;
float s_enemyShootCycle = 2.0f;
float s_enemyShootTimer = 0.0f;

// shooting enemy bullet data
BulletList enemyBulletList;
float s_enemyBulletMoveCycle = 0.05f;
float s_enemyBulletMoveTimer = 0.0f;


/* --------------------- Funtions ------------------------*/
// Timer Initialization
inline void InitializationTimer() {
	gamePlayTimer  = 0.0f;
	playerMoveTimer = 0.0f;
	playerShootTimer = 0.0f;
	bulletMoveTimer = 0.0f;
	enemySpawnTimer = 0.0f;
	enemyMoveTimer = 0.0f;
	s_enemySpawnTimer = 0.0f;
	s_enemyMoveTimer = 0.0f;
	s_enemyShootTimer = 0.0f;
	s_enemyBulletMoveTimer = 0.0f;
}


// Timer += deltaTime
inline void UpdateTimer() {
	Time::UpdateTime();
	player.HitTimer();
	gamePlayTimer += Time::GetDeltaTime();
	playerMoveTimer += Time::GetDeltaTime();
	playerShootTimer += Time::GetDeltaTime();
	bulletMoveTimer += Time::GetDeltaTime();
	enemySpawnTimer += Time::GetDeltaTime();
	enemyMoveTimer += Time::GetDeltaTime();
	s_enemySpawnTimer += Time::GetDeltaTime();
	s_enemyMoveTimer += Time::GetDeltaTime();
	s_enemyShootTimer += Time::GetDeltaTime();
	s_enemyBulletMoveTimer += Time::GetDeltaTime();
}

// Player move & collision
inline void PlayerMoving() {
	if (playerMoveTimer >= playerMoveCycle) {
		player.Move(playMap);

		// collision(player - enemy) : player hp 감소(die), enemy destroy
		for (auto enemy = enemyList.begin(); enemy != enemyList.end(); ) {
			if (enemy->isCollision(player.pos.X, player.pos.Y)) {
				player.Hit(enemy->attackDamege);
				enemy = enemyList.erase(enemy);
				UpdatePlayerHpUi(&player);
				OutputDebugStringA("player : 공격 당함! (enemy collision)\n");		// debug
			}
			else
				enemy++;
		}

		// collision(player - s_enemy) : player hp 감소(die), s_enemy destroy
		for (auto s_enemy = shootingEnemyList.begin(); s_enemy != shootingEnemyList.end(); ) {
			if (s_enemy->isCollision(player.pos.X, player.pos.Y)) {
				player.Hit(s_enemy->attackDamege);
				s_enemy = shootingEnemyList.erase(s_enemy);
				UpdatePlayerHpUi(&player);
				OutputDebugStringA("player : 공격 당함!  (s_enemy collision)\n");		// debug
			}
			else
				s_enemy++;
		}

		playerMoveTimer = 0.0f;
	}
}

// Player shoot
inline void PlayerShooting() {
	if (playerShootTimer >= playerShootCycle && Input::IsKeyDown(VK_SPACE)) {
		playerBulletList.Insert(new PlayerBullet(player.pos.X, player.pos.Y - 1));
		playerShootTimer = 0.0f;
	}
}

// Player Bullet move & collision
inline void PlayerBulletControll() {
	if (bulletMoveTimer >= bulletMoveCycle) {
		for (Bullet* currentBullet = playerBulletList.head; currentBullet != NULL; currentBullet = currentBullet->next) {
			currentBullet->SetPos(currentBullet->GetPos().X, currentBullet->GetPos().Y - 1);

			// collision(playerbullet - enemy) : playerbullet destroy, enemy hp 감소(die)
			for (auto enemy = enemyList.begin(); enemy != enemyList.end(); ) {
				if ((*enemy).isCollision((*currentBullet).pos.X, (*currentBullet).pos.Y)) {
					//playerBulletList.Remove(currentBullet);	 // TODO :: BulletList Remove() 수정
					enemy->Hit(player.attackDamege);
					
					if (enemy->isDie) {
						enemy = enemyList.erase(enemy);
						UpdatePlayerHpUi(&player);
						OutputDebugStringA("player : 일반 몬스터 죽임\n");		// debug
					}	
					else enemy++;
				}
				else
					enemy++;
			}

			// collision(playerbullet - s_enemy) : playerbullet destroy, s_enemy hp 감소(die)
			for (auto s_enemy = shootingEnemyList.begin(); s_enemy != shootingEnemyList.end(); ) {
				if ((*s_enemy).isCollision((*currentBullet).pos.X, (*currentBullet).pos.Y)) {
					//playerBulletList.Remove(currentBullet);	 // TODO :: BulletList Remove() 수정
					s_enemy->Hit(player.attackDamege);
					if (s_enemy->isDie) {
						s_enemy = shootingEnemyList.erase(s_enemy);
						UpdatePlayerHpUi(&player);
						OutputDebugStringA("player : 공격 몬스터 죽임\n");		// debug
					}
					else s_enemy++;
				}
				else
					s_enemy++;
			}
		}

		bulletMoveTimer = 0.0f;
	}
}

// Enemy spawn
inline void EnemySpawn() {
	// 일반
	if (enemySpawnTimer >= enemySpawnCycle) {
		enemyList.push_back(Enemy(rand() % 58 + 1, 0));
		enemySpawnTimer = 0.0f;
	}

	// 공격
	if (gamePlayTimer >= s_nemeyCreatStartTime && s_enemySpawnTimer >= s_enemySpawnCycle) {
		shootingEnemyList.push_back(ShootingEnemy(rand() % 58 + 1, 0));
		s_enemySpawnTimer = 0.0f;
	}
}

// Enemy move
inline void EnemyMoving() {
	// 일반
	if (enemyMoveTimer >= enemyMoveCycle) {
		for (auto enemy = enemyList.begin(); enemy != enemyList.end(); enemy++)
			enemy->Move();

		enemyMoveTimer = 0.0f;
	}

	// 공격
	if (s_enemyMoveTimer >= s_enemyMoveCycle) {
		for (auto s_enemy = shootingEnemyList.begin(); s_enemy != shootingEnemyList.end(); s_enemy++)
			s_enemy->Move();

		s_enemyMoveTimer = 0.0f;
	}
}

// Enemy shoot
inline void EnemyShooting() {
	if (s_enemyShootTimer >= s_enemyShootCycle) {
		for (auto s_enemy = shootingEnemyList.begin(); s_enemy != shootingEnemyList.end(); s_enemy++) 
			enemyBulletList.Insert(new EnemyBullet((*s_enemy).pos.X, (*s_enemy).pos.Y+1));

		s_enemyShootTimer = 0.0f;
	}
}
 
// Enemy Bullet move & collision
inline void EnemyBulletControll() {
	if (s_enemyBulletMoveTimer >= s_enemyBulletMoveCycle) {
		for (Bullet* currentBullet = enemyBulletList.head; currentBullet != NULL; currentBullet = currentBullet->next) {
			// move
			currentBullet->SetPos(currentBullet->GetPos().X, currentBullet->GetPos().Y + 1);

			// collision
			if (player.isCollision(currentBullet->GetPos().X, currentBullet->GetPos().Y)) {
				player.Hit(shootingEnemyList.front().attackDamege);
				UpdatePlayerHpUi(&player);
				OutputDebugStringA("player : 공격 당함! (s_enemy bullet)\n");		// debug
			}
		}

		s_enemyBulletMoveTimer = 0.0f;
	}
}

/* ----------------------- Play --------------------------*/
namespace Play {
	// Start
	void Initalize() {
		Time::Initialize();
		InitializationTimer();
		player.Initialization();
		UpdatePlayerHpUi(&player);
	}

	// Update
	void Update() {
		if (!player.isDie) {
			UpdateTimer();

			PlayerMoving();
			PlayerShooting();
			PlayerBulletControll();

			EnemySpawn();
			EnemyMoving();
			EnemyShooting();
			EnemyBulletControll();	
		}
		else {
			// debug
			OutputDebugStringA("player : 죽었다...\n HP : ");
			std::string str = std::to_string(player.hp);
			const char* cstr = str.c_str();
			OutputDebugStringA(cstr);

			playerBulletList.Clear();
			enemyBulletList.Clear();
			enemyList.clear();
			shootingEnemyList.clear();

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
		if(!player.isHit)
			ConsoleRenderer::ScreenDrawChar(player.pos.X, player.pos.Y, player.body, FG_YELLOW);
		else
			ConsoleRenderer::ScreenDrawChar(player.pos.X, player.pos.Y, player.body, FG_RED);

		// player bullet
		for (Bullet* current = playerBulletList.head; current != NULL; current = current->next) {
			ConsoleRenderer::ScreenDrawChar(current->GetPos().X, current->GetPos().Y, current->body, FG_YELLOW);
		}

		// enemy
		for (auto& enemy : enemyList) {
			ConsoleRenderer::ScreenDrawChar(enemy.pos.X, enemy.pos.Y, enemy.body, FG_GRAY);
		}

		// s_enemy
		for (auto& s_enemy : shootingEnemyList) {
			ConsoleRenderer::ScreenDrawChar(s_enemy.pos.X, s_enemy.pos.Y, s_enemy.body, FG_GREEN);
		}

		// s_enemy bullet
		for (Bullet* current = enemyBulletList.head; current != NULL; current = current->next) {
			ConsoleRenderer::ScreenDrawChar(current->GetPos().X, current->GetPos().Y, current->body, FG_GREEN);
		}

		// UI
		ConsoleRenderer::ScreenDrawStringW(10, 55, ui_playerHp, FG_RED);
		ConsoleRenderer::ScreenDrawStringW(10, 56, ui_playerPower, FG_GREEN);
	}
}
