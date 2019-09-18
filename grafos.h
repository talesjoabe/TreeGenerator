#ifndef ARQUIVOS_H
#define ARQUIVOS_H
#include <iostream>
#include "aresta.h"
#include "estruturas.h"
#include <string>
#include <fstream>
#include "particao.h"
#include "conexo.h"
#include "heap.h"
#include "funcoes.h"

using namespace std;

#define MAX 500

/*
A função lerGrafo preenche um conjunto de arestas a partir de um grafo pre-selecionado em um arquivo
indicado endereçado pelo parâmetro de entrada nome, assim como atribui automaticamente os parâmetros
de numero de arestas e vertices que compõem um grafo.
*/
void lerGrafo(aresta G[], string nome, int& nV, int& nA){
    int i=1;
    string line;
    ifstream myfile(nome);

    if (myfile.is_open()){
        myfile >> nV;
        while ( getline (myfile,line) )
        {
            myfile >> G[i].vertice1;
            myfile >> G[i].vertice2;
            myfile >> G[i].peso;
            G[i].tipo = 0;
            i++;
        }
        nA= i-2;
        myfile.close();
    }
    else cout << "Unable to open file";
}

/*
A funço salvarGrafo deve salvar uma instância contendo um grafo com as configurações do conjunto de
arestas e os inteiros de numero de vertices e arestas passados como parâmentros de entrada.
*/
void salvarGrafo(aresta G[], int nV,int nA){
    ofstream myfile;

    string nome;
    nome= "teste.in"; //nome da nova instancia

    myfile.open(nome); //abre o arquivo criado com o nome

    if(myfile.is_open()){
        myfile << nV<<endl;
	
	/*
        imprime na instancia os dados do grafo
        */
        for(int i=0; i<nA; i++){
            myfile << G[i].vertice1 << " " << G[i].vertice2 << " " << G[i].peso << endl;
        }

        myfile.close(); //fecha o arquivo criado.
    }
}

/*
A função find recupera um valor passado de acordo com o conjunto em que está inserida.
*/
int find(int x, int pai[]){
    if(pai[x] == x) return x;
    return pai[x] = find(pai[x], pai);
}

/*
A função join une dois elementos a um mesmo conjunto de acordo com a ordem a qual estão
embarcadas.
*/
void join(int a, int b, int pai[], int peso[]){

    a = find(a, pai);
    b = find(b, pai);
    /*
    Os laços condicionais devem segregar os valores e agrupá-los novamente no conjunto de maior peso.
    */
    if(peso[a] < peso[b]) pai[a] = b;
    else if(peso[b] < peso[a]) pai[b] = a;
    else{
        pai[a] = b;
        peso[b]++;
    }
}

/*
De acordo com o algoritmo de Kruskal, a função arvore mínima retorna uma árvore geradora mínima de um grafo
previamente descrito pelos parâmetros de entrada aresta G[], int &nV, int &nA. Leva-se em consideração o ti-
po de aresta(Opcional, Obrigatoria, Excluida) que o grafo possui para construir a MST.
*/
void arvoreMinima(aresta G[], aresta mst[], int &nV, int &nA){
        int pai[MAX], peso[MAX];
        // inicializar os pais para o union-find

        for(int i = 1;i <= nV;i++) pai[i] = i;

         ascendingSort(G, nA);//ordena-se o grafo

         int size = 0;

	/*
        A MST é construida levando-se em consideração o tipo de aresta e a origem dos vertices do grafos
        */
         for(int i = 1;i <= nA;i++){
             if(G[i].tipo!=2 && find(G[i].vertice1, pai) != find(G[i].vertice2, pai) ){ // se estiverem em componentes distintas
                 join(G[i].vertice1, G[i].vertice2, pai, peso);

                 mst[++size] = G[i];
             }
         }
}

/*
A função imprimirGrafo imprime um grafo em tela.
*/
void imprimirGrafo(aresta G[], int nV, int nA){
    cout << nV << endl;
    for(int i=1; i<=nA; i++){
         cout << G[i].vertice1 << " " << G[i].vertice2 << " "<< G[i].peso<< endl;
    }
}

/*
A função boleana existeAresta deve verificar se a aresta que agrupa um par de vertices em um grafo existe,
podendo apontar em qual indice esta localizada a aresta.
*/
bool existeAresta(aresta A[], int V1, int V2, int nA, int& indice){
    bool flag=false;

    int i;

    for(i=1;i<=nA; i++){
        indice=i;
        if(A[i].vertice1==V1 && A[i].vertice2==V2){
            return true;
        }
    }

    indice=i-1;

    return false;
}


/*
A função particionar recebe como parâmetro de entrada partição P, partição heap[100] e o inteiro para o tamanho
da heap para construção e empilhamento da partição de um grafo em uma estrutura de dado heap, no intuito de or-
denar por custo as partições geradas do grafo.
*/
void particionar(particao P, particao heap[100], int& tamanhoheap){
    particao P1,P2; //declara-se as partições geradas da partição P
    P1=P; //inicializa-se a partição P1 como P
    P2=P; //inicializa-se a partição P2 como P
    int indice=1;

    particao mst=P; //inicializa-se a arvore geradora minima da partição P como P

    particao mstAUX;//inicializa-se uma arvore geradora minima auxiliar da partição P como P
    // preenche-se a arvore geradora minima auxiliar
    mstAUX.nA=P.nV-1;
    mstAUX.nV=P.nV;

    arvoreMinima(P.A,mstAUX.A,P.nV,P.nA);
    mstAUX.custo=calcularCusto(mstAUX.A,mstAUX.nA);

    for(int i=1; i<=P.nA;i++){
	//verifica-se os tipos de arestas para preencher corretamente a partição de P, levando-se em consideração
        //as arestas da mstAUX para alternar-se os tipos de arestas na partição de P
        if(P.A[i].tipo==0 && existeAresta(mstAUX.A,P.A[i].vertice1,P.A[i].vertice2,mstAUX.nA,indice)){ // opcional
            P1.A[i].tipo=2; // proibida
            P2.A[i].tipo=1; // obrigatoria
	    
            //preenche a arvore geradora minima da partição de P
            mst= P1;

            arvoreMinima(P1.A, mst.A, P1.nV, P1.nA);
            mst.nA= P1.nV-1;
            mst.nV= P1.nV;

	   //verifica-se se o grafo MST gerado da partição de P é conexo para inserção da partição a Heap
           if(verificarConexo(mst)){
                P1.custo=calcularCusto(mst.A,P1.nV-1);
                insere(P1, heap, tamanhoheap);
            }
            P1=P2;
        }
    }
}

/*
A funcao kbest desempenha o papel de particionar um grafo do tipo particao G e agrupar suas partições em
uma partição heap[], devendo-se informar por um parâmetro por referência inteiro com o tamanho da heap,
com o objetivo de encontrar e imprimir em tela as quantidades de arvores geradoras minimas desejadas apon-
tadas pelo paramentro de entrada inteiro qtdearvores.
*/
void kbest(particao G, particao heap[100], int& tamanhoheap, int qtdearvores){
    aresta mst[100];
    int i=0;

    arvoreMinima(G.A,mst,G.nV,G.nA); //encontra a MST correspondente ao grafo G
    cout<< "$$$$$custo: "<<calcularCusto(mst,G.nV-1) << "$$$$$$\n"; //imprime o custo da MST encontrada
    imprimirGrafo(mst,G.nV,G.nV-1); //imprime a MST
    particionar(G,heap,tamanhoheap); //particiona o grafo G

    int k=0;

    do{
         arvoreMinima(heap[1].A,mst,G.nV,G.nA); //em seguida, é encontrado a MST de cada particao presente na heap para gerar as proximas
                                               //particoes e suas respectivas MSTs
         cout<< "$$$$$custo: "<<calcularCusto(mst,G.nV-1) << "$$$$$$\n"; //imprime o custo da MST encontrada

         imprimirGrafo(mst,G.nV,G.nV-1); //imprime a MST
          k++;
         particionar(heap[1],heap,tamanhoheap); //particiona a partição no topo da heap
         deleta(1,heap,tamanhoheap); // e em seguida a partição é deletada do topo da heap para que possam ser geradas as demais MSTs
    }while(tamanhoheap>0 && k!=qtdearvores);
    cout << tamanhoheap;
}


#endif // ARQUIVOS_H

