#include <stdio.h>
#include "ConsoleRenderer.h"
#include "Input.h"
#include "GameManager.h"
#include "MenuScene.h"
#include "PlayScene.h"
#include "InfoScene.h"

// Map Data
const wchar_t* menuMap[] = {

L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"    ::::::::  :::    :::  ::::::::   ::::::::  :::::::::::  ",
L"   :+:    :+: :+:    :+: :+:    :+: :+:    :+:     :+:      ",
L"   +:+        +:+    +:+ +:+    +:+ +:+    +:+     +:+      ",
L"   +#++:++#++ +#++:++#++ +#+    +:+ +#+    +:+     +#+      ",
L"          +#+ +#+    +#+ +#+    +#+ +#+    +#+     +#+      ",
L"   #+#    #+# #+#    #+# #+#    #+# #+#    #+#     #+#      ",
L"    ########  ###    ###  ########   ########      ###      ",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"        ::::::::      :::     ::::    ::::  ::::::::::      ",
L"       :+:    :+:   :+: :+:   +:+:+: :+:+:+ :+:             ",
L"       +:+         +:+   +:+  +:+ +:+:+ +:+ +:+             ",
L"       :#:        +#++:++#++: +#+  +:+  +#+ +#++:++#        ",
L"       +#+   +#+# +#+     +#+ +#+       +#+ +#+             ",
L"       #+#    #+# #+#     #+# #+#       #+# #+#             ",
L"        ########  ###     ### ###       ### ##########      ",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                       ***************                      ",
L"                                                            ",
L"                        Game Start                          ",
L"                                                            ",
L"                        How to Play?                        ",
L"                                                            ",
L"                       ***************                      ",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"
};

const int mapHeight = sizeof(menuMap) / sizeof(menuMap[0]);
const wchar_t* selectBar[] = { L">>" };
COORD selectBar_coord = { 20,39 };

namespace Menu {

	// Start
	void Initalize() {

	}

	// Update 
	void Update() {
		if (Input::IsKeyPressed(VK_UP)) {
			selectBar_coord.Y = 39;
			Game::soundManager.PlaySFX_Shoot();
		}

		if (Input::IsKeyPressed(VK_DOWN)) {
			selectBar_coord.Y = 41;
			Game::soundManager.PlaySFX_Shoot();
		}

		// scene change
		if (Input::IsKeyPressed(VK_SPACE)) {
			if (selectBar_coord.Y == 39) {
				Game::soundManager.PlaySFX_Shoot();
				Game::g_SceneCurrent = Game::PLAY_SCENE;
				Play::Initalize();
			}
			else if (selectBar_coord.Y == 41) {
				Game::soundManager.PlaySFX_Shoot();
				Game::g_SceneCurrent = Game::INFO_SCENE;
				Info::Initalize();
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
