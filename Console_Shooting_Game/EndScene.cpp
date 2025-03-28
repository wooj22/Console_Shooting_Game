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
L"                          Your Die !                        ",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                       press [spacebar]                     ",
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


namespace End {
	// Start
	void Initalize() {
		
	}

	// Update 
	void Update() {
		// scene change
		if (Input::IsKeyPressed(VK_SPACE)) {
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
	}
}