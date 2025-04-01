#pragma comment(lib, "fmod_vc.lib")

#include <iostream>
#include "SoundManager.h"

/// FMOD 시스템 초기화
void SoundManager::InitSystem() {
	if (FMOD::System_Create((&this->system)) != FMOD_OK) {
		std::cerr << "FMOD 시스템 생성 실패!" << std::endl;
	}
	system->init(512, FMOD_INIT_NORMAL, nullptr);

	if (FMOD::System_Create((&this->system)) != FMOD_OK) {
		std::cerr << "FMOD 시스템 생성 실패!" << std::endl;
	}
	system->init(512, FMOD_INIT_NORMAL, nullptr);
}

/// All Sound Stop
void SoundManager::StopSound() {
	sfx_sound->release();
	bgm_sound->release();
	system->close();
}

/// BGM Play
void SoundManager::PlayBGM() {
	system->createSound("BGM_Main.wav", FMOD_DEFAULT, nullptr, &bgm_sound);
	system->playSound(bgm_sound, nullptr, false, &channel);
}

/// SFX Play
/// 메모리 누수 문제 Fix : &sfx_sound, &bgm_sound를 분리하고, sfx play마다 sfx_sound->release();
void SoundManager::PlaySFX_Shoot() {
	sfx_sound->release();
	system->createSound("SFX_Shoot.wav", FMOD_DEFAULT, nullptr, &sfx_sound);
	system->playSound(sfx_sound, nullptr, false, &channel);
}
void SoundManager::PlaySFX_Hit() {
	sfx_sound->release();
	system->createSound("SFX_Hit.wav", FMOD_DEFAULT, nullptr, &sfx_sound);
	system->playSound(sfx_sound, nullptr, false, &channel);
}

void SoundManager::PlaySFX_ItemPickUp() {
	sfx_sound->release();
	system->createSound("SFX_ItemPickUp.wav", FMOD_DEFAULT, nullptr, &sfx_sound);
	system->playSound(sfx_sound, nullptr, false, &channel);
}

void SoundManager::PlaySFX_GameOver() {
	sfx_sound->release();
	system->createSound("SFX_GameOver.wav", FMOD_DEFAULT, nullptr, &sfx_sound);
	system->playSound(sfx_sound, nullptr, false, &channel);
}

void SoundManager::PlaySFX_GameSuccess() {
	sfx_sound->release();
	system->createSound("SFX_GameSuccess.wav", FMOD_DEFAULT, nullptr, &sfx_sound);
	system->playSound(sfx_sound, nullptr, false, &channel);
}

void SoundManager::PlaySFX_Ui() {
	sfx_sound->release();
	system->createSound("SFX_Hit.wav", FMOD_DEFAULT, nullptr, &sfx_sound);
	system->playSound(sfx_sound, nullptr, false, &channel);
}