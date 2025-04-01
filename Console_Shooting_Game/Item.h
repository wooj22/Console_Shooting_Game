#pragma once
#include <windows.h>

/// Bullet List와 같은 구조. (Bullet.h 참고)
/// Bullet List을 제네릭으로 만들까 했지만 다시 공부해야돼서 우선 Item 타입의 리스트를 따로 작성하였다.

/*---------- Item (Node) Data --------*/
class Item {
public:
	COORD pos;
	char body;
	bool isGoal;
	Item* next;

	Item(SHORT x, SHORT y, char body) : pos({ x, y }), body(body), isGoal(false), next(nullptr) {};
	void Move();
	bool isCollision(SHORT x, SHORT y);
};

class HpPosion : public Item{
public:
	HpPosion(SHORT x, SHORT y, char body = 'H') : Item(x, y, body) {};
};

class PowerPosion : public Item {
public:
	PowerPosion(SHORT x, SHORT y, char body = 'P') : Item(x, y, body) {};
};

class SpeedPosion : public Item {
public:
	SpeedPosion(SHORT x, SHORT y, char body = 'S') : Item(x, y, body) {};
};


/*---------- Item Single Linked List --------*/
class ItemList {
public:
	Item* head;
	ItemList() : head(nullptr) {}
	~ItemList();

	void Insert(Item* newItem);
	void Remove(Item* targetItem);
	void Clear();
};
