#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, ans, aux;
    scanf("%d %d", &n, &ans);
    for(int i = 1; i < n; i++)
        scanf("%d", &aux), ans = __gcd(ans, aux);
    cout << ans << '\n';

    return 0;
} 