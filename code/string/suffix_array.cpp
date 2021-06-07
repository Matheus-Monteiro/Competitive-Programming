#include <bits/stdc++.h>
using namespace std;
 
string txt; // texto
string pat; // padrao
int n; // tamanho do texto
int chave[100]; // chave para comparacao dos sufixos
int vs[100]; // vetor de sufixos
int ord[100]; // ordem de um sufixo (qual classe ele pertence)
int lcp[100]; // maior prefixo comum
 
bool comp(int a, int b)
{
    return chave[a] < chave[b];
}
 
void constroi()// O(N*Log(N)*Log(N))
{
    for(int i = 0; i < n; i++)
    {
        vs[i] = i;
        chave[i] = txt[i] - 'a' + 1;
    }
    sort(vs, vs+n, comp);
    for(int i = 0; ; i++)
    {
        int classes = 0;
        for(int j = 0; j < n; j++)
            ord[vs[j]] = j > 0 and chave[vs[j]] 
            	== chave[vs[j-1]] ? ord[vs[j-1]] : ++classes;
        if(classes == n) break; 
        for(int j = 0; j < n; j++)
        {
            chave[j] = ord[j]*(classes+1);
            chave[j] += j+(1<<i) < n ? ord[j+(1<<i)] : 0;
        }
        sort(vs, vs+n, comp);
    }
}
 
int strcompara(int pos)
{// retorna 0 se o padrao esta no sufixo, maior que zero se o padrao eh
//lexicograficamente maior que o sufixo, e menor que 0 se o padrao 
//eh lexicograficamente menor que o sufixo
    for(int i = 0; i < pat.size(); i++)
        if(i+pos >= n)
            return 1;
        else if(pat[i] != txt[i+pos])
            return pat[i] - txt[i+pos];
    return 0;
}
 
bool search()// O(Size(Pat)*Log(N))
{
    int b = 0, e = n - 1, m, aux;
    while(b <= e)
    {
        m = (b + e) / 2;
        aux = strcompara(vs[m]);
        if(aux == 0)
            return true;
        else if(aux > 0)        
            b = m + 1;
        else
            e = m - 1;
    }
    return false;
}

// numero de vezes que o padrao aparece no texto. O(Size(Pat)*Log(N))
int numberOfOcur()
{
    int b = 0, e = n - 1, m, aux, l = INT_MAX, r = INT_MIN;
    while(b <= e)
    {
        m = (b + e) / 2;
        aux = strcompara(vs[m]);
        if(aux == 0)
        {
            l = min(l, m);
            e = m - 1;
        }
        else if(aux > 0)        
            b = m + 1;
        else
            e = m - 1;
    }
    b = 0, e = n - 1;
    while(b <= e)
    {
        m = (b + e) / 2;
        aux = strcompara(vs[m]);
        if(aux == 0)
        {
            r = max(r, m);
            b = m + 1;
        }
        else if(aux > 0)        
            b = m + 1;
        else
            e = m - 1;
    }
    return abs(r-l+1);
}
 
// kasai em O(NlogN) pra construir o LCP (longest common prefix)
void kasai()
{
    vector<int> invSuff(n, 0);
    for(int i = 0; i < n; i++)
        invSuff[vs[i]] = i;
    int k = 0;
    for(int i = 0; i < n; i++)
    {
        if(invSuff[i] == n-1)
        {
            k = 0;
            continue;
        }
        int j = vs[invSuff[i]+1];
        while(i + k < n and j + k < n and txt[i + k] == txt[j + k])
            k++;
        lcp[invSuff[i]] = k;
        if(k > 0)
            k--;
    }
}
 
void printAll()
{
    cout << "Vetor de sufixos:\n";
    for(int i = 0; i < n; i++)
        cout << vs[i] << ' ';
    cout << '\n';
    cout << "Sufixos em ordem:\n";
    for(int i = 0; i < n; i++)
        cout << txt.substr(vs[i]) << '\n';
}
 
/*
	Dado um array LCP onde LCP[i] armazena o tamanho do maior prefixo
	 em comum entre os sufixos i e i + 1 da suffix array
	, entao para achar o maior prefixo em comum entre dois sufixos que
	 estao nas posicoes a e b da suffix array, corresponde a achar
	  o menor valor no intervalo [a, b-1] no LCP array.

	Outra aplicacao eh dada uma string, para contar quantas substrings
	 diferentes ela tem basta contar quantas tem no total ( ((n + 1) * n)/2
	  possiveis substrings) e remover todos os valores de LCP do total.
*/

int main()
{
    cin >> txt;
    n = txt.size();
    constroi();
    printAll();
 
    cout << '\n';
 
    cin >> pat;
    cout << (search() ? "found " : "not found ") <<  numberOfOcur()  << " vez(es)\n\n";
    
    kasai();
    cout << "LCP\n";
    for(int i = 0; i < n; i++)
    	cout << lcp[i] << ' ';
    cout << '\n';
 
    return 0;
}
