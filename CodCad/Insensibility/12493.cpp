#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, dis, ins = 0;
    int x0, y0, x1, y1;
    
    cin >> n;
    
    while(n--){
        cin >> x0 >> y0 >> x1 >> y1;
        dis = pow((x0-x1),2) + pow((y0-y1),2);
        ins += dis;
    }
    cout << ins << endl;
    
    return 0;
}