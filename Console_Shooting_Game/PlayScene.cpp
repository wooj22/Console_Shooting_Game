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
#include "Boss.h"
#include "Item.h"
#include "UIManager.h"


/* ------------------------- Data ----------------------------*/
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
L"▓  Speed                                                   ▓",
L"▓                                                          ▓",
L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"
};
const int mapHeight = sizeof(playMap) / sizeof(playMap[0]);

// game & level data
int currentLevel = 0;
float gamePlayTimer = 0.0f;

float levelChangeTiming[3] = {0, 20, 60};
float enemySpawnCycle[3] = { 6.5f, 5.0f, 3.0f };
float enemyMoveCycle[3] = { 1.2f, 1.0f, 0.7f };
float s_enemySpawnCycle[3] = { 10.0f, 6.0f, 4.0f };
float s_enemyMoveCycle[3] = { 1.5f, 0.8f, 0.5f };
float s_enemyShootCycle[3] = { 5.0f, 3.0f, 2.0f };
float s_enemyBulletMoveCycle[3] = { 0.3f, 0.1f, 0.05f };

// player data
Player player;
float playerMoveTimer = 0.0f;
float playerShootTimer = 0.0f;

// player bullet data
BulletList p_bulletList;
float bulletMoveCycle = 0.05f;
float bulletMoveTimer = 0.0f;

// enemy data
std::vector<Enemy> enemyList;
float enemySpawnTimer = 0.0f;
float enemyMoveTimer = 0.0f;

// shooting enemy data
std::vector<ShootingEnemy> s_enemyList;
float s_nemeyCreatStartTime = 20.0f;
float s_enemySpawnTimer = 0.0f;
float s_enemyMoveTimer = 0.0f;
float s_enemyShootTimer = 0.0f;

// shooting enemy bullet data
BulletList e_bulletList;
float s_enemyBulletMoveTimer = 0.0f;

// hpPosion data
ItemList hpPosionList;
float hpPosionCreateCycle = 30.0f;
float hpPosionCreateTimer = 0.0f;
float hpPosionMoveCycle = 0.7f;
float hpPosionMoveTimer = 0.0f;

// power posion data
ItemList powerPosionList;
float powerPosionStartTime = 20.0f;
float powerPosionCreateCycle = 15.0f;
float powerPosionCreateTimer = 0.0f;
float powerPosionMoveCycle = 0.2f;
float powerPosionMoveTimer = 0.0f;

// speed posion data
ItemList speedPosionList;
float speedPosionCreateCycle = 16.0f;
float speedPosionCreateTimer = 0.0f;
float speedPosionMoveCycle = 0.08f;
float speedPosionMoveTimer = 0.0f;

// boss data
bool isBoss = false;
float bossSpawnTime = 1.0f;	// 100으로 다시 돌려놔
float bossMoveTimer = 0.0f;
float bossShootTimer = 0.0f;
Boss* boss;

// boss bullet data
BulletList b_bulletList;
float bossBulletMoveTimer = 0.0f;
float bossBulletMoveCycle = 0.02f;

/* ------------------------ Funtions ---------------------------*/
/* 충돌 체크는 cycle이 더 짧은 쪽에서 검사하여 놓치지 않도록 한다. */

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
	hpPosionCreateTimer = 0.0f;
	hpPosionMoveTimer = 0.0f;
	powerPosionCreateTimer = 0.0f;
	powerPosionMoveTimer = 0.0f;
	speedPosionCreateTimer = 0.0f;
	speedPosionMoveTimer = 0.0f;
	bossMoveTimer = 0.0f;
	bossShootTimer = 0.0f;
	bossBulletMoveTimer = 0.0f;
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
	hpPosionCreateTimer += Time::GetDeltaTime();
	hpPosionMoveTimer += Time::GetDeltaTime();
	powerPosionCreateTimer += Time::GetDeltaTime();
	powerPosionMoveTimer += Time::GetDeltaTime();
	speedPosionCreateTimer += Time::GetDeltaTime();
	speedPosionMoveTimer += Time::GetDeltaTime();

	if (isBoss && !player.isBossKill) {
		bossMoveTimer += Time::GetDeltaTime();
		bossShootTimer += Time::GetDeltaTime();
		bossBulletMoveTimer += Time::GetDeltaTime();
	}
}

/// Level Managing
inline void LevelManaging() {
	// level
	if (gamePlayTimer >= levelChangeTiming[2])
		currentLevel = 2;
	else if (gamePlayTimer >= levelChangeTiming[1])
		currentLevel = 1;

	// boss
	if (!isBoss && gamePlayTimer >= bossSpawnTime) {
		boss = new Boss();
		UpdatePlayerHpUi(&player);
		isBoss = true;
	}
}

/// Player move & collision
inline void PlayerMoving() {
	if (playerMoveTimer >= player.moveCycle) {
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
		for (auto s_enemy = s_enemyList.begin(); s_enemy != s_enemyList.end(); ) {
			if (s_enemy->isCollision(player.pos.X, player.pos.Y)) {
				player.Hit(s_enemy->attackDamege);
				s_enemy = s_enemyList.erase(s_enemy);
				UpdatePlayerHpUi(&player);
				OutputDebugStringA("player : 공격 당함!  (s_enemy collision)\n");		// debug
			}
			else
				s_enemy++;
		}

		// collision(player - hp posion) : player hp 증가, hp posion remove
		for (Item* currentItem = hpPosionList.head; currentItem != nullptr; ) {
			Item* nextItem = currentItem->next;

			if (currentItem->isCollision(player.pos.X, player.pos.Y)) {
				player.Recover();
				hpPosionList.Remove(currentItem);
				UpdatePlayerHpUi(&player);
			}
			currentItem = nextItem;
		}

		// collision(player - power posoin) : player attack damage 증가, power posion remove
		for (Item* currentItem = powerPosionList.head; currentItem != nullptr; ) {
			Item* nextItem = currentItem->next;

			if (currentItem->isCollision(player.pos.X, player.pos.Y)) {
				player.PowerUp();
				powerPosionList.Remove(currentItem);
				UpdatePlayerPowerUi(&player);
			}
			currentItem = nextItem;
		}

		// collision(player - speed posoin) : player 이속 증가, speed posion remove
		for (Item* currentItem = speedPosionList.head; currentItem != nullptr; ) {
			Item* nextItem = currentItem->next;

			if (currentItem->isCollision(player.pos.X, player.pos.Y)) {
				player.SpeedUp();
				speedPosionList.Remove(currentItem);
				UpdatePlayerSpeedUi(&player);
			}
			currentItem = nextItem;
		}

		// collision(player - boss) : 바~로 die
		if (isBoss && !player.isBossKill && 
			boss->isCollision(player.pos.X, player.pos.Y))
			player.isDie = true;
		
			
		playerMoveTimer = 0.0f;
	}
}

/// Player shoot
inline void PlayerShooting() {
	if (playerShootTimer >= player.shootCycle && Input::IsKeyDown(VK_SPACE)) {
		if(player.attackDamege <= 30)
			p_bulletList.Insert(new PlayerBullet(player.pos.X, player.pos.Y - 1));
		else if (player.attackDamege <= 80)
			p_bulletList.Insert(new PlayerBullet(player.pos.X, player.pos.Y - 1, '!'));
		else
			p_bulletList.Insert(new PlayerBullet(player.pos.X, player.pos.Y - 1, '$'));

		playerShootTimer = 0.0f;
	}
}

/// Player Bullet move & collision
inline void PlayerBulletControll() {
	if (bulletMoveTimer >= bulletMoveCycle) {
		// move
		for (Bullet* currentBullet = p_bulletList.head; currentBullet != nullptr; ) {
			// nextBullet 미리 저장 (why? : bullet이 remove됐을때 currentBullet->next에 접근할 수 없기 때문)
			Bullet* nextBullet = currentBullet->next;
			bool isBulletDestroyed = false;

			((PlayerBullet*)currentBullet)->Move();
			
			// collision(playerbullet - enemy) : playerbullet remove, enemy hp 감소(die)
			for (auto enemy = enemyList.begin(); enemy != enemyList.end(); ) {
				if ((*enemy).isCollision(currentBullet->pos.X, currentBullet->pos.Y)) {
					p_bulletList.Remove(currentBullet);
					isBulletDestroyed = true;
					enemy->Hit(player.attackDamege);

					if (enemy->isDie) {
						enemy = enemyList.erase(enemy);
						UpdatePlayerHpUi(&player);
						OutputDebugStringA("player : 일반 몬스터 죽임\n");
					}
					else ++enemy;
					break;
				}
				else ++enemy;
			}

			// collision(playerbullet - s_enemy) : playerbullet remove, s_enemy hp 감소(die)
			if (!isBulletDestroyed) {
				for (auto s_enemy = s_enemyList.begin(); s_enemy != s_enemyList.end(); ) {
					if ((*s_enemy).isCollision(currentBullet->pos.X, currentBullet->pos.Y)) {
						p_bulletList.Remove(currentBullet);
						isBulletDestroyed = true;
						s_enemy->Hit(player.attackDamege);

						if (s_enemy->isDie) {
							s_enemy = s_enemyList.erase(s_enemy);
							UpdatePlayerHpUi(&player);
							OutputDebugStringA("player : 공격 몬스터 죽임\n");
						}
						else ++s_enemy;
						break;
					}
					else ++s_enemy;
				}
			}

			// collision(playerbullet - boss) : playerbullet remove, boss hp 감소(die)
			if (isBoss && !player.isBossKill &&
				!isBulletDestroyed && boss->isCollision(currentBullet->pos.X, currentBullet->pos.Y)) {
				p_bulletList.Remove(currentBullet);
				boss->Hit(player.attackDamege);
				UpdateBossHpBar(boss);
				if (boss->isDie) player.isBossKill = true;
			}
			

			// 상단을 넘었을 경우 remove
			if(currentBullet->isGoal) 
				p_bulletList.Remove(currentBullet);

			currentBullet = nextBullet;
		}

		bulletMoveTimer = 0.0f;
	}
}

/// Enemy spawn
inline void EnemySpawn() {
	// 일반
	if (enemySpawnTimer >= enemySpawnCycle[currentLevel]) {
		enemyList.push_back(Enemy(rand() % 58 + 1, 0));
		enemySpawnTimer = 0.0f;
	}

	// 공격
	if (gamePlayTimer >= s_nemeyCreatStartTime && s_enemySpawnTimer >= s_enemySpawnCycle[currentLevel]) {
		s_enemyList.push_back(ShootingEnemy(rand() % 58 + 1, 0));
		s_enemySpawnTimer = 0.0f;
	}
}

/// Enemy move
inline void EnemyMoving() {
	// 일반
	if (enemyMoveTimer >= enemyMoveCycle[currentLevel]) {
		for (auto enemy = enemyList.begin(); enemy != enemyList.end(); ) {
			enemy->Move();

			if ((*enemy).isGoal) {
				enemy = enemyList.erase(enemy);
				player.WallHit();
				UpdatePlayerHpUi(&player);
			}
			else enemy++;	
		}

		enemyMoveTimer = 0.0f;
	}

	// 공격
	if (s_enemyMoveTimer >= s_enemyMoveCycle[currentLevel]) {
		for (auto s_enemy = s_enemyList.begin(); s_enemy != s_enemyList.end(); ) {
			s_enemy->Move();

			if ((*s_enemy).isGoal) {
				s_enemy = s_enemyList.erase(s_enemy);
				player.WallHit();
				UpdatePlayerHpUi(&player);
			}
			else s_enemy++;	
		}
			
		s_enemyMoveTimer = 0.0f;
	}
}

/// Enemy shoot
inline void EnemyShooting() {
	if (s_enemyShootTimer >= s_enemyShootCycle[currentLevel]) {
		for (auto s_enemy = s_enemyList.begin(); s_enemy != s_enemyList.end(); s_enemy++) 
			e_bulletList.Insert(new EnemyBullet((*s_enemy).pos.X, (*s_enemy).pos.Y+1));

		s_enemyShootTimer = 0.0f;
	}
}
 
/// Enemy Bullet move & collision
inline void EnemyBulletControll() {
	if (s_enemyBulletMoveTimer >= s_enemyBulletMoveCycle[currentLevel]) {
		for (Bullet* currentBullet = e_bulletList.head; currentBullet != nullptr; ) {
			Bullet* nextBullet = currentBullet->next;

			// move
			((EnemyBullet*)currentBullet)->Move();

			// collision(enemy bullet - player) : enemy bullet remove, player hp 감소
			if (player.isCollision(currentBullet->GetPos().X, currentBullet->GetPos().Y)) {
				e_bulletList.Remove(currentBullet);
				player.Hit(s_enemyList.front().attackDamege);
				UpdatePlayerHpUi(&player);
				OutputDebugStringA("player : 공격 당함! (s_enemy bullet)\n");		// debug
			}

			// 하단을 넘었을 경우 remove
			if (currentBullet->isGoal) 
				e_bulletList.Remove(currentBullet);

			currentBullet = nextBullet;
		}

		s_enemyBulletMoveTimer = 0.0f;
	}
}

/// Hp Posion creating
inline void HpPosionCreating() {
	if (hpPosionCreateTimer >= hpPosionCreateCycle) {
		hpPosionList.Insert(new HpPosion(rand() % 58 + 1, 0));
		hpPosionCreateTimer = 0.0f;
	}
}

/// Hp Posion move
inline void HpPosionMoving() {
	if (hpPosionMoveTimer >= hpPosionMoveCycle) {
		for (Item* currentItem = hpPosionList.head; currentItem != nullptr; ) {
			Item* nextItem = currentItem->next;
			currentItem->Move();

			// 하단을 넘었을 경우 remove
			if (currentItem->isGoal)
				hpPosionList.Remove(currentItem);

			currentItem = nextItem;
		}
			
		hpPosionMoveTimer = 0.0f;
	}
}

/// Power Posion creating
inline void PowerPosionCreating() {
	if (gamePlayTimer >= powerPosionStartTime && powerPosionCreateTimer >= powerPosionCreateCycle) {
		powerPosionList.Insert(new PowerPosion(rand() % 58 + 1, 0));
		powerPosionCreateTimer = 0.0f;
	}
}

/// Power Posion move
inline void PowerPosionMoving() {
	if (powerPosionMoveTimer >= powerPosionMoveCycle) {
		for (Item* currentItem = powerPosionList.head; currentItem != nullptr; ) {
			Item* nextItem = currentItem->next;
			currentItem->Move();

			// 하단을 넘었을 경우 remove
			if (currentItem->isGoal)
				powerPosionList.Remove(currentItem);

			currentItem = nextItem;
		}

		powerPosionMoveTimer = 0.0f;
	}
}

/// Speed Posion creating
inline void SpeedPosionCreating() {
	if (speedPosionCreateTimer >= speedPosionCreateCycle) {
		speedPosionList.Insert(new SpeedPosion(rand() % 58 + 1, 0));
		speedPosionCreateTimer = 0.0f;
	}
}

/// Speed Posion move
inline void SpeedPosionMoving() {
	if (speedPosionMoveTimer >= speedPosionMoveCycle) {
		for (Item* currentItem = speedPosionList.head; currentItem != nullptr; ) {
			Item* nextItem = currentItem->next;
			currentItem->Move();

			// 하단을 넘었을 경우 remove
			if (currentItem->isGoal)
				speedPosionList.Remove(currentItem);

			currentItem = nextItem;
		}

		speedPosionMoveTimer = 0.0f;
	}
}

/// Boss
inline void BossControll() {
	// boss move
	if (bossMoveTimer >= boss->moveCycle)
	{
		boss->Move();
		bossMoveTimer = 0.0f;
	}

	// boss attack
	if (bossShootTimer >= boss->shootCycle) {
		int xPosi = rand() % 4;
		b_bulletList.Insert(new BossBullet((*boss).pos.X + xPosi, (*boss).pos.Y + 1));
		bossShootTimer = 0.0f;
	}

	// bullet move & collision
	if (bossBulletMoveTimer >= bossBulletMoveCycle) {
		for (Bullet* current = b_bulletList.head; current != nullptr; ) {
			Bullet* next = current->next;
			((BossBullet*)current)->Move();

			if (player.isCollision(current->pos.X, current->pos.Y)) {
				b_bulletList.Remove(current);
				player.Hit(boss->attackDamege);
				UpdatePlayerHpUi(&player);
			}
			current = next;
		}

		bossBulletMoveTimer = 0.0f;
	}
}


/* ------------------------- Play ----------------------------*/
namespace Play {
	// Start
	void Initalize() {
		currentLevel = 0;
		isBoss = false;

		Time::Initialize();
		InitializationTimer();
		player.Initialization();

		UpdatePlayerHpUi(&player);
		UpdatePlayerPowerUi(&player);
		UpdatePlayerSpeedUi(&player);
	}

	// Update
	void Update() {
		// playing
		if (!player.isDie && !player.isBossKill) {
			UpdateTimer();
			LevelManaging();

			PlayerMoving();
			PlayerShooting();
			PlayerBulletControll();

			EnemySpawn();
			EnemyMoving();
			EnemyShooting();
			EnemyBulletControll();	

			HpPosionCreating();
			HpPosionMoving();

			PowerPosionCreating();
			PowerPosionMoving();

			SpeedPosionCreating();
			SpeedPosionMoving();

			if (isBoss && !player.isBossKill) {
				BossControll();
			}
		}
		// game over
		else if(player.isDie){
			OutputDebugStringA("player : die\n");

			// data clear
			enemyList.clear();
			s_enemyList.clear();
			p_bulletList.Clear();
			e_bulletList.Clear();
			hpPosionList.Clear();
			powerPosionList.Clear();
			speedPosionList.Clear();
			delete boss;

			// scene change
			Game::isGameSuccess = false;
			Game::g_SceneCurrent = Game::END_SCENE;
			End::Initalize();
		}
		// game success
		else if (!player.isDie && player.isBossKill) {
			OutputDebugStringA("player : boss kill\n ");
			// TODO :: 게임 성공 연출 추가?

			// scene change
			Game::isGameSuccess = true;
			Game::g_SceneCurrent = Game::END_SCENE;
			End::Initalize();
		}
	}

	// Render
	void Render() {
		// map
		for (int i = 0; i < mapHeight; i++)
			ConsoleRenderer::ScreenDrawStringW(0, i, playMap[i], FG_YELLOW);
		
		// player
		if(!player.isHit)
			ConsoleRenderer::ScreenDrawChar(player.pos.X, player.pos.Y, player.body, FG_YELLOW);
		else
			ConsoleRenderer::ScreenDrawChar(player.pos.X, player.pos.Y, player.body, FG_RED);

		// player bullet
		for (Bullet* current = p_bulletList.head; current != NULL; current = current->next) 
			ConsoleRenderer::ScreenDrawChar(current->GetPos().X, current->GetPos().Y, current->body, FG_YELLOW);
		
		// enemy
		for (auto& enemy : enemyList) 
			ConsoleRenderer::ScreenDrawChar(enemy.pos.X, enemy.pos.Y, enemy.body, FG_GRAY);
		
		// s_enemy
		for (auto& s_enemy : s_enemyList) 
			ConsoleRenderer::ScreenDrawChar(s_enemy.pos.X, s_enemy.pos.Y, s_enemy.body, FG_GREEN);
		
		// s_enemy bullet
		for (Bullet* current = e_bulletList.head; current != nullptr; current = current->next) 
			ConsoleRenderer::ScreenDrawChar(current->GetPos().X, current->GetPos().Y, current->body, FG_GREEN);
		
		// hp posion
		for (Item* current = hpPosionList.head; current != nullptr; current = current->next)
			ConsoleRenderer::ScreenDrawChar(current->GetPos().X, current->GetPos().Y, current->body, FG_RED);
		
		// power posion
		for (Item* current = powerPosionList.head; current != nullptr; current = current->next)
			ConsoleRenderer::ScreenDrawChar(current->GetPos().X, current->GetPos().Y, current->body, FG_BLUE);
		
		// speed posion
		for (Item* current = speedPosionList.head; current != nullptr; current = current->next)
			ConsoleRenderer::ScreenDrawChar(current->GetPos().X, current->GetPos().Y, current->body, FG_SKY);
		
		// boss
		if (isBoss) {
			ConsoleRenderer::ScreenDrawStringW(boss->pos.X, boss->pos.Y, boss->body, FG_GREEN);
			ConsoleRenderer::ScreenDrawStringW(boss->pos.X, boss->pos.Y-2, ui_bossHpBar, FG_RED);

			for (Bullet* current = b_bulletList.head; current != nullptr; current = current->next) 
				ConsoleRenderer::ScreenDrawChar(current->GetPos().X, current->GetPos().Y, current->body, FG_GREEN);
			
		}

		// UI
		ConsoleRenderer::ScreenDrawStringW(10, 55, ui_playerHp, FG_RED); 
		ConsoleRenderer::ScreenDrawStringW(10, 56, ui_playerPower, FG_BLUE);
		ConsoleRenderer::ScreenDrawStringW(10, 57, ui_playerSpeed, FG_SKY);
	}
}
