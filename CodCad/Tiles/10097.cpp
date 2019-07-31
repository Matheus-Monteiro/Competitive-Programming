#include <iostream>

using namespace std;

struct ladrilho{
    int x;
    bool cor;
};

ladrilho m[205][205];
int l, c, cont;

void dfs(int a, int b){
    if(b+1 < c and m[a][b].x == m[a][b+1].x and !m[a][b+1].cor){
        cont++;
        m[a][b+1].cor = true;
        dfs(a, b+1);
    }
    if(a+1 < l and m[a][b].x == m[a+1][b].x and !m[a+1][b].cor){
        cont++;
        m[a+1][b].cor = true;
        dfs(a+1, b);
    }
    if(b-1 >= 0 and m[a][b].x == m[a][b-1].x and !m[a][b-1].cor){
        cont++;
        m[a][b-1].cor = true;
        dfs(a, b-1);
    }
    if(a-1 >= 0 and m[a][b].x == m[a-1][b].x and !m[a-1][b].cor){
        cont++;
        m[a-1][b].cor = true;
        dfs(a-1, b);
    }
}

int main(){
    cin >> l >> c;
    
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            cin >> m[i][j].x;
            m[i][j].cor = false;
        }
    }

    int menor = 0x3f3f3f3f;
    
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            cont = 1;
            if(!m[i][j].cor){
                m[i][j].cor = true;
                dfs(i, j);
                if(cont < menor)
                    menor = cont;
            }
        }
    }
    cout << menor << endl;
   
    return 0;
}