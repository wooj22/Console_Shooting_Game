#include "Bullet.h"

/*--------- Bullet --------*/
// �浹 : �÷��̾��� �Ѿ��� ���� �浹���� ��
bool PlayerBullet::OnTrrigerEndter2D() {
    return true;
}

// �浹 : ���� �Ѿ��� �÷��̿� �浹���� ��
bool EnemyBullet::OnTrrigerEndter2D() {
    return true;
}

/*---------- Bullet Single Linked List --------*/
// �Ҹ���
BulletList::~BulletList() {
    clear();
}

// ���� : ����Ʈ�� �������� �߰�
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

// ���� : targetBullet�� ã�Ƽ� ����
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

// ���� : ��� ��� ����
void BulletList::clear() {
    Bullet* current = head;
    while (current) {
        Bullet* nextBullet = current->next;
        delete current;
        current = nextBullet;
    }
    head = nullptr;
}