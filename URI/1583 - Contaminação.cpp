// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Contaminação
// Nível: 3
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1583

#include <bits/stdc++.h>
using namespace std;

int R, C;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
char grid[55][55];

void floodfill(int r, int c, char c1, char c2){
	if(r < 0 or r >= R or c < 0 or c >= C) return;
	if(grid[r][c] != c1) return;
	grid[r][c] = c2;
	for(int d = 0; d < 4; d++)
		floodfill(r+dr[d], c+dc[d], c1, c2);
}

int main(){
	while(cin >> R >> C and (R or C)){
		for(int i = 0; i < R; i++)
			cin >> grid[i];
		for(int i = 0; i < R; i++)
			for(int j = 0; j < C; j++)
				if(grid[i][j] == 'T'){
					grid[i][j] = 'A';
					floodfill(i, j, 'A', '.');
				}
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				if(grid[i][j] == '.') cout << 'T';
				else cout << grid[i][j];
			}
		cout << '\n';
		}				
		cout << '\n';
	}
	
	return 0;
}
