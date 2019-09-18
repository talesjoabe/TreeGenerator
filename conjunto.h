#ifndef CONJUNTO_H
#define CONJUNTO_H

/*
A função find busca um elemento no conjunto.
*/
int find(int x){
    if(pai[x] == x) return x;
    return pai[x] = find(pai[x]);
}

/*
A função join agrupa dois elementos em um mesmo conjunto.
*/
void join(int a, int b){

    a = find(a);
    b = find(b);

    if(peso[a] < peso[b]) pai[a] = b;
    else if(peso[b] < peso[a]) pai[b] = a;
    else{
        pai[a] = b;
        peso[b]++;
    }
}
#endif // CONJUNTO_H
