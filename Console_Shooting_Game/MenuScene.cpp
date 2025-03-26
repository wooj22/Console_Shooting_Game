#include <stdio.h>
#include "ConsoleRenderer.h"
#include "Input.h"
#include "GameManager.h"
#include "MenuScene.h"
#include "PlayScene.h"

namespace Menu {
	// Map Data
	const wchar_t* menuMap[] = {

	L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
	L"                                                            ",
	L"                                                            ",
	L"   TTTTT  OOO  W   W  EEEEE  RRRR      OOO   FFFFF   77777  ",
	L"     T   O   O W   W  E      R   R    O   O  F       7   7  ",
	L"     T   O   O W W W  EEEE   RRRR     O   O  FFFF        7  ",
	L"     T   O   O WW WW  E      R  R     O   O  F           7  ",
	L"     T    OOO  W   W  EEEEE  R   R     OOO   F           7  ",
	L"                                                            ",
	L"                                                            ",
	L"                                                            ",
	L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓            ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄           ▓",
	L"▓            █░░░░░░░░▀█▄▀▄▀██████░▀█▄▀▄▀██████░           ▓",
	L"▓            ░░░░░░░░░░▀█▄█▄███▀░░░ ▀██▄█▄███▀░            ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                      ***************                     ▓",
	L"▓                                                          ▓",
	L"▓                       Game Start                         ▓",
	L"▓                                                          ▓",
	L"▓                       How to Play?                       ▓",
	L"▓                                                          ▓",
	L"▓                      ***************                     ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
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
	const int mapHeight = sizeof(menuMap) / sizeof(menuMap[0]);

	const wchar_t* selectBar[] = { L">>" };
	COORD selectBar_coord = { 20,39 };

	// Start
	void Initalize() {

	}

	// Update 
	void Update() {
		// scene change
		if (Input::IsKeyPressed(VK_UP)) {
			selectBar_coord.Y = 39;
		}

		if (Input::IsKeyPressed(VK_DOWN)) {
			selectBar_coord.Y = 41;
		}

		if (Input::IsKeyPressed(VK_SPACE)) {
			if (selectBar_coord.Y == 39) {
				Game::g_SceneCurrent = Game::PLAY_SCENE;
				Play::Initalize();
			}
		}
	}

	// Render
	void Render() {
		for (int i = 0; i < mapHeight; i++)
		{
			ConsoleRenderer::ScreenDrawStringW(0, i, menuMap[i], FG_YELLOW);
		}
		ConsoleRenderer::ScreenDrawStringW(selectBar_coord.X, selectBar_coord.Y, selectBar[0], FG_YELLOW);
	}
}
