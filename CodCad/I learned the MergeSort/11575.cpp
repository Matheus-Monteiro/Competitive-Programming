#include <bits/stdc++.h>
#define INF -(1<<30)

using namespace std;

void merge_sort(vector<int> &v){
	if(v.size()==1) return;
	
	vector<int> u1, u2;
	
	for(int i=0;i<v.size()/2;i++) u1.push_back(v[i]);
	for(int i=v.size()/2;i<v.size();i++) u2.push_back(v[i]);
	
	merge_sort(u1);
	merge_sort(u2);
	
	u1.push_back(INF);
	u2.push_back(INF);
	
	int ini1=0, ini2=0;
	
	for(int i=0;i<v.size();i++){
		if(u1[ini1]>u2[ini2]){
			v[i]=u1[ini1];
			ini1++;
		}else{
			v[i]=u2[ini2];
			ini2++;
		}
	}
	
	return;
}


int main(){
    int n;
    vector<int> v;
    cin >> n;
    v.resize(n);
    for(auto &p : v)
        cin >> p;
        
    merge_sort(v);
   
    int i = 0;
    for(auto &p : v){
        cout << p;
        if(i < v.size()-1)
            cout << " ";
        i++;
    }
    cout << endl;
 
    return 0;
}