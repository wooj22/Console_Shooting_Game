#include "Bullet.h"

// 소멸자
BulletList::~BulletList() {
    Clear();
}

// 삽입 : 리스트의 마지막에 추가
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

// 삭제 : targetBullet을 찾아서 삭제
void BulletList::Remove(Bullet* targetBullet) {
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
void BulletList::Clear() {
    Bullet* current = head;
    while (current) {
        Bullet* nextBullet = current->next;
        delete current;
        current = nextBullet;
    }
    head = nullptr;
}