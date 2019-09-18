#ifndef PARTICAO_H
#define PARTICAO_H
#include "aresta.h"
#include <iostream>

using namespace std;

#define MAX 500

struct particao{
    aresta A[MAX];
    int nA;
    int nV;
    int custo;
};

void imprimirParticao(particao P){
     cout << P.nV << endl;
     for(int i=1; i<=P.nA; i++){
         cout << P.A[i].vertice1 << " " << P.A[i].vertice2 << " " << P.A[i].peso << " "<< P.A[i].tipo<< endl;
     }
}

#endif // PARTICAO_H
