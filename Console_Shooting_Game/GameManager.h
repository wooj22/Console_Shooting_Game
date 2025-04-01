#pragma once
#include "SoundManager.h"

namespace Game {
	enum Scene {
		MENU_SCENE,
		INFO_SCENE,
		PLAY_SCENE,
		END_SCENE
	};

	extern Scene g_SceneCurrent;
	extern bool isGameSuccess;
	extern SoundManager& soundManager;
}
