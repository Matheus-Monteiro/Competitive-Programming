// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Concurso de Contos
// Nível: 3
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1222

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, l, c, qtd_lin, aux;
    string texto;
     
    while(cin >> n >> l >> c){
        cin.ignore();
        getline(cin , texto);
        qtd_lin = aux = 0;
        for(int i = 0; i < texto.size(); i++){
            if(aux == c){
                if(texto[i] == ' '){
                    qtd_lin++;
                    aux = 0;
                }else{
                    while(texto[i] != ' ')
                        i--;
                    qtd_lin++;
                    aux = 0;
                }
            }else
                aux++;
        }
        if(aux)
            qtd_lin++;   
        cout << ((qtd_lin%l == 0) ? qtd_lin/l : (qtd_lin/l)+1) << '\n'; 
    }
     
    return 0;
}
