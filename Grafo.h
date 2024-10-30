#pragma once

#include <iostream>
#include <vector>
#include <climits>
//Tenemos que crear un grafo. Pero también tenemos diversas opciones del que salen distintas estructuras

//Grafo sin direcciones y no ponderada
class UndirectedGraph {
private:
    int vertices; //Número de vértices
    std::vector<std::vector<int>> adjMatrix; //Matriz de adyacencia

public:
    UndirectedGraph(int v) : vertices(v) {
        adjMatrix = std::vector<std::vector<int>>(v, std::vector<int>(v, 0));
    }

    //Agregamos una arista entre u y v
    void addEdge(int u, int v) {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1; //Como el grafo es no dirigido, también se crea una arista de v a u
        }
    }

    //Impresión de la matriz de adyacencia
    void printGraph() {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << '\n';
        }
    }

    int countEdgesInCycle() {
        std::vector<int> state(vertices, 0); // 0 = no visitado, 1 = visitado en camino actual, 2 = completado
        int edgeCount = 0;

        // Buscar ciclos desde cada nodo
        for (int i = 0; i < vertices; i++) {
            if (state[i] == 0) { // Si el nodo no ha sido visitado
                if (dfsCountEdges(i, state, edgeCount)) {
                    return edgeCount; // Retorna el número de aristas del ciclo encontrado
                }
            }
        }
        return 0; // Si no hay ciclos
    }

    //Verifica si hay una arista entre u y v
    bool hasEdge(int u, int v) {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            return adjMatrix[u][v] == 1;
        }
        return false;
    }
};

//Grafo con direcciones y no ponderada
class DirectedGraph {
private:
    int vertices; //Número de vértices
    std::vector<std::vector<int>> adjMatrix; //Matriz de adyacencia

public:
    DirectedGraph(int v) : vertices(v) {
        adjMatrix = std::vector<std::vector<int>>(v, std::vector<int>(v, 0));
    }

    //Agregamos una arista direccionada de u a v
    void addEdge(int u, int v) {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            adjMatrix[u][v] = 1;
        }
    }

    //Impresión de la matriz de adyacencia
    void printGraph() {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << '\n';
        }
    }

    //Verifica si hay una arista direccionada de u hacia v
    bool hasEdge(int u, int v) {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            return adjMatrix[u][v] == 1;
        }
        return false;
    }
};


//Grafo con direcciones y ponderada
class WeightedGraph {
private:
    int vertices; //Número de vértices
    std::vector<std::vector<int>> adjMatrix; //Matriz de adyacencia

public:
    WeightedGraph(int v) : vertices(v) {
        adjMatrix = std::vector<std::vector<int>>(v, std::vector<int>(v, INT_MAX));
        // Usamos INT_MAX (un valor muy grande) para señalar que no estan conectados

        for (int i = 0; i < v; ++i) {
            adjMatrix[i][i] = 0; //Valor de un nodo a si mismo: cero
        }
    }

    //Agregamos una arista direccionada de u a v con un peso
    void addEdge(int u, int v, int weight = 1) {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            adjMatrix[u][v] = weight;
        }
    }

    //Impresión de la matriz de adyacencia
    void printGraph() {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << '\n';
        }
    }

    //Devuelve el peso de una arista direccionada de u a v. Es INT_Max si no hay adyacencia.
    int getEdge(int u, int v) const {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            return adjMatrix[u][v];
        }
        return INT_MAX; // Retorna "sin conexión" si los nodos están fuera de rango
    }
};
