#include <bits/stdc++.h>
const int MAX = 1e6 + 10; 
using namespace std;

int n, arr[MAX], pos[MAX], newArr[MAX], realValue[MAX];
 
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i], pos[i] = i;
    sort(pos, pos + n, [](int i, int j){ return arr[i] < arr[j]; });    
    int id = 1;
    for(int i = 0; i < n; i++)
    {
    if(!i) newArr[pos[i]] = id, realValue[id] = arr[pos[i]];
    else if(arr[pos[i-1]] == arr[pos[i]]) newArr[pos[i]] = newArr[pos[i-1]]; 
    else newArr[pos[i]] = ++id, realValue[id] = arr[pos[i]];
    }
    for(int i = 0; i < n; i++)
        cout << arr[i] << ' ' << newArr[i] <<
        	 ' ' << realValue[newArr[i]] << '\n';
    

    return 0;
} 
