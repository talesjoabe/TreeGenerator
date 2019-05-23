#include <iostream>
#include <fstream> // acesso a biblioteca com as funções que permitem o uso dos arquivos
#include <cstring> // permite o uso de funções para a manipulação de strings
#include <cstdlib>
#include <ctime>

using namespace std;

struct grafoCompleto{
    int aresta1;
    int aresta2;
    int peso;
};

void salvarGrafoCompleto(grafoCompleto G[], int vertice,int arestas){
    ofstream myfile;


    char nome[15] = "Teste\0";

    /*nome[0]= char(vertice);
    strcat(nome, "grid.in\0");*/

    myfile.open(nome);

    if(myfile.is_open()){
        myfile << vertice<<endl;

        for(int i=0; i<arestas; i++){
            myfile << G[i].aresta1 << " " << G[i].aresta2 << " " << G[i].peso << endl;
        }

        myfile.close();
    }
}

void gerarGrafoCompleto(grafoCompleto G[], int vertice, int arestas){
    srand(time(0));

    /* Sabendo que um grafo completo é um grafo simples -
    isto é, não possui laços nem duas ou mais arestas que
    liga dois vértices -, utiliza-se o laço a seguir para
    ligar dois vértices diferentes apenas uma vez e com um
    peso aleatório */
    int aux=0;
    while(aux<arestas){
        for(int i=1; i<vertice; i++){
            for(int j=i+1;j<=vertice;j++){
                G[aux].aresta1= i;
                G[aux].aresta2= j;
                G[aux].peso= rand()%101;
                aux++;
                cout << aux << endl;
            }
        }
    }
}

int main()
{
    int vertice;
    /* Como iremos trabalhar com numeros aleatorios,
    é interessante a inacialização da semente. Isso
    torna possível gerar um numero diferente de acordo
    com o tempo */
    srand(time(0));
    /* A seguir, armazena-se um valor aleatorio na variavel
    vertice no intervalo de 5 a 30 */
    vertice = (rand() % (30-5+1)) + 5;
    cout << vertice << endl;

    int arestas = (vertice*(vertice-1))/2;

    grafoCompleto G[arestas];

    gerarGrafoCompleto(G, vertice, arestas);
    salvarGrafoCompleto(G, vertice,arestas);

    return 0;
}
