#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;

int n, blk_sz;
int arr[MAX], block[MAX];

void update(int idx, int val)
{
    int blockNumber = idx/blk_sz;
    block[blockNumber] += val - arr[idx];
    arr[idx] = val;
}

int query(int l, int r)
{
    int sum = 0;
    while(l < r and l%blk_sz != 0 and l != 0)
        sum += arr[l], l++;
    while(l+blk_sz <= r)
        sum += block[l/blk_sz], l += blk_sz;
    while(l <= r)
        sum += arr[l], l++;
    return sum;
}

void build()
{
    int blk_idx = -1;
    blk_sz = sqrt(n);
    for(int i = 0; i < n; i++)
    {
        if(i%blk_sz == 0)
            blk_idx++;
        block[blk_idx] += arr[i];
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    build();
    int o, l, r;
    while(cin >> o >> l >> r and o)
        if(o == 1)
            update(l-1, r);
        else
            cout << query(l-1, r-1) << '\n';

    return 0;
}
