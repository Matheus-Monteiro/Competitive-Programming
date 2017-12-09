// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Idades
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1154

#include <iostream>
#include <stdio.h>

using namespace std;

int main (){
    int idade;
    double media=0, a = 0;
    
     while((cin >> idade) && idade>0){
        media+=idade;
        a++;
     }
     media = media/a;
     printf("%.2f\n",media);
        
}

