#include <stdio.h>
#include "ConsoleRenderer.h"
#include "Input.h"
#include "Time.h"
#include "GameManager.h"
#include "MenuScene.h"
#include "EndScene.h"

// Map Data
const wchar_t* endMap[] = {

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
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                         press [ESC]                        ",
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
const int mapHeight = sizeof(endMap) / sizeof(endMap[0]);

const wchar_t* success = L"You Win!";
const wchar_t* over = L"Dead";

namespace End {
	// Start
	void Initalize() {
		
	}

	// Update 
	void Update() {
		// scene change
		if (Input::IsKeyPressed(VK_ESCAPE)) {
			Game::g_SceneCurrent = Game::MENU_SCENE;
			Menu::Initalize();
		}
	}

	// Render
	void Render() {
		for (int i = 0; i < mapHeight; i++)
		{
			ConsoleRenderer::ScreenDrawStringW(0, i, endMap[i], FG_YELLOW);
		}

		if(Game::isGameSuccess)
			ConsoleRenderer::ScreenDrawStringW(26, 25, success, FG_YELLOW);
		else
			ConsoleRenderer::ScreenDrawStringW(28, 25, over, FG_YELLOW);
	}
}