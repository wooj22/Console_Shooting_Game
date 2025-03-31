#pragma once
#include <fmod.hpp>

// ½Ì±ÛÅæ »ç¿îµå ¸Å´ÏÀú
class SoundManager {
public:
	static SoundManager& getInstance() {
		static SoundManager instance;
		return instance;
	}

	FMOD::System* system = nullptr;
	FMOD::Sound* bgm_sound = nullptr;
	FMOD::Sound* sfx_sound = nullptr;
	FMOD::Channel* channel = nullptr;

	void InitSystem();
	void StopSound();
	void PlayBGM();
	void PlaySFX_Shoot();
	void PlaySFX_Hit();
	void PlaySFX_ItemPickUp();
	void PlaySFX_GameOver();
	void PlaySFX_GameSuccess();
};