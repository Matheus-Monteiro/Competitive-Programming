// simple matrix generator

#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}
 
int main(int argc, char* argv[]) {
   // atoi(s) converts an array of chars to int
   srand(atoi(argv[1])); 

   int n = rand(1, 3), m = rand(1, 3);

   cout << n << ' ' << m << endl;
   for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
         cout << rand(1, 5) << ' '; 
      }
      cout << endl;
   }

	return 0;
}