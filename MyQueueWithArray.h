//
// Created by Patrick on 11/09/2024.
//

#ifndef SEMANA_4_MYQUEUEWITHARRAY_H
#define SEMANA_4_MYQUEUEWITHARRAY_H

//Vamos a hacer una cola. Aquí se usará una lista que de al frente y a la cola, y su respectiva lista.

#define MAX_QUEUE_SIZE 100

#include <iostream>

template<typename T>
class Queue {
    int frente;  // Índice de frente
    int cola;   // Índice de final
    T lista[MAX_QUEUE_SIZE];
public:
    Queue() : frente(0), cola(0) {}

    bool IsFull() {
        return frente == (cola + 1) % MAX_QUEUE_SIZE;
    }

    bool IsEmpty() {
        return frente == cola;
    }

    T front() {
        if (!(this->IsEmpty())) {
            return lista[(frente+1)%MAX_QUEUE_SIZE];  // El frente apunta al elemento actual
        } else {
            throw std::out_of_range("La cola está vacía.");
        }
    }

    void enqueue(T value) {
        if (!(this->IsFull())) {
            lista[cola] = value;
            cola = (cola + 1) % MAX_QUEUE_SIZE;
        } else {
            throw std::out_of_range("La cola esta llena");
        }
    }

    void dequeue() {
        if (!(this->IsEmpty())) {
            frente = (frente + 1) % MAX_QUEUE_SIZE;
        } else {
            throw std::out_of_range("La cola esta vacia");
        }
    }

};


#endif //SEMANA_4_MYQUEUEWITHARRAY_H
