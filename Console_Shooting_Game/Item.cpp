#include "Item.h"

/// 이동
void Item::Move()
{
	this->pos.Y++;
}

/// 충돌
bool Item::isCollision(SHORT x, SHORT y) {
	if (this->pos.X == x && this->pos.Y == y) return true;
	else return false;
}

/// 소멸자
ItemList::~ItemList() {
    Clear();
}

/// 삽입 : 리스트의 마지막에 추가
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

/// 삭제 : targetBullet을 찾아서 삭제
void ItemList::Remove(Item* targetItem) {
    // 리스트가 비었을 경우
    if (!head) return;

    // 삭제할 bullet이 헤드(첫번째 원소)일 경우
    if (head == targetItem) {
        Item* temp = head;
        if (targetItem->next)
            head = head->next;
        else
            head = nullptr;
        delete temp;
        return;
    }

    // 삭제할 bullet이 헤드가 아닐 경우
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

/// 삭제 : 모든 노드 삭제
void ItemList::Clear() {
    Item* current = head;
    while (current) {
        Item* nextItem = current->next;
        delete current;
        current = nextItem;
    }
    head = nullptr;
}