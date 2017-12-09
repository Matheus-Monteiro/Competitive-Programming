// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Animal
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1049

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    string a,b,c;
   
        cin >> a;
        
        if(a=="vertebrado"){
            cin >> b;
            if(b=="ave"){
                cin >> c;
                if(c=="carnivoro"){
                    printf("aguia\n");
                }
                
                if(c=="onivoro"){
                    printf("pomba\n");
                }
            }
            
            if(b=="mamifero"){
                cin >> c;
                if(c=="onivoro"){
                    printf("homem\n");
                }
                
                if(c=="herbivoro"){
                    printf("vaca\n");
                }
            }
        }
        
        
        if(a=="invertebrado"){
            cin >> b;
            if(b=="inseto"){
                cin >> c;
                if(c=="hematofago"){
                    printf("pulga\n");
                }
                
                if(c=="herbivoro"){
                    printf("lagarta\n");
                }
            }
            
            if(b=="anelideo"){
                cin >> c;
                if(c=="hematofago"){
                    printf("sanguessuga\n");
                }
                
                if(c=="onivoro"){
                    printf("minhoca\n");
                }
            }
        }
    return 0;
}
