// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Operações em ABP I
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1200

#include <bits/stdc++.h>

using namespace std;

struct No{
    char valor;
    No *esq, *dir;
};

No* novoNo(char valor){
    No* no = (No*)malloc(sizeof(No));
    no->valor = valor;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}

void montarArvore(No* raiz, char valor){
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

bool buscaNo(No* raiz, char valor){
    if(raiz != NULL){
        if(raiz->valor == valor)
            return true;
        if(raiz->valor > valor)
            buscaNo(raiz->esq, valor);
        else
            if(raiz->valor < valor)
                buscaNo(raiz->dir, valor);
    }else
        return false;   
}

string aux;

string preOrdem(No* raiz){
    if(raiz != NULL){
        aux.push_back(raiz->valor);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
    return aux;
}

string emOrdem(No* raiz){
    if(raiz != NULL){
        emOrdem(raiz->esq);
        aux.push_back(raiz->valor);
        emOrdem(raiz->dir);
    }
    return aux;
}

string posOrdem(No* raiz){
    if(raiz != NULL){
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        aux.push_back(raiz->valor);
    }
    return aux;
}

int main(){
    string str, impr;
    No* raiz = NULL;
    bool ok = true; 
    
    while(getline(cin, str)){
        if(str[0] == 'I' and str[1] == ' '){
            if(ok){
                raiz = novoNo(str[2]);
                ok = false;
            }else
                montarArvore(raiz, str[2]);
        }
        if(str[0] == 'P' and str[1] == ' '){
            bool ok2 = buscaNo(raiz, str[2]);
            if(ok2)
                cout << str[2] << " existe" << "\n";
            else
                cout << str[2] << " nao existe" << "\n"; 
        }
        if(str == "INFIXA"){
            impr = emOrdem(raiz);
            for(int i = 0; i < impr.size(); i++){
                cout << impr[i];
                if(i < impr.size()-1)
                    cout << " ";
            }
            cout << "\n";
            aux.clear();
        }
        if(str == "PREFIXA"){
            impr = preOrdem(raiz);
            for(int i = 0; i < impr.size(); i++){
                cout << impr[i];
                if(i < impr.size()-1)
                    cout << " ";
            }
            cout << "\n";
            aux.clear();
        }
        if(str == "POSFIXA"){
            impr = posOrdem(raiz);
            for(int i = 0; i < impr.size(); i++){
                cout << impr[i];
                if(i < impr.size()-1)
                    cout << " ";
            }
            cout << "\n";
            aux.clear();
        }
    }
    
    return 0;
}
