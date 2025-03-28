#pragma once
#include <Windows.h>

/// PlayerBullet, EnemyBullet�� ��� ��� ���� (Base)Bullet Class�� �����
/// (Base)Bullet ������ ����Ʈ�� ��ĳ���� �ؼ� �߰��Ѵ�.
/// ����Ʈ �ȿ� Bullet�� �ٿ�ĳ�����ؼ� PlayerBullet, EnemyBullet�� ����� �����Ѵ�.

/*----------Bullet (Node) Data--------*/
class Bullet {
public:
    COORD pos;
    char body;
    Bullet* next;

    Bullet(SHORT x, SHORT y, char symbol) : pos({ x, y }), body(symbol), next(nullptr) {}
    void SetPos(int x, int y) { pos.X = x; pos.Y = y; }
    COORD GetPos() { return pos; }
};

class PlayerBullet : public Bullet {
public:
    PlayerBullet(SHORT x, SHORT y) : Bullet(x, y, '!') {}
    bool OnTriggerEnter2D();
};

class EnemyBullet : public Bullet {
public:
    EnemyBullet(SHORT x, SHORT y) : Bullet(x, y, 'V') {}
    bool OnTriggerEnter2D();
};

/*---------- Bullet Single Linked List --------*/
class BulletList {
public:
    Bullet* head; 
    BulletList() : head(nullptr) {}
    ~BulletList();

    void Insert(Bullet* newBullet);
    void Remove(Bullet* targetBullet);
    void Clear();
};
