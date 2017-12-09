// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Procurando Subsequências
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2126

#include <bits/stdc++.h>

using namespace std;

int main(){
    string n1, n2;
    int pos, cont, ult, caso = 1;  
     
    while(cin >> n1 >> n2){
        cont = ult = 0;
        pos = 1;
        cout << "Caso #" << caso << ":" << "\n";
        if(n1.size() <= n2.size()){ 
            while(pos != -1){
                pos = n2.find(n1);
                if(pos != -1){
                    cont++;
                    ult += pos+1;
                    n2 = n2.substr(pos+1, n2.size());
                }
                
            }
            if(cont > 0){
                cout << "Qtd.Subsequencias: " << cont << "\n";
                cout << "Pos: " << ult << "\n";
            }else
                cout << "Nao existe subsequencia" << "\n"; 
        }else
            cout << "Nao existe subsequencia" << "\n";   
        cout << "\n";
        caso++;
    }

	return 0;
}
