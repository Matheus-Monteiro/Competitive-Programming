// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Troca de Cartas
// Nível: 3
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1104

#include <iostream>
#include <set>

using namespace std;

int main(){
    
    int a, b, aux, cont;
    set<int> A;
    set<int> B;
    
    while(cin >> a >> b && a != 0 || b != 0){
    
        while(a--){
            cin >> aux;
            A.insert(aux);
        }
        
        while(b--){
            cin >> aux;
            B.insert(aux);
        }
        
        if(A.size() > B.size())
            swap(A, B);
            
        cont = 0;
        
        for(set<int>::iterator it = A.begin(); it != A.end(); it++)
            if(B.find(*it) != B.end())
                cont++;
        
        int res = A.size() - cont;
        cout << res << endl;
        
        A.clear();
        B.clear();
    }
    
    return 0;
}
