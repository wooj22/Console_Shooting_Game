#pragma once

class Player {
public:
	COORD pos = { 30, 57 };
	char playerChar = 'P';
	void Move(const wchar_t** playMap);
	void Shoot();
};
