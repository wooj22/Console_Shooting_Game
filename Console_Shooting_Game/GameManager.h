#pragma once

namespace Game {
	// enum���� Scene ����
	enum Scene {
		MENU_SCENE,
		PLAY_SCENE,
		END_SCENE
	};

	extern Scene g_SceneCurrent;
	extern bool g_isDie;
}
