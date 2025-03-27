#include <stdio.h>
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
	Player player;
	//Bullet* bullets[100];
	BulletList playerBulletList;

	// Start
	void Initalize() {
		Time::Initialize();
	}

	// Update
	void Update() {
		// Move
		Time::UpdateTime();
		if (Time::GetTotalTime() >= 0.1f) {
			// Player
			player.Move(playMap);

			// Player Bullet
			for (Bullet* current = playerBulletList.head; current != NULL; current = current->next) {
				current->SetPos(current->GetPos().X, current->GetPos().Y - 1);
			}
				
			/*for (int i = 0; i < 100; i++)
				if (bullets[i] != nullptr)
					((PlayerBullet*)bullets[i])->SetPos(
						((PlayerBullet*)bullets[i])->GetPos().X, ((PlayerBullet*)bullets[i])->GetPos().Y - 1);*/

			Time::Initialize();
		}
		
		// Shoot
		if (Input::IsKeyDown(VK_SPACE)) {
			playerBulletList.insert(new PlayerBullet(player.pos.X, player.pos.Y - 1));
			//bullets[0] = (Bullet*)new PlayerBullet(player.pos.X, player.pos.Y - 1);
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

		/*for (int i = 0; i < 100; i++)
			if (bullets[i] != nullptr)
				ConsoleRenderer::ScreenDrawChar(((PlayerBullet*)bullets[i])->pos.X, 
					((PlayerBullet*)bullets[i])->pos.Y, ((PlayerBullet*)bullets[i])->body, FG_RED);*/
	}
}

