#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;
    char aux;
    int a0, a1;
        
    cin >> str;
    //por 4
    if(str.size() > 1){
        aux = str[str.size()-2];
        a1 = atoi(&aux); 
        aux = str[str.size()-1];
        a0 = atoi(&aux);
        if((a0+10*a1)%4 == 0)
            cout << "S" << endl;
        else
            cout << "N" << endl;
    }else{
        aux = str[str.size()-1];
        a0 = atoi(&aux);
        if(a0%4 == 0)
            cout << "S" << endl;
        else
            cout << "N" << endl;
    }
    
    //por 9 
    long long int soma = 0;
    for(int i = 0; i < str.size(); i++){
        aux = str[i];
        soma += atoi(&aux);
    }
    if(soma%9 == 0)
        cout << "S" << endl;
    else
        cout << "N" << endl;
    
    //por 25  
    soma = 0;   
    if(str.size() > 1){
        aux = str[str.size()-2];
        soma += 10*atoi(&aux); 
        aux = str[str.size()-1];
        soma += atoi(&aux);
        if(soma%25 == 0)
            cout << "S" << endl;
        else
            cout << "N" << endl;
    }else{
        if(str[0] == '0')
            cout << "S" << endl;
        else
            cout << "N" << endl;
    }
        
    return 0;
}