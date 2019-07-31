#include <iostream>

using namespace std;

int main(){
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