#include <iostream>
#include <fstream>
#include <string>
#include "estruturas.h"
#include "grafos.h"
#include "aresta.h"
#include "grafos.h"
#include "particao.h"
#include "funcoes.h"
#include "conexo.h"
#include "heap.h"

using namespace std;

#define MAX 100

int main()
{

    particao heap[MAX], arvores[MAX];
    int tamanhoheap=0, qtdearvores=20;
    particao p,mst;

   string nome;

    cout << "Welcome to the Tree Generator 1.0!!!\nTell me the adress directory of your wished graph: ";
    getline(cin,nome);
    cout << "Now tell me how many tree do you want: ";
    cin>> qtdearvores;

    lerGrafo(p.A,nome, p.nV,p.nA);

    kbest(p,heap,tamanhoheap,qtdearvores);

    return 0;
}
