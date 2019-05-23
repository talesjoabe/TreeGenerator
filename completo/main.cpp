#include <iostream>
#include <fstream> // acesso a biblioteca com as fun��es que permitem o uso dos arquivos
#include <cstdlib> // essa biblioteca permitir� o uso das fun��es rand e srand
#include <ctime> // essa biblioteca permitir� o uso da fun��o time()

/* A inclus�o da biblioteca a seguir, permite declarar
   e manipular strings. Para compilar, � necess�rio ter
   a vers�o standard C++11. No code blocks, voc� pode
   verificar em
   Settings -> Compiler
   depois, selecionar o compilador GNU GCC COMPILER
   feito isso, ir na tabela compiler settings.
   dentro dela, ir na outra tabela chamada Compiler Flags
   e verificiar se a op��o:
   "Have g++ follow the C++11 ISO C++ languaage standard [-std=c++11]"
   est� marcada.
   */
#include <string>

using namespace std;

/*
    A Struct caminho � composto por duas arestas
    e um peso. Ao atribuir valores para uma vari�vel
    deste tipo estruturado, estaremos dizendo que h�
    um caminho existente entre a aresta1 e aresta2 e
    o peso desse caminho � peso.
*/
struct caminho{
    int aresta1;
    int aresta2;
    int peso;
};

/*
    A fun��o gerarGrafoCompleto armazena todos os caminhos que um
    grafo completo de v�rtices = nV e arestas = nA  no vetor G.
*/
void gerarGrafoCompleto(caminho G[], int nV, int nA){
    srand(time(0));

    /* Sabendo que um grafo completo � um grafo simples -
    isto �, n�o possui la�os nem duas ou mais arestas que
    liga dois v�rtices -, utiliza-se o la�o a seguir para
    ligar dois v�rtices diferentes apenas uma vez e com um
    peso aleat�rio */
    int aux=0;
    while(aux<nA){
        for(int i=1; i<nV; i++){
            for(int j=i+1;j<=nV;j++){
                G[aux].aresta1= i;
                G[aux].aresta2= j;
                G[aux].peso= rand()%101;
                aux++;
            }
        }
    }
}

/*
    A fun��o salvarGrafoCompleto, armazena os valores de um
    Grafo Completo de n�mero de v�rtices = nV e n�mero de A-
    restas = nA em um arquivo no formato ".in". Onde o nome
    de cada arquivo armazenado ser� no formato "nVcompleto.in".
    Dentro do arquivo, a primeira linha � o n�mero de v�rtices.
    E as linhas posteriores � cada caminho de um grafo completo
    no seguinte formato: "aresta1 aresta2 peso".
*/

void salvarGrafoCompleto(caminho G[], int nV,int nA){
    ofstream myfile;

    string nome;
    nome=to_string(nV);
    nome = nome+"completo.in\0";

    myfile.open(nome);

    if(myfile.is_open()){
        myfile << nV<<endl;

        for(int i=0; i<nA; i++){
            myfile << G[i].aresta1 << " " << G[i].aresta2 << " " << G[i].peso << endl;
        }

        myfile.close();
    }
}

int main()
{


    int nV; // Declara-se a variavel nV para armazenar o n�mero de v�rtice.

    /* Como iremos trabalhar com numeros aleatorios,
    � interessante a inacializa��o da semente. Isso
    torna poss�vel gerar um numero diferente de acordo
    com o tempo */
    srand(time(0));

    /* A seguir, armazena-se um valor aleatorio na variavel
    nV no intervalo de 5 a 30 */
    nV = (rand() % (30-5+1)) + 5;
    cout << nV << endl;

    /*
        Inicializaremos o n�mero de arestas nA com o n�mero de
        arestas que um grafo completo de n�mero de vertices = nV
        possui. Sendo este numero definido por
        nA = (nV*(nV-1))/2
    */
    int nA = (nV*(nV-1))/2;

    caminho G[nA];

    gerarGrafoCompleto(G, nV, nA);
    salvarGrafoCompleto(G, nV,nA);

    cout << "Grafo Completo salvo e armazenado! :-)"<<endl;

    return 0;
}
