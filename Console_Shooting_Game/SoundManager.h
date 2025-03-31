#pragma once
#include <fmod.hpp>

// �̱��� ���� �Ŵ���
class SoundManager {
public:
	static SoundManager& getInstance() {
		static SoundManager instance;
		return instance;
	}

	FMOD::System* system = nullptr;
	FMOD::Sound* sound = nullptr;
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