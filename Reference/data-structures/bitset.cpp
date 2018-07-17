/*
    Para ficar realmente eficiente e suportar até 3,2 * 10^9 elementos
    usar B como um array global de tamanho 10^8.
*/

#include <bits/stdc++.h>
using namespace std;
 
struct Bitset
{
    vector<int> B;    
     
    void resize(int x)
    {
        int sz = (x / 32) + 1;
        B.resize(sz);
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
        for(int i = 0; i < (int)B.size(); i++) 
            B[i] = ~0;
    }

    Bitset operator^(const Bitset &a)
    {
        int k = (int)B.size();
        Bitset ans;
        ans.resize(k);
        for(int i = 0; i < k; i++) 
           ans.B[i] = B[i] ^ a.B[i];
       return ans; 
    }

    Bitset operator&(const Bitset &a)
    {
        int k = (int)B.size();
        Bitset ans;
        ans.resize(k);
        for(int i = 0; i < k; i++) 
           ans.B[i] = B[i] & a.B[i];
       return ans; 
    }

    Bitset operator|(const Bitset &a)
    {
        int k = (int)B.size();
        Bitset ans;
        ans.resize(k);
        for(int i = 0; i < k; i++) 
           ans.B[i] = B[i] | a.B[i];
       return ans; 
    }

    void printtt()
    {
        int k = (int)B.size();
        for(int i = k - 1; i >= 0; i--)
            for(int j = 31; j >= 0; j--)
                printf(B[i] & (1 << j) ? "1" : "0");
        puts("");
    }

};

int main()
{
    Bitset b, c;
    
    b.resize(10);
    c.resize(10);
    
    b.set(1);
    b.set(5);
    c.set(5);
    c.printtt();
    b.printtt();
    
    b = b ^ c;   

    b.printtt();

    c = b | c;
    
    c.printtt();

    b.setAll();

    c = b & c;

    b.printtt();
    c.printtt();

	return 0;
}
