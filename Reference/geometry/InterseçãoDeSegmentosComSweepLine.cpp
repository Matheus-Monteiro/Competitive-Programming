#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4;

struct Point
{
    int x, y;
    Point(int _x, int _y)
    {
        x = _x, y = _y;
    }
    Point(){}
};

Point arr[MAX];
int BIT[MAX], seg[MAX], pos[MAX], cor[MAX];

void update(int x, int val)
{
    while(x < MAX)
        BIT[x] += val, x += x&-x;
}

int query(int x)
{
    int sum = 0;
    while(x)
        sum += BIT[x], x -= x&-x;
    return sum;
}

int main()
{
    int n, x1, y1, x2, y2;
    
    cin >> n;
    int cur = 0, id = 0;   
    for(int i = 0; i < n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        seg[cur] = id;
        pos[cur] = cur;
        arr[cur++] = Point(x1+1, y1+1);
        seg[cur] = id++;
        pos[cur] = cur;
        arr[cur++] = Point(x2+1, y2+1);
    }
    sort(pos, pos+cur, [](int a, int b){return arr[a].x < arr[b].x;});
    int ans = 0;
    for(int i = 0; i < cur; i++)
    {
        if(arr[pos[i]].x == arr[pos[i+1]].x and seg[pos[i]] == seg[pos[i+1]])
        {
            int aux = ans;
            ans += query(max(arr[pos[i]].y, arr[pos[i+1]].y)); 
            ans -= query(min(arr[pos[i]].y, arr[pos[i+1]].y)-1);
            i++;
        }
        else
        {   
            if(!cor[seg[pos[i]]])
            {
                update(arr[pos[i]].y, 1);
                cor[seg[pos[i]]]++;
            }
            else
            {
                update(arr[pos[i]].y, -1);
                cor[seg[pos[i]]]--;
            }
        }
    }
    cout << ans << '\n';
    
    return 0;
}