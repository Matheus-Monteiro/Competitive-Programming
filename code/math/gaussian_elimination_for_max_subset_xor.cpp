#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

int MSB(ull n)
{
    int cnt = 0;
    while(n)
    {
        cnt++;
        n >>= 1;
    }
    return cnt;
}

int main()
{   
    int n;
    cin >> n;
    ull a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int lengths[n]; 
    for(int i = 0; i < n; i++)
        lengths[i] = MSB(a[i]);
    //eh um array que armazena os coeficientes 
    //das equacoes
    vector<ull> buckets[65];
    //para a Gaussian Elimination, semelhante
    //a linha da matriz em algebra linear
    for(int i = 0; i < n; i++)
        buckets[lengths[i]].push_back(a[i]);
    ull modified_array[100], m_index = 0;

    // Gaussian Elimination
    for(int i = 64; i > 0; i--)
        if(buckets[i].size())
        {
            modified_array[m_index++] = buckets[i][0];
            for(int j = 1; j < buckets[i].size(); j++)
            {
                ull temp = buckets[i][0] ^ buckets[i][j];
                int len = MSB(temp);
                buckets[len].push_back(temp);
            }
        }
    ull ans = 0;
    for(int i = 0; i < m_index; i++) 
        if(ans < (ans ^ modified_array[i]))
            ans = (ans ^ modified_array[i]);
    cout << ans << '\n';

    return 0;
}
