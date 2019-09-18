#ifndef ARESTA_H
#define ARESTA_H

/*
A estrutura aresta é composta por um par de vértices e o peso da aresta, seguida do dado
tipo que expecifica a classificação da aresta, alternando entre:
    0 - Opcional
    1 - Obrigatoria
    2 - Proibida
*/
struct aresta{
    int vertice1;
    int vertice2;
    int peso;
    int tipo;
};

/*
A função copiar arestas transfere todos os dados depositados em um array de arestas para um
outro array de arestas, em que é necessário especificar quais os arrays e o número de ares-
tas presentes nos arrays.
*/
void copiarArestas(aresta A1[], aresta A2[], int nA){
    for(int i=1; i<=nA; i++){
        A1[i].vertice1= A2[i].vertice1;
        A1[i].vertice2= A2[i].vertice2;
        A1[i].peso= A2[i].peso;
        A1[i].tipo= A2[i].tipo;
    }
}

#endif // ARESTA_H
