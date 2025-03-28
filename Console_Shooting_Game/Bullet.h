#pragma once
#include <Windows.h>

/// PlayerBullet, EnemyBullet�� ��� ��� ���� (Base)Bullet Class�� �����
/// (Base)Bullet ������ ����Ʈ�� ��ĳ���� �ؼ� �߰��Ѵ�.
/// ����Ʈ �ȿ� Bullet�� �ٿ�ĳ�����ؼ� PlayerBullet, EnemyBullet�� ����� �����Ѵ�.
/// ! �Ϸ��������� ���潺 �帣�� ����, ���� �Ѿ� �Ƚ��ϴ�(EnemyBullet ��� X)

/*----------Bullet (Node) Data--------*/
class Bullet {
public:
    COORD pos;
    char body;
    Bullet* next;

    Bullet(int x, int y, char symbol) : pos({ (SHORT)x, (SHORT)y }), body(symbol), next(nullptr) {}
    void SetPos(int x, int y) { pos.X = x; pos.Y = y; }
    COORD GetPos() { return pos; }
};

class PlayerBullet : public Bullet {
public:
    PlayerBullet(int x, int y) : Bullet(x, y, '!') {}
    bool OnTriggerEnter2D();
};

class EnemyBullet : public Bullet {
public:
    EnemyBullet(int x, int y) : Bullet(x, y, 'V') {}
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
