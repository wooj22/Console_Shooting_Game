#include <stdio.h>
#include "ConsoleRenderer.h"
#include "Input.h"
#include "GameManager.h"
#include "MenuScene.h"
#include "PlayScene.h"

// Map Data
const wchar_t* infoMap[] = {

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
L"                      < 플레이어 조작 >                      ",
L"                                                            ",
L"                플레이어 이동 [←] [→] [↑] [↓]                ",
L"                플레이어 공격  [Spacebar]                    ",
L"                                                            ",
L"                                                            ",
L"                      < 아이템 종류 >                        ",
L"                                                            ",
L"                  H : 체력 회복 포션                         ",
L"                  P : 공격력, 공속 증가 포션                  ",
L"                  S : 이속 포션                              ",
L"                                                            ",
L"                                                            ",
L"                     < 게임 성공/실패 >                      ",
L"                                                            ",
L"                  Boss를 죽이면 게임 성공!                    ",
L"              플레이어의 HP가 다 닳으면 게임 실패...           ",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                                                            ",
L"                >>  Mene 화면으로[Spacebar]                  ",
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
const int infoMapMapHeight = sizeof(infoMap) / sizeof(infoMap[0]);

namespace Info {

	// Start
	void Initalize() {

	}

	// Update 
	void Update() {
		// scene change
		if (Input::IsKeyPressed(VK_SPACE)) {
			Game::soundManager.PlaySFX_Shoot();
			Game::g_SceneCurrent = Game::MENU_SCENE;
			Menu::Initalize();
		}
	}

	// Render
	void Render() {
		for (int i = 0; i < infoMapMapHeight; i++)
		{
			ConsoleRenderer::ScreenDrawStringW(0, i, infoMap[i], FG_YELLOW);
		}
	}
}
