#include <iostream>
#define endl '\n' 

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
    int n, c;
    string str, gab;
    cin >> n >> str >> gab;
    c = 0;
    for(int i = 0; i < str.size(); i++)
    	if(str[i] == gab[i])
    		c++;
    cout << c << endl;
    
    return 0;
}