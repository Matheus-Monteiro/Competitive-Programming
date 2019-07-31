#include <iostream>
#include <set>

using namespace std;

int main(){
    
    int a, b, aux, cont;
    set<int> A;
    set<int> B;
    
    cin >> a >> b;
    
    while(a--){
        cin >> aux;
        A.insert(aux);
    }
    
    while(b--){
        cin >> aux;
        B.insert(aux);
    }
    
    if(A.size() > B.size())
        swap(A, B);
        
    cont = 0;
    
    for(set<int>::iterator it = A.begin(); it != A.end(); it++)
        if(B.find(*it) != B.end())
            cont++;
    
    int res = A.size() - cont;
            
    cout << res << endl;
    
    return 0;
}