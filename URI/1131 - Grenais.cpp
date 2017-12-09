// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Grenais
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1131

#include <iostream>

using namespace std;

int main(){
    int gg, gi, n=1, s=0, vg=0, vi=0, e=0;

    while(n==1 && cin >> gi >> gg){

            if(gi > gg){
                vi+=1;
            }
            
            if(gi < gg){
                vg+=1;
            }
            
            if(gi == gg){
                e+=1;
            }
            s+=n;
            cout << "Novo grenal (1-sim 2-nao)" << endl;
            cin >> n;
    }
    
            cout << s << " grenais" << endl;
            cout << "Inter:" << vi << endl;
            cout << "Gremio:" << vg << endl; 
            cout << "Empates:" << e << endl;
            
            if(vi > vg)
                cout << "Inter venceu mais" << endl;
            if(vi < vg)
                cout << "Gremio venceu mais" << endl;
                
            if(vi == vg)
                cout << "Nao houve vencedor" << endl;


return 0;
}
