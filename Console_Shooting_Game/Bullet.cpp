#include "Bullet.h"

BulletList::~BulletList() {
    clear();
}

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

void BulletList::clear() {
    Bullet* current = head;
    while (current) {
        Bullet* nextBullet = current->next;
        delete current;
        current = nextBullet;
    }
    head = nullptr;
}