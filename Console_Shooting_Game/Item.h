#pragma once
#include <windows.h>

/// Bullet List�� ���� ����. (Bullet.h ����)
/// Bullet List�� ���׸����� ����� ������ �ٽ� �����ؾߵż� �켱 Item Ÿ���� ����Ʈ�� ���� �ۼ��Ͽ���.

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
