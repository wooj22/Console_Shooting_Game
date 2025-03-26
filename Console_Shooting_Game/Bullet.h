#pragma once

class Bullet {
public:
	COORD pos;
	char bulletChar = 'o';

	void SetPos(int x, int y);
};
