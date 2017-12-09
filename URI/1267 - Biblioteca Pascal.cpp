// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Biblioteca Pascal
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1267

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, d, aux;
    int arr[110];

   while(scanf("%d %d", &n, &d) and (n or d))
   {
        for(int i = 0; i < n; i++)
            arr[i] = 1;
        for(int k = 0; k < d; k++)
            for(int i = 0; i < n; i++)
            {
                scanf("%d", &aux);
                arr[i] &= aux;
            }
        bool flag = false;
        for(int i = 0; i < n and !flag; i++)
            flag = arr[i];
        cout << (flag ? "yes\n" : "no\n");
    }

    return 0;
}
