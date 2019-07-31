#include <iostream>
#include <map>

using namespace std;

int main(){
    
    multimap<int, int> C;
    multimap<int, int> I;
    multimap<int, int> R;
    int a, b, aux1, aux2;
    
    cin >> a >> b;
   
    while(a--){
        cin >> aux1 >> aux2;
        C.insert(make_pair(aux1, aux2));
    }
    
    while(b--){
        cin >> aux1 >> aux2;
        I.insert(make_pair(aux1, aux2));
    }

    multimap<int, int>::iterator it, aux;
    
    for(it = I.begin(); it != I.end(); it++){
        aux = C.find(it->first);
        if(C.find(it->first) != C.end() and it->second > aux->second or C.find(it->first) == C.end()){
            if(R.find(it->first) != R.end()){
                aux = R.find(it->first);
                if(aux->second < it->second){
                    R.erase(aux);
                    R.insert(*it);
                }
            }else{
                R.insert(*it);
            }
        }
    }
    
    for(it = R.begin(); it != R.end(); it++)
        cout << it->first << " " << it->second << endl;

    return 0;
}