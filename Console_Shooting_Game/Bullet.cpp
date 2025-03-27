#include "ConsoleRenderer.h"
#include "Time.h"
#include "Bullet.h"

Node::Node(int value) : data(value), next(nullptr) {}

SinglyLinkedList::SinglyLinkedList() : head(nullptr) {}

SinglyLinkedList::~SinglyLinkedList() {
    Node* current = head;
    while (current) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void SinglyLinkedList::insert(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void SinglyLinkedList::remove(int value) {
    if (!head) return;

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    while (current->next && current->next->data != value) {
        current = current->next;
    }

    if (current->next) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

/*-------------- Player Bullet ---------------*/
PlayerBullet::PlayerBullet(int x, int y) {
	this->pos.X = x;
	this->pos.Y = y;
}

void PlayerBullet::SetPos(int x, int y) {
	this->pos.X = x;
	this->pos.Y = y;
}

COORD PlayerBullet::GetPos() {
	return this->pos;
}

/*-------------- Enemy Bullet ---------------*/
EnemyBullet::EnemyBullet(int x, int y) {
	this->pos.X = x;
	this->pos.Y = y;
}

void EnemyBullet::SetPos(int x, int y) {
	this->pos.X = x;
	this->pos.Y = y;
}

COORD EnemyBullet::GetPos() {
	return this->pos;
}