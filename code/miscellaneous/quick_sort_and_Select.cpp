#include <bits/stdc++.h>
using namespace std;

int n, arr[10000];

int quickselect(int l, int r, int k)
{
    int j = l - 1;
    for(int i = l; i < r; i++)
        if(arr[i] <= arr[r])
            swap(arr[++j], arr[i]);
    swap(arr[j+1], arr[r]);
    if(j+1 < k) return quickselect(j+2, r, k);
    else if(j+1 > k) return quickselect(l, j, k);
    return arr[j+1];
}

void quicksort(int l, int r)
{
    int j = l - 1;
    for(int i = l; i < r; i++)
        if(arr[i] <= arr[r])
            swap(arr[++j], arr[i]);
    swap(arr[j+1], arr[r]);
    if(l < j)
        quicksort(l, j);
    if(j+2 < r)
        quicksort(j+2, r);
}

int main()
{
    int k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << quickselect(0, n-1, k-1) << '\n';
    
    return 0;
}
