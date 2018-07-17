/*
    Para ficar realmente eficiente e suportar até 3,2 * 10^9 elementos
    usar B como um array global de tamanho 10^8.
*/

#include <bits/stdc++.h>
using namespace std;
 
struct Bitset
{
    vector<int> B;
    int aux, sz; // aux representa quantos bits estão sobrando, e sz o tamanho do bitset   
     
    void resize(int x)
    {
        sz = (x / 32) + 1;
        B.resize(sz);
        aux = x % 32;
        sz = x;
    }
     
    void set(int x)
    {
        int p = x / 32;
        int b = x % 32;
        B[p] |= (1 << b);
    }
     
    void reset(int x)
    {
        int p = x / 32;
        int b = x % 32;
        B[p] &= ~(1 << b);
    }
     
    bool isSet(int x)
    {
        int p = x / 32;
        int b = x % 32;
        return (B[p] & (1 << b));
    }

    void resetAll()
    {
        for(int i = 0; i < (int)B.size(); i++) 
            B[i] = 0;
    }
     
    void setAll()
    {
        int k = (int)B.size();
        for(int i = 0; i < k; i++) 
            B[i] = ~0;
        for(int i = 31; i >= aux; i--)
            B[k] &= ~(1 << i);
    }

    int count()
    {
        int k = (int)B.size(), cont = 0;
        for(int i = k - 1; i >= 0; i--)
        {
            int j = 31;
            if(k == int(B.size())) j = aux - 1;
            for(; j >= 0; j--)
                cont += (B[i] & (1 << j) ? 1 : 0);
        }
        return cont;
    }

    Bitset operator^(const Bitset &a)
    {
        Bitset ans;
        ans.resize(sz);
        for(int i = 0; i < sz; i++) 
           ans.B[i] = B[i] ^ a.B[i];
        return ans; 
    }

    Bitset operator&(const Bitset &a)
    {
        Bitset ans;
        ans.resize(sz);
        for(int i = 0; i < sz; i++) 
           ans.B[i] = B[i] & a.B[i];
       return ans; 
    }

    Bitset operator|(const Bitset &a)
    {
        Bitset ans;
        ans.resize(sz);
        for(int i = 0; i < sz; i++) 
           ans.B[i] = B[i] | a.B[i];
       return ans; 
    }

    void printtt()
    {
        int k = (int)B.size();
        for(int i = k - 1; i >= 0; i--)
        {
            int j = 31;
            if(k == int(B.size())) j = aux - 1;
            for(; j >= 0; j--)
                printf(B[i] & (1 << j) ? "1" : "0");
        }
        puts("");
    }

};

int main()
{
    Bitset b, c;
    
    b.resize(7);
    c.resize(7);
    
    b.set(1);
    b.set(5);
    c.set(5);
    c.printtt();
    b.printtt();
    
    b = b ^ c;   

    b.printtt();

    b.set(4);
    b.set(0);

    b.printtt();

    cout << b.count() << '\n';

	return 0;
}
