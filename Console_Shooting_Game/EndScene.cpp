#include <stdio.h>
#include "ConsoleRenderer.h"
#include "Input.h"
#include "Time.h"
#include "GameManager.h"
#include "MenuScene.h"
#include "EndScene.h"

/*--------------- Data ------------------*/
const wchar_t* win[] = {

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
L"        __   __                _    _  _         _          ",
L"        | | / /               | |  | |(_)       | |         ",
L"        |_ V /   ___   _   _  | |  | | _  _ __  | |         ",
L"          | /   / _ | | | | | | |/|| || || '_  || |         ",
L"          | |  | (_) || |_| | |  /|  /| || | | ||_|         ",
L"          |_|   |___/  |__,_| |/  |/  |_||_| |_|(_)         "
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                        press [ESC]                         ",
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

const wchar_t* over[] = {

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
L"                 ______                   _                 ",
L"                 |  _  |                 | |                ",
L"                 | | | |  ___   __ _   __| |                ",
L"                 | | | | / _ | / _` | / _` |                ",
L"                 | |/ / |  __/| (_| || (_| |                ",
L"                 |___/   |___| |__,_| |__,_|                "
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                        press [ESC]                         ",
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

const int winMapHeight = sizeof(win) / sizeof(win[0]);
const int overMapHeight = sizeof(over) / sizeof(over[0]);

/*--------------- End ------------------*/
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
		if(Game::isGameSuccess)
			for (int i = 0; i < winMapHeight; i++)
				ConsoleRenderer::ScreenDrawStringW(0, i, win[i], FG_YELLOW);
		else
			for (int i = 0; i < overMapHeight; i++)
				ConsoleRenderer::ScreenDrawStringW(0, i, over[i], FG_GRAY);
	}
}