#include <bits/stdc++.h>
using namespace std;
#define matrix vector<vector<int>>
 
matrix init(int n, int m, int value = 0)
{
    return vector<vector<int>>(n, vector<int>(m, value));
}
 
void printtt(const matrix &M)
{
    for(int i = 0; i < M.size(); i++)
    {
        for(int j = 0; j < M[0].size(); j++)
            cout << M[i][j] << ' ';
        puts("");
    }    
}
 
matrix multiply(const matrix &A, const matrix &B)
{
    matrix C = init(A.size(), B[0].size());
    for(int i = 0; i < A.size(); i++)
        for(int j = 0; j < B[i].size(); j++)
            for(int k = 0; k < B.size(); k++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}
 
matrix exp(matrix M, int k)
{
    matrix I = init(M.size(), M[0].size());
    for(int i = 0; i < M.size(); i++) I[i][i] = 1;
    while(k)
        if(k & 1) I = multiply(I, M), k--;
        else M = multiply(M, M), k /= 2;
    return I;
}
 
 
int determinantOfMatrix(matrix mat)   
{   
	int n = mat.size();
    int num1, num2, det = 1, index, total = 1;   
    int temp[n + 1];   
    for(int i = 0; i < n; i++)    
    {  
        index = i; 
        while(mat[index][i] == 0 and index < n)   
            index++;       
        if(index == n)
            continue;   
		if(index != i)   
        {   
            for(int j = 0; j < n; j++)   
                swap(mat[index][j], mat[i][j]);      
            det = det*pow(-1,index-i);     
		}   
		for(int j = 0; j < n; j++)   
			temp[j] = mat[i][j];   	
		for(int j = i+1; j < n; j++)   
		{   
			num1 = temp[i];   
			num2 = mat[j][i];
			for(int k = 0; k < n; k++)   
				mat[j][k] = (num1 * mat[j][k]) - (num2 * temp[k]);   
			total = total * num1;   
		}   
	}   
    for(int i = 0; i < n; i++)   
        det = det * mat[i][i];   
    return (det/total);
} 
 
 
int32_t main()
{
    int n, m;
 
    cin >> n >> m;
    matrix A = init(n, m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> A[i][j];    
    matrix C = exp(A, 7);
    printtt(C);
 
    return 0;
}
