// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Múltiplos
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1044

#include <iostream>

using namespace std;

int main(){
//declarando as variaveis
int A,B,RESTO;

//entrada de dados
cin >> A;
cin >> B;

//processamento
if(A<B){
RESTO = B%A;
if(RESTO == 0){
cout<<"Sao Multiplos"<<endl;
}else {
cout<<"Nao sao Multiplos"<<endl;
}
}else{
if(B<A){
RESTO = A%B;
if(RESTO == 0){
cout<<"Sao Multiplos"<<endl;
}else {
cout<<"Nao sao Multiplos"<<endl;
}
}
}

return 0;
}


