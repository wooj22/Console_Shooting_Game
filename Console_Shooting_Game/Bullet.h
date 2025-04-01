#pragma once
#include <Windows.h>

/// PlayerBullet, EnemyBullet을 모두 담기 위해 (Base)Bullet Class를 만들고
/// Bullet* 타입의 데이터를 담는 BulletList에 업캐스팅 해서 추가한다.
/// BulletList내의 Bullet을 다운캐스팅해서 PlayerBullet, EnemyBullet의 멤버에 접근한다.

/*---------- Bullet (Node) Data --------*/
class Bullet {
public:
    COORD pos;
    char body;
    bool isGoal;
    Bullet* next;

    Bullet(SHORT x, SHORT y, char body) : pos({ x, y }), body(body), isGoal(false), next(nullptr) {}
};

class PlayerBullet : public Bullet {
public:
    PlayerBullet(SHORT x, SHORT y, char body = '^') : Bullet(x, y, body) {}
    void Move();
};

class EnemyBullet : public Bullet {
public:
    EnemyBullet(SHORT x, SHORT y) : Bullet(x, y, '*') {}
    void Move();
};

class BossBullet : public Bullet {
public:
    BossBullet(SHORT x, SHORT y) : Bullet(x, y, '#') {}
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
