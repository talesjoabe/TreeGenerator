#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H
#include "aresta.h"

void ascendingSort(aresta a[], int nA){
    int ordenado = 0; // inicializo "ordenado" como 0, para que o loop comece

    while(ordenado == 0){ // enquanto ordenado for 0

    ordenado = 1; // suponho que o vetor está ordenado

        for(int i=1; i < nA; i++){ // e checo para todas as posições, exceto a última
            if(a[i].peso > a[i+1].peso){ // se não há inversão entre vetor[i] e vetor[i+1]

                // se houver, troco os valores de vetor[i] e vetor[i+1]
                aresta aux = a[i];
                a[i] = a[i+1];
                a[i+1]= aux;

                ordenado = 0; // e salvo que o vetor não está ordenado
            }
        }
    }
}

void decreasingSort(aresta a[], int nA){
    int ordenado = 0; // inicializo "ordenado" como 0, para que o loop comece

    while(ordenado == 0){ // enquanto ordenado for 0

    ordenado = 1; // suponho que o vetor está ordenado

        for(int i=1; i < nA; i++){ // e checo para todas as posições, exceto a última
            if(a[i].peso > a[i+1].peso){ // se não há inversão entre vetor[i] e vetor[i+1]

                // se houver, troco os valores de vetor[i] e vetor[i+1]
                aresta aux = a[i];
                a[i] = a[i+1];
                a[i+1]= aux;

                ordenado = 0; // e salvo que o vetor não está ordenado
            }
        }
    }
}

#endif // ESTRUTURAS_H
