#include <bits/stdc++.h>
using namespace std;
 
#define gc getchar_unlocked
#define pc putchar_unlocked

inline void scanint(int &k)
{
	bool sinal = true;
    register char c;
    k = 0;
    for(c = gc(); sinal and (c < '0' or c > '9'); c = gc())
    	if(c == '-')
    		sinal = false;
    for(; c >= '0' and c <= '9'; c = gc())
        k = (k << 3) + (k << 1) + c - '0';
	if(!sinal) k = -k;
}
 
inline void printint(int n)
{
	if(n < 0) pc('-');
	n = abs(n);
	int rev = n, cnt = 0;
	if(!n)
	{
		pc('0');
		pc('\n');
		return;
	}
	while(!(rev % 10))
		cnt++, rev /= 10;
	rev = 0;
	while(n)
		rev = (rev << 3) + (rev << 1) + n % 10, n /= 10;
	while(rev)
		pc(rev % 10 + '0'), rev /= 10;
	while(cnt--)
		pc('0');
	pc('\n');
}

inline void scanstr(string &k)
{
    register char c;
	k = "";
    for(c = gc(); c < 'a' or c > 'z'; c = gc());
    for(; c >= 'a' and c <= 'z'; c = gc()) k.push_back(c);
}
 
inline void printstr(string &k)
{
	for(char &c : k) putchar(c);
	putchar('\n');
}
 
int main()
{
	int k;
	scanint(k);
	printint(k);
	
    return 0;
} 
