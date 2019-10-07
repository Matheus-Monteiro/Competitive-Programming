#include <bits/stdc++.h>
using namespace std;
 
int n, m;
int arr[100];
int cnt[10000];
int aux[100];
 
void count_sort()
{
    for(int i = 0; i < n; i++)
        cnt[arr[i]]++;
    for(int i = 1; i <= m; i++)
        cnt[i] += cnt[i-1];
    for(int i = 0; i < n; i++)
        aux[--cnt[arr[i]]] = arr[i];
    memcpy(arr, aux, n*sizeof(int));
}
 
int main()
{   
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i], m = max(arr[i], m);
 
    count_sort();
 
    for(int i = 0; i < n; i++)
    	cout << arr[i] << ' '; cout << '\n';
 
    return 0;
}
