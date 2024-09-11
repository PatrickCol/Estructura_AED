//
// Created by Patrick on 11/09/2024.
//

#ifndef SEMANA_4_MYSTACKWITHARRAY_H
#define SEMANA_4_MYSTACKWITHARRAY_H

//En este caso, el stack lo construimos con el uso de un array.
//Se conformará de una lista de un máximo de tamaño y un valor top que será el índice al último valor agregado

#define MAX_STACK_SIZE 10
#include <iostream>

template<typename T>
class Stack{
    int tope; //índice al tope del stack
    T list[MAX_STACK_SIZE]; //Lista con todos los valores
public:
    Stack(): tope(-1){}

    bool IsFull(){ //Comprueba si el tope no alcanza al máximo que propusimos
        return tope >= MAX_STACK_SIZE-1;
    }

    bool IsEmpty(){ //Comprueba si el tope esta en -1 (o sea que esta vacío).
        return tope == -1;
    }

    T top(){ //Ya que tope apunta al tope de la lista, solo lo devuelves
        if (tope > -1){
            return list[tope];
        } else{
            throw std::out_of_range("La lista esta vacia");
        }
    }

    void push(T value){
        if (!(this->IsFull())){
            tope++;
            list[tope] = value;
        } else{
            std::cout<<"La lista ya esta llena.";
        }
    }

    T pop(){
        if (tope>=0){
            T val = list[tope];
            tope--;
            return val;
        }
        else{
            throw std::out_of_range("La lista esta vacia");
        }
    }

};



#endif //SEMANA_4_MYSTACKWITHARRAY_H
