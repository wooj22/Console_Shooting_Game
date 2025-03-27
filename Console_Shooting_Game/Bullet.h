#pragma once
#include <Windows.h>

/// PlayerBullet, EnemyBullet을 모두 담기 위해 (Base)Bullet Class를 만들고
/// (Base)Bullet 형식의 리스트에 업캐스팅 해서 추가한다.
/// 리스트 안에 Bullet을 다운캐스팅해서 PlayerBullet, EnemyBullet의 멤버에 접근한다.

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

    void insert(Bullet* newBullet);
    void remove(Bullet* targetBullet);
    void clear();
};
