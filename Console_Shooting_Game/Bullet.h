#pragma once

class PlayerBullet {
public:
	COORD pos;
	char body = 'n';

	PlayerBullet(int x, int y);
	void SetPos(int x, int y);
	COORD GetPos();
};

class EnemyBullet {
public:
	COORD pos;
	char body = 'u';

	EnemyBullet(int x, int y);
	void SetPos(int x, int y);
	COORD GetPos();
};