#include <bits/stdc++.h>
using namespace std;
 
int a,b; char sa[10000]; char sb[10000];
 
void rev(char s[])
{
	int l = strlen(s);
	for(int i = 0; i < l - 1 - i; i++)
		swap(s[i], s[l - 1 - i]);
}
 
void multi(char s[], int k)
{
	int i, c = 0, d;
	for(i=0;s[i];i++)
	{
		d = (s[i] - '0') * k + c;
		c = d / b; d %= b;
		s[i] = '0' + d;
	}
	while(c)
	{
		s[i] = '0' + (c % b); i++;
		c /= b;
	}
	s[i] = '\0';
}
 
void add(char s[], int k)
{
	int i, c = k, d;
	for(i = 0; s[i]; i++)
	{
		d = (s[i] - '0') + c;
		c = d / b; d %= b;
		s[i] = '0' + d;
	}
	while(c)
	{
		s[i] = '0' + (c % b); i++;
		c /= b;
	}
	s[i]='\0';
}
 
void trans(char s[])
{
	for(int i = 0; s[i]; i++)
	{
		char& c = s[i];
		if(c >= 'A' && c <= 'Z') c = '0' + 10 + (c - 'A');
		if(c >= 'a' && c <= 'z') c = '0' + 36 + (c - 'a');
	}
}
 
void itrans(char s[])
{
	for(int i = 0; s[i]; i++)
	{
		char& c = s[i]; int d = c - '0';
		if(d >= 10 && d <= 35) c = 'A' + (d - 10);
		if(d >= 36) c = 'a' + (d - 36);
	}
}
 
int main()
{
//digitos {0-9,A-Z,a-z}
	int q; cin>>q;
	int i,j;
	while(q)
	{
		q--;
		
		cin >> a >> b >> sa; sb[0] = '0'; sb[1] = '\0';
		// a e b sao dados na base 10
		// sa eh dado na base a
		// converter sa da base a pra base b
		cout << a << " " << sa << '\n';
		trans(sa);
		for(i = 0; sa[i]; i++)
		{
			multi(sb, a);
			add(sb, sa[i] - '0');
		}
		rev(sb);
		itrans(sb);
		// sb eh a na base b
		cout << b << " " << sb << '\n';
		puts("");
	}
	return 0;
}
