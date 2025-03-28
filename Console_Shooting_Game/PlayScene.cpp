﻿#include <stdio.h>
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
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓                                                          ▓",
L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"
};
const int mapHeight = sizeof(playMap) / sizeof(playMap[0]);

// player data
Player player;
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
float enemyMoveCycle = 0.8f;
float enemyMoveTimer = 0.0f;

std::vector<ShootingEnemy> shootingEnemyList;
float s_enemySpawnCycle = 4.0f;
float s_enemySpawnTimer = 0.0f;
float s_enemyMoveCycle = 0.5f;
float s_enemyMoveTimer = 0.0f;
float s_enemyShootCycle = 0.5f;
float s_enemyShootTimer = 0.0f;

/* --------------------- Funtions ------------------------*/
// Timer += deltaTime
inline void UpdateTimer() {
	Time::UpdateTime();
	player.HitTimer();
	playerMoveTimer += Time::GetElapsedTime();
	playerShootTimer += Time::GetElapsedTime();
	bulletMoveTimer += Time::GetElapsedTime();
	enemySpawnTimer += Time::GetElapsedTime();
	enemyMoveTimer += Time::GetElapsedTime();
	s_enemySpawnTimer += Time::GetElapsedTime();
	s_enemyMoveTimer += Time::GetElapsedTime();
	s_enemyShootTimer += Time::GetElapsedTime();
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
			}
			else
				enemy++;
		}

		// collision(player - s_enemy) : player hp 감소(die), s_enemy destroy
		for (auto s_enemy = shootingEnemyList.begin(); s_enemy != shootingEnemyList.end(); ) {
			if (s_enemy->isCollision(player.pos.X, player.pos.Y)) {
				player.Hit(s_enemy->attackDamege);
				s_enemy = shootingEnemyList.erase(s_enemy);
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

// Bullet move & collision
inline void BulletControll() {
	if (bulletMoveTimer >= bulletMoveCycle) {
		for (Bullet* currentBullet = playerBulletList.head; currentBullet != NULL; currentBullet = currentBullet->next) {
			currentBullet->SetPos(currentBullet->GetPos().X, currentBullet->GetPos().Y - 1);

			// collision(playerbullet - enemy) : playerbullet destroy, enemy hp 감소(die)
			for (auto enemy = enemyList.begin(); enemy != enemyList.end(); ) {
				if ((*enemy).isCollision((*currentBullet).pos.X, (*currentBullet).pos.Y)) {
					//playerBulletList.Remove(currentBullet);	 // TODO :: BulletList Remove() 수정
					enemy->Hit(player.attackDamege);
					if (enemy->isDie)
						enemy = enemyList.erase(enemy);
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
					if (s_enemy->isDie)
						s_enemy = shootingEnemyList.erase(s_enemy);
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
	if (s_enemySpawnTimer >= s_enemySpawnCycle) {
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

	if (s_enemyMoveTimer >= s_enemyMoveCycle) {
		for (auto s_enemy = shootingEnemyList.begin(); s_enemy != shootingEnemyList.end(); s_enemy++)
			s_enemy->Move();
		s_enemyMoveTimer = 0.0f;
	}
}

/* ----------------------- Play --------------------------*/
namespace Play {
	// Start
	void Initalize() {
		Time::Initialize();
		player.Initialization();
	}

	// Update
	void Update() {
		if (!player.isDie) {
			UpdateTimer();
			PlayerMoving();
			PlayerShooting();
			BulletControll();
			EnemySpawn();
			EnemyMoving();

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
			ConsoleRenderer::ScreenDrawChar(enemy.pos.X, enemy.pos.Y, enemy.body, FG_BLUE);
		}

		// s_enemy
		for (auto& s_enemy : shootingEnemyList) {
			ConsoleRenderer::ScreenDrawChar(s_enemy.pos.X, s_enemy.pos.Y, s_enemy.body, FG_RED);
		}
	}
}
