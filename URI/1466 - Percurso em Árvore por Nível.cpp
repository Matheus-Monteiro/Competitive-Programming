// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Percurso em Árvore por Nível
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1466

#include <bits/stdc++.h>

using namespace std;

struct No{
    int val;
    No *esq, *dir;
    No(int _val){
        val = _val;
        esq = dir = nullptr;
    }  
};

void inserir(No* raiz, int valor){
    if(raiz->val > valor){
        if(raiz->esq == nullptr)
            raiz->esq = new No(valor);
        else
            inserir(raiz->esq, valor);
    }else{
        if(raiz->dir == nullptr)
            raiz->dir = new No(valor);
        else
            inserir(raiz->dir, valor);
    }
}

void bfs(No* raiz){
    queue<No*> fila;
    fila.push(raiz);
    bool flag = false;
    while(!fila.empty()){
        No *no = fila.front();
        fila.pop();
        if(no != nullptr){
            if(flag) cout << ' ';
            else flag = true;
            cout << no->val;
            if(no->esq != nullptr)
                fila.push(no->esq);
            if(no->dir != nullptr)
                fila.push(no->dir);
        }
    }
    cout << '\n';
}

int main(){
    int t, n, valor, c = 1;
     
    cin >> t;
    while(t--){
        cin >> n >> valor;
        No *raiz = new No(valor);
        n--;
        while(n--){
            cin >> valor;
            inserir(raiz, valor);
        }
        cout << "Case " << c++ << ':' << '\n';
        bfs(raiz);
        free(raiz);
        cout << '\n';
    }
    return 0;
}
