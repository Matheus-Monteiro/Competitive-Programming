// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Feedback
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1546

#include<iostream>

using namespace std;

int main(){

    int n, k, aux;

    cin >> n;
    while(n--){
            cin >> k;
        while(k--){
                cin >> aux;
            if(aux==1)
                cout << "Rolien" << endl;
            if(aux==2)
                cout << "Naej" << endl;
            if(aux==3)
                cout << "Elehcim" << endl;
            if(aux==4)
                cout << "Odranoel" << endl;
        }
    }

}

