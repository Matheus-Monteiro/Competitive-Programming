#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4;

int n;
int LI[MAX], LD[MAX];
vector<int> arr;

int LIS() {
    for(int i = 0; i < n; i++)
        LI[i] = 1;
    for(int i = n - 1; i >= 0; i--)
        for(int j = 0; j < i; j++)
            if(arr[j] < arr[i])
                LI[j] = max(LI[j], LI[i] + 1);  
}

int LDS() {
    reverse(arr.begin(), arr.end());
    for(int i = 0; i < n; i++)
        LD[i] = 1;
    vector<int> pilha;
    for(int i = 0; i < n; i++) {
        int p = (int)(lower_bound(pilha.begin(),
        	pilha.end(), arr[i]) - pilha.begin());
        if(p == pilha.size())
            pilha.push_back(arr[i]);
        else
            pilha[p] = arr[i];
        LD[i] = p + 1;
    }
                
}

int main() {	
    cin >> n; arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
   
    LIS();
    LDS();
    
    for(int i = 0; i < n; i++)
    	cout << LI[i] << ' '; puts("");
    for(int i = 0; i < n; i++)
    	cout << LD[n - i - 1] << ' '; puts("");
   
	return 0;
}
