#include <iostream>
#include <fstream> // acesso a biblioteca com as funções que permitem o uso dos arquivos
#include <cstdlib> // essa biblioteca permitirá o uso das funções rand e srand
#include <ctime> // essa biblioteca permitirá o uso da função time()
#include <cmath>

/* A inclusão da biblioteca a seguir, permite declarar
   e manipular strings. Para compilar, é necessário ter
   a versão standard C++11. No code blocks, você pode
   verificar em
   Settings -> Compiler
   depois, selecionar o compilador GNU GCC COMPILER
   feito isso, ir na tabela compiler settings.
   dentro dela, ir na outra tabela chamada Compiler Flags
   e verificiar se a opção:
   "Have g++ follow the C++11 ISO C++ languaage standard [-std=c++11]"
   está marcada.
   */
#include <string>

using namespace std;

/*
    A Struct aresta é composto por dois vertices
    e um peso. Ao atribuir valores para uma variável
    deste tipo estruturado, estaremos dizendo que há
    uma aresta existente entre vertice1 e vertice2 e
    o custo dessa aresta é peso.
*/
struct aresta{
    int vertice1;
    int vertice2;
    int peso;
};

/*
        A função gerarGrafoGrid armazena todos as arestas que um
    grafo completo de vértices = nV, arestas = nA e quantida-
    de de colunas=nC no vetor do tipo
    aresta G.
        Sabendo que um grafo Grid é um grafo esparso. Utilizaremos duas linhas
    para construir o desenho da grade. Onde há uma aresta entre cada vértice
    e o da direita, assim como também o seu inferior.
        No primeiro laço, iremos prencher as arestas no vetor G de tal forma
    que obedeça essa característica do grafo Grid. Enquanto isso, sabendo que
    não há nenhuma aresta entre cada vértice da segunda linha e o seu inferior
    - pois não há uma terceira linha, o segundo laço irá apenas preencher as
    arestas entre cada vértice e o próximo da direita.
        nA é um parâmetro de entrada e saída. No qual, recebe como entrada o
    valor máximo de arestas que um grafo Grid de nC colunas e de 2 linhas po-
    de ter. Ao fim dela, o valor é atualizado para a quantidade real que um
    grafo de nV vértices tem.
*/
void gerarGrafoGrid(aresta G[], int nV, int&     nA, int nC){
    srand(time(0));
    int nVaux=1; // variavel auxiliar que indica qual é o vertice atual
    int aux=0; // variavel auxiliar para preencher o vetor G de tamanho nA

    while(nVaux<=nC){

        /*
            Caso o vertice da direita exista, então há uma aresta existente
            entre ele e o vertice atual
        */
        if(nVaux+1<=nC){
            G[aux].vertice1=nVaux; // vertice atual
            G[aux].vertice2=nVaux+1; // vertice da direita
            G[aux].peso=rand()%101;
            aux++;
        }

        /*
            Caso o vertice inferior exista, então há uma aresta existente
            entre ele e o vertice atual
        */

        if(nVaux+nC<=nV){
            G[aux].vertice1=nVaux; // vertice atual
            G[aux].vertice2=nVaux+nC; // vertice inferior
            G[aux].peso=rand()%101; // peso da aresta
            aux++;
        }
            nVaux++;
    }

    while(nVaux<nV){
        G[aux].vertice1=nVaux; // vertice atual
        G[aux].vertice2=nVaux+1; // vertice da direita
        G[aux].peso=rand()%101; // peso da aresta
        aux++;
        nVaux++;
    }
    nA= aux; // atualiza para a quantidade de arestas que o grafo Grid de nV vertices possui.
}

/*
    A função salvarGrafoCompleto, armazena os valores de um
    Grafo Completo de número de vértices = nV e número de A-
    restas = nA em um arquivo no formato ".in". Onde o nome
    de cada arquivo armazenado será no formato "nVcompleto.in".
    Dentro do arquivo, a primeira linha é o número de vértices.
    E as linhas posteriores é cada aresta de um grafo completo
    no seguinte formato: "vertice1 vertice2 peso".
*/

void salvarGrafoGrid(aresta G[], int nV,int nA){
    ofstream myfile;

    string nome;
    nome=to_string(nV);
    nome = nome+"grid.in\0";

    myfile.open(nome);

    if(myfile.is_open()){
        myfile << nV<<endl;

        for(int i=0; i<nA; i++){
            myfile << G[i].vertice1 << " " << G[i].vertice2 << " "<< G[i].peso << endl;
        }

        myfile.close();
    }
}

int main()
{

    int nV; // Declara-se a variavel nV para armazenar o número de vértice.

    /* Como iremos trabalhar com numeros aleatorios,
    é interessante a inacialização da semente. Isso
    torna possível gerar um numero diferente de acordo
    com o tempo */
    srand(time(0));

    /* A seguir, armazena-se um valor aleatorio na variavel
    nV no intervalo de 5 a 30 */
    nV = (rand() % (30-5+1)) + 5;

    int linhas=2, colunas= ceil(nV/2.); // caracterstica do desenho da grade utilizada na nossa implementação.

    /*
        Inicializaremos o número de arestas nA com o número de
        arestas que um grafo Grid possui.
    */
    int nA = 2*linhas*colunas-linhas-colunas;

    aresta G[nA]; // arestas existentes num grafo Grid

    gerarGrafoGrid(G, nV, nA, colunas);
    salvarGrafoGrid(G, nV,nA);

    cout << "Grafo Grid salvo e armazenado! :-)"<<endl;

    return 0;
}
