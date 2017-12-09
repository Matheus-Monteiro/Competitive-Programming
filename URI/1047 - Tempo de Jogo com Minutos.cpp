// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Tempo de Jogo com Minutos
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1047

#include <iostream>

using namespace std;

int main (){

    int h1, m1, h2, m2, dh, dm;
    
            cin >> h1 >> m1 >> h2 >> m2;
            
        if(h1 == h2 && m1 == m2)
          {
              cout << "O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)\n";
          }
        
        if(h1 < h2 && m1 < m2)
          {
              dh = h2-h1;
              dm = m2-m1;
              
              cout << "O JOGO DUROU " << dh << " HORA(S) E " << dm << " MINUTO(S)\n";
          }
          
        if(h1 < h2 && m1 > m2)
          { 
             if(h1==h2-1)
                {
                    dh = 0;
                    dm = 60-m1+m2;
                    
                    cout << "O JOGO DUROU " << dh << " HORA(S) E " << dm << " MINUTO(S)\n";
                }else{
                
                        dh = h2-h1-1;
                        dm = 60-m1+m2;
                        
                        cout << "O JOGO DUROU " << dh << " HORA(S) E " << dm << " MINUTO(S)\n";
                     }
          }
          
        if(h1 > h2 && m1 > m2)
          {
              dh = 23-h1+h2;
              dm = 60-m1+m2;
              
              cout << "O JOGO DUROU " << dh << " HORA(S) E " << dm << " MINUTO(S)\n";

          }
          
        if(h1 > h2 && m1 < m2)
          {
              dh = 23-h1+h2;
              dm = 60-m1+m2;
              
              if((60-m1+m2) > 60)
                {
                  dh = dh+1;
                  dm = dm-60;
                }
              
              cout << "O JOGO DUROU " << dh << " HORA(S) E " << dm << " MINUTO(S)\n";

          }
        
        if(h1==h2 && m1>m2)
          {
            dh = 23;
            dm = 60-m1+m2;
            
            cout << "O JOGO DUROU " << dh << " HORA(S) E " << dm << " MINUTO(S)\n";

          }
          
         if(h1==h2 && m1<m2)
          {
            dh = 0;
            dm = m2-m1;
            
            cout << "O JOGO DUROU " << dh << " HORA(S) E " << dm << " MINUTO(S)\n";

          }
          
        if(h1>h2 && m1==0 && m2==0)
          {
            dh = 24-h1+h2;
            dm = 0;
            
            cout << "O JOGO DUROU " << dh << " HORA(S) E " << dm << " MINUTO(S)\n";

          }

        if(h1<h2 && m1==0 && m2==0)
          {
            dh = h2-h1;
            dm = 0;
            
            cout << "O JOGO DUROU " << dh << " HORA(S) E " << dm << " MINUTO(S)\n";

          }
          
        if(h1<h2 && m1==m2)
          {
            dh = h2-h1;
            dm = 0;
            
            cout << "O JOGO DUROU " << dh << " HORA(S) E " << dm << " MINUTO(S)\n";

          }
          
        if(h1>h2 && m1==m2)
          {
            dh = 24-h1+h2;
            dm = 0;
            
            cout << "O JOGO DUROU " << dh << " HORA(S) E " << dm << " MINUTO(S)\n";

          }
}

