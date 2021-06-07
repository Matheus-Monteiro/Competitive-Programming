/*
    Funcao de Hash:
    
    Tome uma string S[0 ... n-1] e deois inteiros A e B
    
    (S[0]*A^n-1 + S[1]*A^n-2 + S[2]*A^n-3 + S[3]*A^n-4
    	 ... S[N-1]*A^0) mod B
*/

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;
 
typedef long long ll;
 
ll A = 911382323, B = 972663749;
ll h1[MAX], h2[MAX], p[MAX];
int arr[MAX];
string s;
 
ll buildH(ll *H, int k)
{
    if(k == 0)
        return H[0] = s[0];
    return H[k] = (buildH(H, k - 1)*A + s[k]) % B;
}
 
ll buildP(int k)
{
    if(k == 0) 
        return p[0] = 1;
    return p[k] = (buildP(k - 1)*A) % B;
}
 
ll vhash(ll *H, int a, int b)
{
    if(a == 0)
        return H[b];
    ll ans = (H[b] - H[a - 1] * p[b - a + 1]) % B;
    if(ans < 0)
        ans += B;
    return ans;
}

bool slidingWindow(int k)
{
    if(k < 0 or k > s.size()) return false;
    for(int i = 0; i + k - 1 < s.size(); i++)
        if(vhash(h1, i, i + k - 1) == vhash(h2, s.size()
        	 - (i + k - 1) - 1, s.size() - (i + k - 1) - 2 + k))
            return true; // A substring [i, i + k - 1] eh palindromo
    return false;
}

int buscab()
{
    int tam = 0;
    for(int i = 0; i < s.size(); i++)
        arr[i] = 2*i + 1, tam++;
    int b = 0, e = tam, m, ans = 0;
    while(b <= e)
    {
        m = (b + e) / 2;
        slidingWindow(arr[m]) ? b = m + 1, ans = arr[m] : e = m - 1;
    }
    tam = 0;
    for(int i = 0; i < s.size(); i++)
        arr[i] = 2*i, tam++;
    b = 0, e = tam;
    while(b <= e)
    {
        m = (b + e) / 2;
        slidingWindow(arr[m]) ? b = m + 1, 
        	ans = max(arr[m], ans) : e = m - 1;
    }
    return ans;
}

int main()
{
    cin >> s;
    buildH(h1, s.size()-1); 
    reverse(s.begin(), s.end());
    buildH(h2, s.size()-1);
    buildP(s.size()-1);
    reverse(s.begin(), s.end());
    cout << buscab() << '\n';
 
    return 0;
}
