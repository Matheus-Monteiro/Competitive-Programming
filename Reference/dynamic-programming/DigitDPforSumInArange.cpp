// tem no máximo idx*sum*tight estados, então, O(10 * idx * sum * tight)
// tight = 2, sum é no máximo 9*18, idx é no máximo 18. 10*18*9*18*2 da mais ou menos 10^5 operações

#include "bits/stdc++.h"
using namespace std;
 
long long dp[20][180][2];
 
long long getDigits(long long x, vector <int> &digit)
{
    while (x)
    {
        digit.push_back(x%10);
        x /= 10;
    }
}

long long digitSum(int idx, int sum, int tight, vector <int> &digit)
{
    if(idx == -1)
       return sum;
    if(dp[idx][sum][tight] != -1 and tight != 1)
        return dp[idx][sum][tight];
    long long ret = 0;
    int k = tight ? digit[idx] : 9;
    for(int i = 0; i <= k; i++)
    {
        int newTight = digit[idx] == i ? tight : 0;
        ret += digitSum(idx - 1, sum + i, newTight, digit);
    }
    if(!tight)
      dp[idx][sum][tight] = ret;
    return ret;
}

long long rangeDigitSum(int a, int b)
{
    memset(dp, -1, sizeof(dp));
    vector<int> digitA;
    getDigits(a-1, digitA);
    long long ans1 = digitSum(digitA.size() - 1, 0, 1, digitA);
    vector<int> digitB;
    getDigits(b, digitB);
    long long ans2 = digitSum(digitB.size() - 1, 0, 1, digitB);
    return (ans2 - ans1);
}

int main()
{
    long long a = 1LL, b = 13LL;
    cout << "digit sum for given range : " << rangeDigitSum(a, b) << '\n';

    return 0;
}