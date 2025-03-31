#include "Boss.h"

// boss move :  {4, 4} ~ {55, 40} 내에서 랜덤 이동
void Boss::Move() {
	if (this->pos.Y < 8) {
		this->pos.Y++;
	}
	else {
		// 임시값 저장
		int nextX = this->pos.X;
		int nextY = this->pos.Y;

		int randomInt = rand() % 6;
		switch (randomInt)
		{
		case 0:
			nextX += 2;
			if(nextX >= 4 && nextX <= 55) this->pos.X = nextX;
			else break;
			break;
		case 1:
			nextX -= 2;
			if (nextX >= 4 && nextX <= 55) this->pos.X = nextX;
			else break;
			break;
		case 2:
			nextY += 2;
			if (nextY >= 8 && nextY <= 40) this->pos.Y = nextY;
			else break;
			break;
		case 3:
			nextY -= 2;
			if (nextY >= 8 && nextY <= 40) this->pos.Y = nextY;
			else break;
			break;
			
		default:
			break;
		}
	}
}

void Boss::Hit(int damage) {
	hp -= damage;
	if (hp <= 0) {
		hp = 0;
		isDie = true;
	}
	OutputDebugStringA("boss : hit...ㅜㅜ\n");
}

bool Boss::isCollision(SHORT x, SHORT y) {
	// Boss size : x = 1, y = 4   "Boss"
	if (this->pos.Y == y && 
		this->pos.X <= x && this->pos.X+3 >= y) 
		return true;
	else return false;
}