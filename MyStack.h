//
// Created by Patrick on 9/09/2024.
//

#ifndef SEMANA_4_MYSTACK_H
#define SEMANA_4_MYSTACK_H

#include <iostream>

template<typename T>
struct Node {
    T data;
    Node *next;
};

template<typename V>
class Stack {
    Node<V> *front = nullptr;
public:
    void push(int data) {
        Node<V> *nodo = new Node<V>;
        nodo->data = data;

        nodo->next = front;
        front = nodo;
    }

    V pop() {
        if (front == nullptr) {
            throw std::out_of_range("La lista esta vacía.");
        }
        auto temp = front;
        front = front->next;
        int val = temp->data;

        delete temp;
        return val;
    }

    V top() {
        if (front == nullptr) {
            throw std::out_of_range("La lista esta vacía.");
        }

        return front->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }

};

#endif //SEMANA_4_MYSTACK_H
