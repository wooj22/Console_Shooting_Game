#include <stdio.h>
#include "ConsoleRenderer.h"
#include "Input.h"
#include "Time.h"
#include "GameManager.h"
#include "PlayScene.h"
#include "EndScene.h"

namespace Play {
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

	// Player
	COORD g_Player = { 3, 57 };

	// Start
	void Initalize() {
		Time::Initialize();
	}

	// Update
	void Update() {
		// input & playControll
		Time::UpdateTime();
		if (Time::GetTotalTime() >= 0.1f) {
			PlayerMove();
			Time::Initialize();
		}
		
		// scene change
		if (Input::IsKeyPressed(VK_SPACE)) {
			Game::g_SceneCurrent = Game::END_SCENE;
			End::Initalize();
		}
	}

	// Render
	void Render() {
		// map
		for (int i = 0; i < mapHeight; i++)
		{
			ConsoleRenderer::ScreenDrawStringW(0, i, playMap[i], FG_GRAY | FOREGROUND_INTENSITY);
		}

		// player
		ConsoleRenderer::ScreenDrawChar(g_Player.X, g_Player.Y, 'P', FG_RED);
	}

	// Player Move
	void PlayerMove()
	{// 임시 좌표
		int nextX = g_Player.X;
		int nextY = g_Player.Y;

		// 입력 처리
		if (Input::IsKeyDown(VK_LEFT) && playMap[g_Player.Y][g_Player.X - 1] != L'▓') {
			nextX--;
		}
		if (Input::IsKeyDown(VK_RIGHT) && playMap[g_Player.Y][g_Player.X + 1] != L'▓') {
			nextX++;
		}
		if (Input::IsKeyDown(VK_UP)) {
			nextY--;
		}
		if (Input::IsKeyDown(VK_DOWN) && playMap[g_Player.Y + 1][g_Player.X] != L'▓') {
			nextY++;
		}

		// 경계 검사 (콘솔 창 크기 기준)
		if (nextX < 0) nextX = 0;
		if (nextX >= ConsoleRenderer::ScreenWidth()) nextX = ConsoleRenderer::ScreenWidth() - 1;
		if (nextY < 0) nextY = 0;
		if (nextY >= mapHeight) nextY = mapHeight - 1;

		// 최종 위치 업데이트
		g_Player.X = nextX;
		g_Player.Y = nextY;
	}
}
