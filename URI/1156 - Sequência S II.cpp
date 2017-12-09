// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Sequência S II
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1156

#include <bits/stdc++.h>

using namespace std;

int main(){
	
    double  soma = 0;

    soma = double(1 + (3.0/2) + (5.0/4) + (7.0/8) + (9.0/16) + (11.0/32) + (13.0/64) + (15.0/128) + (17.0/256) + (19.0/512) + (21.0/1024) + (23.0/2048) + (25.0/4096) + (27.0/8192) + (29.0/16384) + (31.0/32768) + (33.0/65536) + (35.0/131072) + (37.0/262144) + (39.0/524288));
	cout.precision(2);	
	cout << fixed;
	cout << soma << endl; 
}
