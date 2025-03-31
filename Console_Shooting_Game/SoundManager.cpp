#include "SoundManager.h"

#include <iostream>
#include <fmod.hpp>

#pragma comment(lib, "fmod_vc.lib")

int main()
{
	FMOD::System* system = nullptr;
	FMOD::Sound* sound = nullptr;
	FMOD::Channel* channel = nullptr;

	// FMOD �ý��� �ʱ�ȭ
	if (FMOD::System_Create(&system) != FMOD_OK) {
		std::cerr << "FMOD �ý��� ���� ����!" << std::endl;
		return -1;
	}
	system->init(512, FMOD_INIT_NORMAL, nullptr);

	// ����� ���� �ε�
	if (system->createSound("wave.mp3", FMOD_DEFAULT, nullptr, &sound) != FMOD_OK) {
		std::cerr << "���� �ε� ����!" << std::endl;
		return -1;
	}

	// ����� ���
	system->playSound(sound, nullptr, false, &channel);

	std::cout << "Press Enter to stop..." << std::endl;
	std::cin.get();  // ����ڰ� Enter �Է� �� ����

	// ����
	sound->release();
	system->close();
	system->release();

	return 0;
}
