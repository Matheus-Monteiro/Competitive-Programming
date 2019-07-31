#include <iostream>
#include <algorithm>
const int MAXN = 1e5;

using namespace std;

struct horario{
    int x, y;
};

bool comp(horario a, horario b){
    return a.y < b.y;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    horario agenda[MAXN];
    
    cin >> n;
    
    for(int i = 0; i < n; i++)
        cin >> agenda[i].x >> agenda[i].y;
        
    int cont = 1;
    
    sort(agenda, agenda+n, comp);
    
    horario aux = agenda[0];
    
    for(int i = 1; i < n; i++){
        if(aux.y <= agenda[i].x){
            cont++;
            aux = agenda[i];
        }   
    }
    
    cout << cont << '\n';
    
    return 0;
}