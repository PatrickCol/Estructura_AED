#include <vector>
#include <iostream>

#define MAX_STACK_SIZE 100

template<typename T>
class Stack {
    int tope; //índice al tope del stack
    T list[MAX_STACK_SIZE]; //Lista con todos los valores
public:
    Stack() : tope(-1) {}

    bool IsFull() { //Comprueba si el tope no alcanza al máximo que propusimos
        return tope >= MAX_STACK_SIZE - 1;
    }

    bool IsEmpty() { //Comprueba si el tope esta en -1 (o sea que esta vacío).
        return tope == -1;
    }

    T top() { //Ya que tope apunta al tope de la lista, solo lo devuelves
        if (tope > -1) {
            return list[tope];
        } else {
            throw std::out_of_range("La lista esta vacia");
        }
    }

    void push(T value) {
        if (!(this->IsFull())) {
            tope++;
            list[tope] = value;
        } else {
            std::cout << "La lista ya esta llena.";
        }
    }

    T pop() {
        if (tope >= 0) {
            T val = list[tope];
            tope--;
            return val;
        } else {
            throw std::out_of_range("La lista esta vacia");
        }
    }
};


#define MAX_QUEUE_SIZE 100

template<typename T>
class Queue {
    int frente;  // Índice de frente
    int cola;   // Índice de final
    T lista[MAX_QUEUE_SIZE];
public:
    Queue() : frente(0), cola(0) {}

    bool isFull() {
        return frente == ((cola + 1) % MAX_QUEUE_SIZE);
    }

    bool isEmpty() {
        return frente == cola;
    }

    T front() {
        if (!(this->isEmpty())) {
            return lista[(frente+1)%MAX_QUEUE_SIZE];  // El frente apunta al elemento actual
        } else {
            throw std::out_of_range("La cola está vacía.");
        }
    }

    void enqueue(T value) {
        if (!(this->isFull())) {
            cola = (cola + 1) % MAX_QUEUE_SIZE;
            lista[cola] = value;
        } else {
            throw std::out_of_range("La cola esta llena");
        }
    }

    void dequeue() {
        if (!(this->isEmpty())) {
            frente = (frente + 1) % MAX_QUEUE_SIZE;
        } else {
            throw std::out_of_range("La cola esta vacia");
        }
    }

};



//Nosotros trabajamos con matrices que representan grafos.
using AdjMat = std::vector<std::vector<int>>;
int N = 10;

auto adjMat = AdjMat(N,std::vector<int>(N, 0));

/* Empecemos con el algoritmo de búsqueda a profundidad (DFS):
 * 1. Vas a crear un vector de tipos bool donde dices si los nodos en esas posiciones fueron visitadas
 * 2. Creas una pila donde primero lo llenas con el nodo donde comienzas.
 * 3. Mientras no este vacío la pila, sacas el tope, y miras si no fue visitado para marcarlo.
 * Luego añades a la cola sus nodos adyacentes no visitados
 */

void DFS(int start) {
    std::vector<bool> visited(N, false); // Vector para marcar nodos visitados
    Stack<int> s;
    s.push(start);

    std::cout << "DFS traversal starting from node " << start << ": ";
    while (!s.IsEmpty()) {
        int node = s.top();
        s.pop();

        if (!visited[node]) {
            std::cout << node << " ";
            visited[node] = true;

            //Visita los nodos adyacentes, empujándolos en el stack
            for (int i = N - 1; i >= 0; --i) {
                if (adjMat[node][i] == 1 && !visited[i]) {
                    s.push(i);
                }
            }
        }
    }
    std::cout << std::endl;
}



/* Ahora vamos con el algoritmo de búsqueda en amplitud (BFS)
 * 1. Vas a crear un vector de tipos bool donde dices si los nodos en esas posiciones fueron visitadas
 * 2. Creas una cola donde primero lo llenas con el nodo donde comienzas.
 * 3. Mientras no este vacío la cola, sacas el tope, y miras si no fue visitado para marcarlo.
 * Luego añades a la cola sus nodos adyacentes no visitados
 */

void BFS(int start) {
    std::vector<bool> visited(N, false); // Vector para marcar nodos visitados
    Queue<int> s;
    s.enqueue(start);

    std::cout << "DFS traversal starting from node " << start << ": ";
    while (!s.isEmpty()) {
        int node = s.front();
        s.dequeue();

        if (!visited[node]) {
            std::cout << node << " ";
            visited[node] = true;

            //Visita los nodos adyacentes, empujándolos en el stack
            for (int i = N - 1; i >= 0; --i) {
                if (adjMat[node][i] == 1 && !visited[i]) {
                    s.enqueue(i);
                }
            }
        }
    }
    std::cout << std::endl;
}
