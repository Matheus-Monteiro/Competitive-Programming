#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10; 
const int OO = 0x3f3f3f3f;

#define bug(x) cout << #x << " = " << x << '\n'
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mt make_tuple
//#define gc getchar_unlocked

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int main()
{
    int t;
    stack<char> p, k, c;
    
    scanf("%d", &t);
    while(t--)
    {
        char s[MAX];
        scanf("%s", s);
        int n = strlen(s);
        bool fl = true;
        REP(i, n)
        {
            if(i < n-1)
            {
                if(s[i] == '(' and (s[i+1] == ']' or s[i+1] == '}'))
                    fl = false;    
                else if(s[i] == '[' and ((s[i+1] == ')' or s[i+1] == '}')))
                    fl = false;    
                else if(s[i] == '{' and (s[i+1] == ']' or s[i+1] == ')'))
                    fl = false;    
                if(!fl) break;
            }
            if(s[i] == '(')
                p.push('(');
            else if(s[i] == '[')
                c.push('[');                
            else if(s[i] == '{')
                k.push('{');
            else
            {
                if(s[i] == ')')
                {
                    if(p.empty())
                        fl = false;
                    else
                        p.pop();
                }         
                else if(s[i] == ']')
                {
                    
                    if(c.empty())
                        fl = false;
                    else
                        c.pop();
                }
                else if(s[i] == '}')
                {
                    if(k.empty())
                        fl = false;
                    else
                        k.pop();
                }
            }
            if(!fl) break;
        }
        if(!p.empty() or !c.empty() or !k.empty()) fl = false;
        printf(fl ? "S\n" : "N\n");
        p = stack<char>();
        c = stack<char>();
        k = stack<char>();
    }

	return 0;
}