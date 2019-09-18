#ifndef CONEXO_H
#define CONEXO_H
#include <iostream>
#include "particao.h"
#include <stdio.h>

using namespace std;

int p[500];
int ordem[500];

/*
A função make_set insere um elemento aos arrays globais p[] e ordem[], definindo que o valor do elemento é se-
melhante a sua posição nos arrays, segregando a distribuição dos arrays por conjuntos.
*/
void make_set(int x){
     p[x] = x;
     ordem[x] = 0;
}

/*
A partir da construção dos arrays pela função make_set, a função find_set encontra facilmente nos arrays o ele-
mento que se deseja buscar, informando-se apenas o valor do elemento.
*/
int find_set(int x){
    if( x!= p[x] )
      p[x] = find_set(p[x]);
    return p[x];
}

/*
A função auxiliar link configura dois elementos como membros de um mesmo conjunto.
*/
void link(int x,int y){
     if(ordem[x] > ordem[y]){
        p[y] = x;
     }else{
        p[x] = y;
        if(ordem[x]==ordem[y])
          ordem[y]++;
     }
}

/*
A função une agrupa dois elementos.
*/
void une(int x,int y){
     link(find_set(x),find_set(y));
}

/*
same_componente verifica se dois componentes pertencem a um mesmo conjunto.
*/
int same_componente(int x,int y){
      if(find_set(x)==find_set(y)) {
        return 1;
    }
    else return 0;
}

/*
A função boleana verificarConexo compara se uma particao é conexa ou não, para tanto, a função faz uso
de funções auxiliares como make_set para construção dos arrays p[] e ordem[] e same_componente para ve-
rificar se os vertices pertencem a um mesmo conjunto (atrela-se conjunto ao grafo)
*/
bool verificarConexo(particao P){
    int n,m,i,a,b,conexo,teste=1,cont;

    n = P.nV;
    m = P.nA;



    for(i=1;i<=n;i++){
        make_set(i);
    }

    cont = 0;

    for(i=1;i<=m;i++){
        a= P.A[i].vertice1;
        b= P.A[i].vertice2;

        if( !same_componente(a,b) )
            cont++;
        une(a,b);
    }

    if(cont==n-1) return true;
    else return false;
}



#endif // CONEXO_H
