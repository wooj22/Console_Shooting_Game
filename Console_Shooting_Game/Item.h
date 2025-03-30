#pragma once
#include <windows.h>

/// Bullet List�� ���� ����. (Bullet.h ����)
/// Bullet List�� ���׸����� ����� ������ �ٽ� �����ؾߵż� �켱 Item Ÿ���� ����Ʈ�� ���� �ۼ��Ͽ���.

/*---------- Item (Node) Data --------*/
class Item {
public:
	COORD pos;
	char body;
	Item* next;

	Item(SHORT x, SHORT y, char body) : pos({ x, y }), body(body), next(nullptr) {};
	void Move();
	bool isCollision(SHORT x, SHORT y);
};

class HpPosion : public Item{
public:
	int hpUp = 10;
	HpPosion(SHORT x, SHORT y, char body = 'H') : Item(x, y, body) {};
};

class PowerUpPosion : public Item {
public:
	int powerUp = 5;
	PowerUpPosion(SHORT x, SHORT y, char body = 'P') : Item(x, y, body) {};
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
