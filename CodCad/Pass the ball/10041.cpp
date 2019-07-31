#include <iostream>
#define MAXN 110

using namespace std;

struct tabuleiro{
    int x;
    bool bandeira;
};

tabuleiro quadrado[MAXN][MAXN];
int n;

void busca(int a, int b){
    if(b+1 < n and quadrado[a][b+1].x >= quadrado[a][b].x and !quadrado[a][b+1].bandeira){
        quadrado[a][b+1].bandeira = true;
        busca(a, b+1);
    }
    if(a+1 < n and quadrado[a+1][b].x >= quadrado[a][b].x and !quadrado[a+1][b].bandeira){
        quadrado[a+1][b].bandeira = true;
        busca(a+1, b);
    }
    if(b-1 >= 0 and quadrado[a][b-1].x >= quadrado[a][b].x and !quadrado[a][b-1].bandeira){
        quadrado[a][b-1].bandeira = true;
        busca(a, b-1);
    }
    if(a-1 >= 0 and quadrado[a-1][b].x >= quadrado[a][b].x and !quadrado[a-1][b].bandeira){
        quadrado[a-1][b].bandeira = true;
        busca(a-1, b);
    }
}

int main(){
    int p1, p2;
    cin >> n >> p1 >> p2;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> quadrado[i][j].x;
            quadrado[i][j].bandeira = false;
        }
    }
    
    quadrado[p1-1][p2-1].bandeira = true;
    busca(p1-1, p2-1);
          
    int cont = 0;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(quadrado[i][j].bandeira == true)
                cont++;
        
    cout << cont << endl;   
          
    return 0;
}