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

/// Sound Stop
void SoundManager::StopSound() {
	// 정리
	sound->release();
	system->close();
	sound->release();
}

/// BGM Play
void SoundManager::PlayBGM() {
	system->createSound("BGM_Main.wav", FMOD_DEFAULT, nullptr, &sound);
	system->playSound(sound, nullptr, false, &channel);
}

/// SFX Play
void SoundManager::PlaySFX_Shoot() {
	system->createSound("SFX_Shoot.wav", FMOD_DEFAULT, nullptr, &sound);
	system->playSound(sound, nullptr, false, &channel);
}
void SoundManager::PlaySFX_Hit() {
	system->createSound("SFX_Hit.wav", FMOD_DEFAULT, nullptr, &sound);
	system->playSound(sound, nullptr, false, &channel);
}

void SoundManager::PlaySFX_ItemPickUp() {
	system->createSound("SFX_ItemPickUp.wav", FMOD_DEFAULT, nullptr, &sound);
	system->playSound(sound, nullptr, false, &channel);
}

void SoundManager::PlaySFX_GameOver() {
	system->createSound("SFX_GameOver.wav", FMOD_DEFAULT, nullptr, &sound);
	system->playSound(sound, nullptr, false, &channel);
}
void SoundManager::PlaySFX_GameSuccess() {
	system->createSound("SFX_GameSuccess.wav", FMOD_DEFAULT, nullptr, &sound);
	system->playSound(sound, nullptr, false, &channel);
}