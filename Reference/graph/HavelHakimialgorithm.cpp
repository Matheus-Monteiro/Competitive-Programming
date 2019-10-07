#include <bits/stdc++.h>
using namespace std;
 
bool havelHakimi(deque<int> degreeSequence)
{
    sort(degreeSequence.begin(), degreeSequence.end(), greater<int>());
    if(degreeSequence.front() > degreeSequence.size())
        return false;
    if(degreeSequence.back() < 0)
        return false;
    if(!degreeSequence.front())
        return true;
    int sum = accumulate(degreeSequence.begin(), degreeSequence.end(), 0);
    if(sum & 1)
        return false;
    int front = degreeSequence.front();
    degreeSequence.pop_front();
    for(int i = 0; i < front; ++i)
        --degreeSequence[i];
    return havelHakimi(move(degreeSequence));
}
 
int32_t main()
{
	int n;
	while(cin >> n)
	{
    	deque<int> degree(n);
    	for(int &i : degree)
    	    cin >> i;
        puts(havelHakimi(degree) ? "possivel" : "impossivel");
	}	
	return 0;
}
