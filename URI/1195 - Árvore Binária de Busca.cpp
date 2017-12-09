// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Árvore Binária de Busca
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1195

#include <bits/stdc++.h>

using namespace std;

struct No{
    int valor;
    No* esq;
    No* dir;
};

No* novoNo(int valor){
    No* no = (No*)malloc(sizeof(No));
    no->valor = valor;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}

void montarArvore(No* raiz, int valor){
    if(raiz != NULL){
        if(raiz->valor > valor){
            if(raiz->esq == NULL)
                raiz->esq = novoNo(valor);
            else
                montarArvore(raiz->esq, valor);
        }else{
            if(raiz->valor < valor){    
                if(raiz->dir == NULL)
                    raiz->dir = novoNo(valor);
                else
                    montarArvore(raiz->dir, valor);
            }
        }    
    }
}

void preOrdem(No* raiz){
    if(raiz != NULL){
        cout << " " << raiz->valor;
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void emOrdem(No* raiz){
    if(raiz != NULL){
        emOrdem(raiz->esq);
        cout << " " << raiz->valor;
        emOrdem(raiz->dir);
    }
}

void posOrdem(No* raiz){
    if(raiz != NULL){
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        cout << " " << raiz->valor;
    }
}

int main(){
    int c, n, aux, caso = 1;
    
    cin >> c;
    while(c--){
        cin >> n >> aux; 
        
        No* raiz = novoNo(aux);
     
        for(int i = 0; i < n-1; i++){
            cin >> aux;
            montarArvore(raiz, aux);
        }
        cout << "Case " << caso << ":\n";
        cout << "Pre.:";
        preOrdem(raiz);
        cout << "\n";
        cout << "In..:";
        emOrdem(raiz);
        cout << "\n";
        cout << "Post:";
        posOrdem(raiz);
        cout << "\n\n";

        caso++;
    }
    return 0;
}
