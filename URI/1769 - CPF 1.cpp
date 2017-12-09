// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: CPF 1
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1769

#include <bits/stdc++.h>

using namespace std;

int main(){
    string cpf;
    int sum1, sum2;
    
    while(cin >> cpf){
        cin.ignore();
        sum1 = 0;
        for(int i = 0, j = 1; i < 11; i++)
            if(cpf[i] != '.'){
                sum1 += j * (cpf[i]-'0'); 
                j++;
            }
        sum2 = 0;
        for(int i = 0, j = 9; i < 11; i++)
            if(cpf[i] != '.'){
                sum2 += j * (cpf[i]-'0');
                j--;
            }
            
        if(sum1%11 != 10)
            sum1 = sum1%11;
        else
            sum1 = 0;
        
        if(sum2%11 != 10)
            sum2 = sum2%11;
        else
            sum2 = 0;
            
        if(sum1 == (cpf[12]-'0') and sum2 == (cpf[13]-'0'))
            cout << "CPF valido" << '\n';   
        else
            cout << "CPF invalido" << '\n';
        
    }
    return 0;
}
