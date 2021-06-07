#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 10; 
const int OO = 0x3f3f3f3f;
const double EPS = 1e-9; 

#define bug(x) cout << #x << " = " << x << '\n'
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mt make_tuple
#define all(vetor) vetor.begin(), vetor.end()
#define X real()
#define Y imag()
//#define gc getchar_unlocked

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<int, ii> iii;
typedef complex<ll> Pll;
typedef complex<ld> Pld;

struct TrieNode
{
    int value;
    TrieNode *children[2];
    TrieNode()
    {
        value = 0;
        children[0] = children[1] = nullptr;
    }
};

void insert(TrieNode *root, int n)
{
    TrieNode *aux = root;
    for(int i = 31; i >= 0; i--)
    {
        bool b = (n & (1 << i));
        if(aux->children[b] == nullptr)
            aux->children[b] = new TrieNode();
        aux = aux->children[b];
    }
    aux->value = n;
}

int query(TrieNode *root, int n)
{
    TrieNode *aux = root;
    for(int i = 31; i >= 0; i--)
    {
        bool b = (n & (1 << i));
        if(aux->children[1-b] != nullptr)
            aux = aux->children[1-b];
        else
            aux = aux->children[b];
    }
    return n ^ aux->value;
}

void maxSubArrayXor(int *arr, int n)
{
    TrieNode *root = new TrieNode();
    insert(root, 0);
    int px = 0, ans = INT_MIN, r = -1;
    for(int i = 0; i < n; i++)
    {
        px = px ^ arr[i];
        insert(root, px);
        int num = max(ans, query(root, px));
        if(num > ans)
            ans = num, r = i;
    }
    int l = r, xo = 0;
    for(; l >= 0; l--)
    {
        xo ^= arr[l];
        if(xo == ans)
            break;
    }
    cout << "O Xor maximo eh: " << ans << '\n';
    while(l <= r)
        cout << arr[l++] << ' ';
    cout << '\n';
}

int main()
{	
    int arr[MAX], n;

    cin >> n;
    REP(i, n) cin >> arr[i];
    maxSubArrayXor(arr, n);

	return 0;
}
