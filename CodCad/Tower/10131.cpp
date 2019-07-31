#include <iostream>
#define endl '\n'
#define MAXN 1005

using namespace std;

int m[MAXN][MAXN];
int linha[MAXN];
int coluna[MAXN];
int n;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> m[i][j];
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            linha[i] += m[i][j];
            coluna[i] += m[j][i];
        }
    }
    
    int peso, maior = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            peso = linha[i] + coluna[j] - 2*m[i][j];
            if(maior < peso)
                maior = peso;
        }
    }
    
    cout << maior << endl;
    
    return 0;
}