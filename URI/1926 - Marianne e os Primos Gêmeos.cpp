// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Marianne e os Primos Gêmeos
// Nível: 4
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1926

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6;

vector<int> primo;
int e_composto[MAX+5];
int gemeo[MAX+5];
int tree[10*MAX+5];

void crivo(){
    e_composto[1] = 1;
    for(int i = 2; i <= MAX+2; i++)
        if(!e_composto[i]){
            primo.push_back(i);
            for(int j = 2; i*j <= MAX+2; j++)
                e_composto[i*j] = 1;
        }
}

void build(int node, int start, int end){
	if(start == end){
		tree[node] = gemeo[start];
	}else{
		int mid =  (start+end)/2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node] = tree[2*node] + tree[2*node+1];
	}
}

int query(int node, int start, int end, int l, int r){
	if(l > end or r < start)
		return 0;
	if(l <= start and end <= r)
		return tree[node];
	int mid = (start + end)/2;
	int p1 = query(2*node, start, mid, l, r);
	int p2 = query(2*node+1, mid+1, end, l, r);
	return (p1+p2);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
    int n, x, y;
    int ans;

    crivo();
	for(int i = 1; i < primo.size(); i++)
		if(abs(primo[i] - primo[i-1]) == 2)
			gemeo[primo[i]] = gemeo[primo[i-1]] = 1;

	build(1, 0, MAX+2);
		
    cin >> n;
    while(n--){
        cin >> x >> y;
  		if(x > y) swap(x, y);
		cout << query(1, 0, MAX+2, x, y) << '\n';
    }

    return 0;
}
