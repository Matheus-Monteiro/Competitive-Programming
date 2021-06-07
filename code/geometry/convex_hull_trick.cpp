#include <bits/stdc++.h>
using namespace std;
#define type int
const int MAX = 1e5;
const int OO = 0x3f3f3f3f;
 
struct line
{
	type m, b;
	line(type _m, type _b){ m = _m, b = _b; }
};
 
int pointer;//Keeps track of the best line from previous query
vector<line> hull;//store hull
 
//Returns true if line l3 is always better than line l2
bool bad(int l1, int l2, int l3)
{
	/*
    intersection(l1,l2) has x-coordinate (b1-b2)/(m2-m1)
	intersection(l1,l3) has x-coordinate (b1-b3)/(m3-m1)
	set the former greater than the latter, and cross-multiply to
    eliminate division
    */
	line L1 = hull[l1], L2 = hull[l2], L3 = hull[l3];
	return (L3.b-L1.b)*(L1.m-L2.m) < (L2.b-L1.b)*(L1.m-L3.m);
}
 
//Adds a new line
void add(type m, type b)
{
    if(hull.size() > 0 and hull.back().m == m) return;
     //First, let's add it to the end
    hull.emplace_back(m, b);
    //If the penultimate is now made irrelevant between the antepenultimate
    //and the ultimate, remove it. Repeat as many times as necessary
    while(hull.size()>=3 and bad(hull.size()-3,hull.size()-2,hull.size()-1))
        hull.erase(hull.end()-2);
}
 
//Returns y value of a function i
type eval(int i, type x)
{
	return hull[i].m * x + hull[i].b;
}
 
//Returns the minimum y-coordinate of any intersection
//between a given vertical line and the lower envelope
//O(N) for all queries (queries are in ascending order of x)
type query(type x)
{
    if(pointer >= hull.size())
        pointer = hull.size() - 1;
    while(pointer < hull.size()-1 and eval(pointer+1, x) < eval(pointer, x))
		pointer++;
    return eval(pointer, x);
}
 
//Returns the minimum y-coordinate of any intersection
//between a given vertical line and the lower envelope
//O(LogN) time (queries are in any order of x)
type binarySearch(type x)
{
	int b = 0, e = hull.size() - 1;
	while(b < e)
	{
		int mid = (b + e) / 2;
		if(eval(mid+1, x) < eval(mid, x)) b = mid + 1;
		else e = mid;
	}
	return eval(b, x);
}
 
/*
    Maximum Y coordenate query, we have two options:
    1) Maximum Y-coordenate query: multiply m and b by -1 and
    make minimum Y-corrdenate query... 
    
    2) Order lines by increasing m if m is not equal, otherwise by decreasing b
       in the function query and binary Search change < to >
            eval(pointer+1, x) < eval(pointer, x)
            to,
            eval(pointer+1, x) > eval(pointer, x)
*/
 
int main()
{
	int n;
    cin >> n;
    //Order lines by decreasing m if m is not equal, otherwise by increasing b
    for(int i = 0; i < n; i++)
    {
        int m, b;
        cin >> m >> b;			
        add(m, b);
    }
    int q;
    cin >> q;
    vector<int> queries(q);//queries are in ascending order of x - run in O(N)
    for(int &w : queries)
		cin >> w;
	//processing queries in ascending order of x
	for(int &w : queries)
		cout << query(w) << '\n';
 
 	int x;
 	while(cin >> x)//queries are in any order of x - run in O(logN)
 		cout << binarySearch(x) << '\n';
 
    return 0;
}
