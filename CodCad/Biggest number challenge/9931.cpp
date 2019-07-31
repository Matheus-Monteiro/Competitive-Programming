#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int aux;

int main(){
    
    while(cin >> aux and aux != 0){
        v.push_back(aux);
    }
   
    int maior = 0;
    
    for(int i = 0; i < v.size(); i++)
        if(v[i] > maior)
            maior = v[i];
            
    cout << maior << endl;
   
    return 0;
}