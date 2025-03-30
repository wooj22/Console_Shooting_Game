#include "Bullet.h"

/// Player Bullet Move
void PlayerBullet::Move() {
    this->pos.Y--;
    if (this->pos.Y <= 0)
        isGoal = true;
}

/// Enemy Bullet Move
void EnemyBullet::Move() {
    this->pos.Y++;
    if (this->pos.Y >= 59)
        isGoal = true;
}

/// 소멸자
BulletList::~BulletList() {
    Clear();
}

/// 삽입 : 리스트의 마지막에 추가
void BulletList::Insert(Bullet* newBullet) {
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

/// 삭제 : targetBullet을 찾아서 삭제
void BulletList::Remove(Bullet* targetBullet) {
    // 리스트가 비었을 경우
    if (!head) return;

    // 삭제할 bullet이 헤드(첫번째 원소)일 경우
    if (head == targetBullet) {
        Bullet* temp = head;
        if (targetBullet->next)
            head = head->next;
        else
            head = nullptr;
        delete temp;
        return;
    }

    // 삭제할 bullet이 헤드가 아닐 경우
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

/// 삭제 : 모든 노드 삭제
void BulletList::Clear() {
    Bullet* current = head;
    while (current) {
        Bullet* nextBullet = current->next;
        delete current;
        current = nextBullet;
    }
    head = nullptr;
}