// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Pedra-papel-tesoura-lagar...
// Nível: 1
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1873

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int main()
{
    string s1, s2;
    int n;
        
    cin >> n;
    while(n--)
    {
        cin >> s1 >> s2;
        if(s1 == s2)
            cout << "empate\n";
        else if(s1 == "tesoura" and s2 == "papel")
            cout << "rajesh\n";
        else if(s1 == "papel" and s2 == "pedra") 
            cout << "rajesh\n";
        else if(s1 == "pedra" and s2 == "lagarto")
            cout << "rajesh\n";
        else if(s1 == "lagarto" and s2 == "spock")
            cout << "rajesh\n";
        else if(s1 == "spock" and s2 == "tesoura")
            cout << "rajesh\n";
        else if(s1 == "tesoura" and s2 == "lagarto")
            cout << "rajesh\n";
        else if(s1 == "lagarto" and s2 == "papel")
            cout << "rajesh\n";
        else if(s1 == "papel" and s2 == "spock")
            cout << "rajesh\n";
        else if(s1 == "spock" and s2 == "pedra")
            cout << "rajesh\n";
        else if(s1 == "pedra" and s2 == "tesoura")
            cout << "rajesh\n";
        else
            cout << "sheldon\n";
    }
    
    return 0;
}
