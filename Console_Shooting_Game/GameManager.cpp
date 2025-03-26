#include <stdio.h>
#include <windows.h>
#include "ConsoleRenderer.h"
#include "Input.h"
#include "GameManager.h"
#include "MenuScene.h"
#include "PlayScene.h"
#include "EndScene.h"

namespace Game {
	// 초기화
	Scene g_SceneCurrent = Game::MENU_SCENE;
	bool g_isDie = false;

	// Start : 게임 시작
	void Initalize() {
		Menu::Initalize();
	}

	// Update : SceneCurrent에 따라 Update()호출
	void Update() {
		// key input
		Input::Update();

		if (Input::IsKeyDown(VK_DELETE)) {
			Game::g_isDie = true;
		}

		// update
		switch (Game::g_SceneCurrent)
		{
		case Game::MENU_SCENE:
			Menu::Update();
			break;
		case Game::PLAY_SCENE:
			Play::Update();
			break;
		case Game::END_SCENE:
			End::Update();
			break;
		default:
			printf("여기오면 안되는데\n");
			break;
		}
	}

	// Render : SceneCurrent에 따라 Render()호출  
	void Render() {
		ConsoleRenderer::ScreenClear();

		switch (Game::g_SceneCurrent)
		{
		case Game::MENU_SCENE:
			Menu::Render();
			break;
		case Game::PLAY_SCENE:
			Play::Render();
			break;
		case Game::END_SCENE:
			End::Render();
			break;
		default:
			printf("여기오면 안되는데\n");
			break;
		}

		ConsoleRenderer::ScreenFlipping();
	}
}

// Main : 게임 진행
// [Spacebar]를 누르면 씬을 전환합니다.
// 루프 종료가 없으니 주의하세요
int main() {
	ConsoleRenderer::ScreenInit();
	Game::Initalize();

	while (!Game::g_isDie)
	{
		Game::Update();
		Game::Render();
	}

	ConsoleRenderer::ScreenRelease();
	return 0;
}