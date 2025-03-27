#pragma once

class Node {
public:
    int data;
    Node* next;

    Node(int value);
};

class SinglyLinkedList {
private:
    Node* head;
public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    void insert(int value);
    void remove(int value);
};

