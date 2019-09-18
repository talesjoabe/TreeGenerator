#ifndef HEAP_H
#define HEAP_H
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include "particao.h"

/*
Recupera o indice correspondente ao pai de um nó.
*/
int pai(int i){
    return i/2;
}

/*
troca os valores de duas variáveis tipo partição.
*/
void troca(particao P1, particao P2) {
    particao T = P1;
    P1 = P2;
    P2 = T;
}

/*
A funcao heapify_up deve empilhar um nó na heap, em que os valores dos nós pai devem ser menor que os valores dos seus respectivos nós filho.
*/
void heapify_up(int v, particao heap[]){

    if(v == 1) return;

    int p = pai(v);
    if(heap[v].custo < heap[p].custo){
        swap(heap[v], heap[p]);
        heapify_up(p, heap);
    }

}

/*
Insere um novo nó na heap.
*/
void insere(particao P, particao heap[], int &tamanho_heap){
    heap[++tamanho_heap] = P;

    heapify_up(tamanho_heap, heap );
}

/*
Retorna o filho da esquerda de um nó.
*/
int esquerda(int i){
    return 2*i;
}

/*
Retorna o filho da direita de um nó.
*/
int direita(int i){
    return 2*i+1;
}

/*
A funcao heapify_down deve desempilhar um nó na heap, em que os valores dos nós pai devem ser menor que os valores dos seus respectivos nós filho.
*/
void heapify_down(int v, particao heap[], int &tamanho_heap){

    int d = direita(v);
    int e = esquerda(v);

    int menor = v;

    if(d < tamanho_heap && heap[d].custo < heap[menor].custo) menor = d;
    if(e < tamanho_heap && heap[e].custo < heap[menor].custo) menor = e;
    if(menor != v){
        swap(heap[v], heap[menor]);
        heapify_down(menor,heap,tamanho_heap);
    }
}

/*
Deleta um nó da heap.
*/
void deleta(int posicao, particao heap[], int &tamanho_heap){

    swap(heap[posicao], heap[tamanho_heap]);
    tamanho_heap--;
    heapify_down(posicao, heap,tamanho_heap);
}


#endif // HEAP_H
