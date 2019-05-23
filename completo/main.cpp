#include <iostream>
#include <fstream> // acesso a biblioteca com as funções que permitem o uso dos arquivos
#include <cstdlib> // essa biblioteca permitirá o uso das funções rand e srand
#include <ctime> // essa biblioteca permitirá o uso da função time()

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
    A função gerarGrafoCompleto armazena todos as arestas que um
    grafo completo de vértices = nV e arestas = nA  no vetor do tipo
    aresta G.
*/
void gerarGrafoCompleto(aresta G[], int nV, int nA){
    srand(time(0));

    /* Sabendo que um grafo completo é um grafo simples -
    isto é, não possui laços nem duas ou mais arestas que
    liga dois vértices -, utiliza-se o laço a seguir para
    ligar dois vértices diferentes apenas uma vez e com um
    peso aleatório */
    int aux=0;
    while(aux<nA){
        for(int i=1; i<nV; i++){
            for(int j=i+1;j<=nV;j++){
                G[aux].vertice1= i;
                G[aux].vertice2= j;
                G[aux].peso= rand()%101;
                aux++;
            }
        }
    }
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

void salvarGrafoCompleto(aresta G[], int nV,int nA){
    ofstream myfile;

    string nome;
    nome=to_string(nV);
    nome = nome+"completo.in\0";

    myfile.open(nome);

    if(myfile.is_open()){
        myfile << nV<<endl;

        for(int i=0; i<nA; i++){
            myfile << G[i].vertice1 << " " << G[i].vertice2 << " " << G[i].peso << endl;
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
    cout << nV << endl;

    /*
        Inicializaremos o número de arestas nA com o número de
        arestas que um grafo completo de número de vertices = nV
        possui. Sendo este numero definido por
        nA = (nV*(nV-1))/2
    */
    int nA = (nV*(nV-1))/2;

    aresta G[nA]; // arestas existentes num grafo completo G

    gerarGrafoCompleto(G, nV, nA);
    salvarGrafoCompleto(G, nV,nA);

    cout << "Grafo Completo salvo e armazenado! :-)"<<endl;

    return 0;
}
