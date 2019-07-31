#include <iostream>
const int MAXN = 1001000;

using namespace std;

int tree[MAXN], A[MAXN];

void build(int node, int start, int end){
    if(start == end)
        tree[node] = A[start];
    else{
        int mid = (start + end)/2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = tree[2*node] * tree[2*node+1];
    }
}

void update(int node, int start, int end, int idx, int val){
    if(start == end){
        A[idx] = val;
        tree[node] = val;
    }else{
        int mid = (start + end)/2;
        if(start <= idx and idx <= mid)
            update(2*node, start, mid, idx, val);
        else
            update(2*node+1, mid+1, end, idx, val);
        tree[node] = tree[2*node] * tree[2*node+1];
    }
}

int query(int node, int start, int end, int l, int r){
    if(r < start or l > end)
        return 1;
    if(l <= start and r >= end)
        return tree[node];
    int mid =(start + end)/2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 * p2);
}

int main(){
    int n, m, a, b, aux;
    char c;
    while(cin >> n >> m){
        for(int i = 0; i < n; i++){
            cin >> aux;
            if(aux > 0)
                A[i] = 1;
            else
                if(aux < 0)
                    A[i] = -1;
                else
                    A[i] = 0;
        }
        build(1, 0, n-1);
        while(m--){
            cin >> c >> a >> b;
            if(c == 'C'){
                if(b > 0)
                    update(1, 0, n-1, a-1, 1);
                else
                    if(b < 0)
                        update(1, 0, n-1, a-1, -1);
                    else
                        update(1, 0, n-1, a-1, 0);
            }else{
                aux = query(1, 0, n-1, a-1, b-1);
                if(aux > 0)
                    cout << '+';
                else
                    if(aux < 0)
                        cout << '-';
                    else
                        cout << '0';
            
            }
        }
        cout << '\n';
    }
    return 0;
}