#include <bits/stdc++.h>
using namespace std;

int n, m;
int M[505][505];

struct SparseTable
{
	int SpT[9][501][9][501];
	bool maxi;

	SparseTable(bool _maxi)
	{
		maxi = _maxi;
		build();
	} 

	void build()
	{
		// caso base
		for(int ir = 0; ir < n; ir++)
		{
			for(int ic = 0; ic < m; ic++)
				SpT[0][ir][0][ic] = M[ir][ic];
			
			for(int jc = 1; (1 << jc) <= m; jc++)
				for(int ic = 0; ic + (1 << jc) <= m; ic++)
					if(maxi)
						SpT[0][ir][jc][ic] = max(SpT[0][ir][jc - 1][ic],
							SpT[0][ir][jc - 1][ic + (1 << (jc - 1))]);
					else
						SpT[0][ir][jc][ic] = min(SpT[0][ir][jc - 1][ic],
							SpT[0][ir][jc - 1][ic + (1 << (jc - 1))]);
		}
		
		// build
		for(int jr = 1; (1 << jr) <= n; jr++)
			for(int ir = 0; ir + (1 << jr) <= n; ir++)
				for(int jc = 0; (1 << jc) <= m; jc++)
					for(int ic = 0; ic + (1 << jc) <= m; ic++)
						if(maxi)
							SpT[jr][ir][jc][ic] = max(
									SpT[jr - 1][ir][jc][ic],
									SpT[jr - 1][ir + (1 << (jr - 1))][jc][ic]
								);	
						else
							SpT[jr][ir][jc][ic] = min(
								SpT[jr - 1][ir][jc][ic],
								SpT[jr - 1][ir + (1 << (jr - 1))][jc][ic]
							);			
		}

	//r1, c1 canto superior esquerdo
	//r2, c2 canto inferior direito
	int query(int r1, int c1, int r2, int c2)
	{
		int jr = (int)log2(r2 - r1 + 1);
		int jc = (int)log2(c2 - c1 + 1);
		int up, down;

		if(maxi)
		{
			up = max(
					SpT[jr][r1][jc][c1], 
					SpT[jr][r1][jc][c2 - (1 << jc) + 1]
				);
			down = max(
					SpT[jr][r2 - (1 << jr) + 1][jc][c1], 
					SpT[jr][r2 - (1 << jr) + 1][jc][c2 - (1 << jc) + 1]
				);
			return max(up, down);
		}
		else
		{
			up = min(
					SpT[jr][r1][jc][c1], 
					SpT[jr][r1][jc][c2 - (1 << jc) + 1]
				);
			down = max(
					SpT[jr][r2 - (1 << jr) + 1][jc][c1], 
					SpT[jr][r2 - (1 << jr) + 1][jc][c2 - (1 << jc) + 1]
				);
			return min(up, down);
		}
	}
};

int32_t main()
{
	cin >> n >> m;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> M[i][j];
	
	SparseTable A(true);
	SparseTable B(false);
	
	int a, b, c, d;
	while(cin >> a >> b >> c >> d)
		cout << A.query(a, b, c, d) << ' ' << B.query(a, b, c, d) << '\n';

	return 0;
}