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
    bool isGoal;
    Bullet* next;

    Bullet(SHORT x, SHORT y, char symbol) : pos({ x, y }), body(symbol), isGoal(false), next(nullptr) {}
    void SetPos(int x, int y) { pos.X = x; pos.Y = y; }
     COORD GetPos() { return pos; }
};

class PlayerBullet : public Bullet {
public:
    PlayerBullet(SHORT x, SHORT y) : Bullet(x, y, '^') {}
    void Move();
};

class EnemyBullet : public Bullet {
public:
    EnemyBullet(SHORT x, SHORT y) : Bullet(x, y, '*') {}
    void Move();
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
