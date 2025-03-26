#include <stdio.h>
#include "ConsoleRenderer.h"
#include "Input.h"
#include "Time.h"
#include "GameManager.h"
#include "PlayScene.h"
#include "EndScene.h"
#include "Player.h"
#include "Bullet.h"

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

	// Start
	void Initalize() {
		Time::Initialize();
	}

	// Update
	void Update() {
		// Move
		Time::UpdateTime();
		if (Time::GetTotalTime() >= 0.1f) {
			player.Move(playMap);
			Time::Initialize();
		}
		
		// Shoot
		if (Input::IsKeyDown(VK_SPACE)) {
			player.Shoot();
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

