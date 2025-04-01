#include <stdio.h>
#include <windows.h>
#include "ConsoleRenderer.h"
#include "Input.h"
#include "GameManager.h"
#include "MenuScene.h"
#include "InfoScene.h"
#include "PlayScene.h"
#include "EndScene.h"

/* ��ü ���� ������ �����ϴ� GameManager �Դϴ�.*/

namespace Game {
	// extern �ʱ�ȭ
	Scene g_SceneCurrent = Game::MENU_SCENE;
	bool isGameSuccess = false;

	// sound manager
	SoundManager& soundManager = SoundManager::getInstance();

	// Start
	void Initalize() {
		Menu::Initalize();
		isGameSuccess = false;
		Game::soundManager.InitSystem();
	}

	// Update : SceneCurrent�� ���� Update()ȣ��
	void Update() {
		// key input
		Input::Update();
		
		// update
		switch (Game::g_SceneCurrent)
		{
		case Game::MENU_SCENE:
			Menu::Update();
			break;
		case Game::INFO_SCENE:
			Info::Update();
			break;
		case Game::PLAY_SCENE:
			Play::Update();
			break;
		case Game::END_SCENE:
			End::Update();
			break;
		default:
			printf("������� �ȵǴµ�\n");
			break;
		}
	}

	// Render : SceneCurrent�� ���� Render()ȣ��  
	void Render() {
		ConsoleRenderer::ScreenClear();

		switch (Game::g_SceneCurrent)
		{
		case Game::MENU_SCENE:
			Menu::Render();
			break;
		case Game::INFO_SCENE:
			Info::Render();
			break;
		case Game::PLAY_SCENE:
			Play::Render();
			break;
		case Game::END_SCENE:
			End::Render();
			break;
		default:
			printf("������� �ȵǴµ�\n");
			break;
		}

		ConsoleRenderer::ScreenFlipping();
	}
}

// Main Game Loop
int main() {
	ConsoleRenderer::ScreenInit();
	Game::Initalize();

	while (true)
	{
		Game::Update();
		Game::Render();
	}

	ConsoleRenderer::ScreenRelease();
	return 0;
}