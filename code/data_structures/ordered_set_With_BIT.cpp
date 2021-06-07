#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+10;

int bit[MAX], arr[MAX];

int bitSearch(int v) 
{
	int sum = 0, pos = 0, LOGN = log2(MAX - 2);
	for(int i = LOGN; i >= 0; i--)
		if(pos + (1 << i) < MAX and sum + bit[pos + (1 << i)] < v)
		{
			sum += bit[pos + (1 << i)];
			pos += (1 << i);
		}
	return pos + 1; 
	// pos + 1, pq pos eh a maior posicao cuja soma do prefixo ate
	// ela eh menor que V 
}
// essa funcao retorna o indice J no array em que a soma do 
// prefixo [1, J] eh o lower_bound para V 
// inserir os elemento na BIT com add(i, arr[i]), para todo i em [1, n]

int query(int idx)// soma de um prefixo
{
	int sum = 0;
	for(; idx > 0; idx -= idx&-idx) sum += bit[idx];
	return sum;
}

void add(int idx, int k)
{
	for(int i = idx; i < MAX; i += i&-i) bit[i] += k;
}

int smallerCount(int v) 
{
	return query(v);
}

int count(int v)
{
	return query(v) - query(v - 1);
}

int greaterCount(int v)
{
	return query(MAX - 3) - query(v - 1);
}

int orderOfKey(int v)
{
	return smallerCount(v);
}

int kth(int k)
{
	return bitSearch(k);
}

int main()
{	
	int n;
	
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		add(arr[i], 1);
	}
	cout << smallerCount(3) << '\n';
	cout << count(3) << '\n';
	cout << greaterCount(3) << '\n';
	cout << kth(2) << '\n';
	cout << orderOfKey(4) << '\n';
		
    return 0;
}
