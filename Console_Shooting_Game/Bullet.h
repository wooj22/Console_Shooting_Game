#pragma once

class Bullet {
public:
	COORD pos;
	char bulletChar = 'o';

	Bullet(int x, int y);
	void SetPos(int x, int y);
	COORD GetPos();
};
