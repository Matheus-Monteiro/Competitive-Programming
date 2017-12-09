// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Experiências
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1094

#include <iostream>

using namespace std;

int main (){

  int n, q=0, s=0, c=0, r=0;
  double p[3], e=0;
  char l;
  
    cin >> n;
    
    while(n--){
      
      cin >> q;
      cin >> l;
      
      if(l=='C'){
        c+=q;
       }
       
       if(l=='R'){
        r+=q;
       }
       
       if(l=='S'){
        s+=q;
       }
       
       e+=q;       
    }
    
    p[0] = (c/e)*100;
    p[1] = (r/e)*100;
    p[2] = (s/e)*100;
    
    cout << "Total: " << e << " cobaias" << endl;
    cout << "Total de coelhos: " << c << endl;
    cout << "Total de ratos: " << r << endl;
    cout << "Total de sapos: " << s << endl;
    cout.precision(2);
    cout << fixed;
    cout << "Percentual de coelhos: " << p[0] << " \%" << endl;
    cout << "Percentual de ratos: " << p[1] << " \%" << endl;
    cout << "Percentual de sapos: " << p[2] << " \%" << endl;
  
  
return 0;
}
  


