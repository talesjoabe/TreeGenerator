#ifndef FUNCOES_H
#define FUNCOES_H
#include "aresta.h"

/*
A partir da soma dos pesos do conjunto de arestas que compõe um grafo, a função calcularCusto
retorna o custo de um grafo. Os parâmetros de entrada são um array de arestas e o número de
arestas presentes no array.
*/
int calcularCusto(aresta T[], int nA){
    int custo=0;
    for(int i=1; i<=nA;i++){
        custo = T[i].peso + custo;
    }
    return custo;
}
#endif // FUNCOES_H
