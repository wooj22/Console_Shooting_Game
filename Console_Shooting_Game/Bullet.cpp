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

/// �Ҹ���
BulletList::~BulletList() {
    Clear();
}

/// ���� : ����Ʈ�� �������� �߰�
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

/// ���� : targetBullet�� ã�Ƽ� ����
void BulletList::Remove(Bullet* targetBullet) {
    // ����Ʈ�� ����� ���
    if (!head) return;

    // ������ bullet�� ���(ù��° ����)�� ���
    if (head == targetBullet) {
        Bullet* temp = head;
        if (targetBullet->next)
            head = head->next;
        else
            head = nullptr;
        delete temp;
        return;
    }

    // ������ bullet�� ��尡 �ƴ� ���
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

/// ���� : ��� ��� ����
void BulletList::Clear() {
    Bullet* current = head;
    while (current) {
        Bullet* nextBullet = current->next;
        delete current;
        current = nextBullet;
    }
    head = nullptr;
}