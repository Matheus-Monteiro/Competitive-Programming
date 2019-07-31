#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<char> fila_oitavas;
    queue<char> fila_quartas;
    queue<char> fila_semi;
    queue<char> fila_final;
    char n, auxa, auxb;
    int a, b;
    
    for(int i = 0; i < 16; i++){
        n = (char)(i+65);
        fila_oitavas.push(n); 
    }
    
    for(int i = 0; i < 8; i++){
        cin >> a >> b;
        auxa = fila_oitavas.front();
        fila_oitavas.pop();
        auxb = fila_oitavas.front();
        fila_oitavas.pop();
        if(a > b)
            fila_quartas.push(auxa);
        else
            fila_quartas.push(auxb);
    }
   
    
    for(int i = 0; i < 4; i++){
        cin >> a >> b;
        auxa = fila_quartas.front();
        fila_quartas.pop();
        auxb = fila_quartas.front();
        fila_quartas.pop();
        if(a > b)
            fila_semi.push(auxa);
        else
            fila_semi.push(auxb);     
    }
    
    for(int i = 0; i < 2; i++){
        cin >> a >> b;
        auxa = fila_semi.front();
        fila_semi.pop();
        auxb = fila_semi.front();
        fila_semi.pop();
        if(a > b)
            fila_final.push(auxa);
        else
            fila_final.push(auxb);
    }
    
    cin >> a >> b;
    auxa = fila_final.front();
    fila_final.pop();
    auxb = fila_final.front();
    fila_final.pop();
    if(a > b)
        cout << auxa << endl;
    else
        cout << auxb << endl;
    
    return 0;
}