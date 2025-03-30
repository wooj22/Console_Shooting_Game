#include "Item.h"

/// �̵�
void Item::Move()
{
	this->pos.Y++;
}

/// �浹
bool Item::isCollision(SHORT x, SHORT y) {
	if (this->pos.X == x && this->pos.Y == y) return true;
	else return false;
}

/// �Ҹ���
ItemList::~ItemList() {
    Clear();
}

/// ���� : ����Ʈ�� �������� �߰�
void ItemList::Insert(Item* newItem) {
    if (!head) {
        head = newItem;
    }
    else {
        Item* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newItem;
    }
}

/// ���� : targetBullet�� ã�Ƽ� ����
void ItemList::Remove(Item* targetItem) {
    // ����Ʈ�� ����� ���
    if (!head) return;

    // ������ bullet�� ���(ù��° ����)�� ���
    if (head == targetItem) {
        Item* temp = head;
        if (targetItem->next)
            head = head->next;
        else
            head = nullptr;
        delete temp;
        return;
    }

    // ������ bullet�� ��尡 �ƴ� ���
    Item* current = head;
    while (current->next && current->next != targetItem) {
        current = current->next;
    }
    if (current->next) {
        Item* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

/// ���� : ��� ��� ����
void ItemList::Clear() {
    Item* current = head;
    while (current) {
        Item* nextItem = current->next;
        delete current;
        current = nextItem;
    }
    head = nullptr;
}