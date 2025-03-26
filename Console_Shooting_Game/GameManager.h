#pragma once

namespace Game {
	// enum으로 Scene 관리
	enum Scene {
		MENU_SCENE,
		PLAY_SCENE,
		END_SCENE
	};

	extern Scene g_SceneCurrent;
	extern bool g_isDie;
}
