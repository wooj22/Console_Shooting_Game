#include "SoundManager.h"

#include <iostream>
#include <fmod.hpp>

#pragma comment(lib, "fmod_vc.lib")

int main()
{
	FMOD::System* system = nullptr;
	FMOD::Sound* sound = nullptr;
	FMOD::Channel* channel = nullptr;

	// FMOD 시스템 초기화
	if (FMOD::System_Create(&system) != FMOD_OK) {
		std::cerr << "FMOD 시스템 생성 실패!" << std::endl;
		return -1;
	}
	system->init(512, FMOD_INIT_NORMAL, nullptr);

	// 오디오 파일 로드
	if (system->createSound("wave.mp3", FMOD_DEFAULT, nullptr, &sound) != FMOD_OK) {
		std::cerr << "사운드 로드 실패!" << std::endl;
		return -1;
	}

	// 오디오 재생
	system->playSound(sound, nullptr, false, &channel);

	std::cout << "Press Enter to stop..." << std::endl;
	std::cin.get();  // 사용자가 Enter 입력 시 종료

	// 정리
	sound->release();
	system->close();
	system->release();

	return 0;
}
