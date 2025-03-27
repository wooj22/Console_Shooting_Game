#include "Bullet.h"

/*--------- Bullet --------*/
// 충돌 : 플레이어의 총알이 적과 충돌했을 때
bool PlayerBullet::OnTrrigerEndter2D() {
    return true;
}

// 충돌 : 적의 총알이 플레이와 충돌했을 때
bool EnemyBullet::OnTrrigerEndter2D() {
    return true;
}

/*---------- Bullet Single Linked List --------*/
// 소멸자
BulletList::~BulletList() {
    clear();
}

// 삽입 : 리스트의 마지막에 추가
void BulletList::insert(Bullet* newBullet) {
    if (!head) {
        head = newBullet;
    }
    else {
        Bullet* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newBullet;
    }
}

// 삭제 : targetBullet을 찾아서 삭제
void BulletList::remove(Bullet* targetBullet) {
    if (!head) return;

    if (head == targetBullet) {
        Bullet* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Bullet* current = head;
    while (current->next && current->next != targetBullet) {
        current = current->next;
    }

    if (current->next) {
        Bullet* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

// 삭제 : 모든 노드 삭제
void BulletList::clear() {
    Bullet* current = head;
    while (current) {
        Bullet* nextBullet = current->next;
        delete current;
        current = nextBullet;
    }
    head = nullptr;
}