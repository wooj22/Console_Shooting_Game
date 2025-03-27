#pragma once

/*----------Bullet Node Data--------*/
class Bullet {
	Bullet* next;
};

class PlayerBullet : Bullet {
public:
	COORD pos;
	char body = 'n';

	PlayerBullet(int x, int y);
	void SetPos(int x, int y);
	COORD GetPos();
};

class EnemyBullet : Bullet {
public:
	COORD pos;
	char body = 'u';

	EnemyBullet(int x, int y);
	void SetPos(int x, int y);
	COORD GetPos();
};

/*----------Single Linked List--------*/
// Node를 Bullet으로 변경
class Node {
public:
	int data;
	Node* next;

	Node(int value);
};

class SinglyLinkedList {
private:
	Node* head;
public:
	SinglyLinkedList();
	~SinglyLinkedList();

	void insert(int value);
	void remove(int value);
};