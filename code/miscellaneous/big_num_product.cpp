string mul(string a, string b)
{
	while(a.size() > b.size()) b = "0" + b;
	while(a.size() < b.size()) a = "0" + a;
	a = "00" + a;
	b = "00" + b;
	int ans = 0, n = a.size(), carry = 0;
	vector<int> num(2 * n, 0);	
	for(int i = n - 1; i >= 0; i--)
		for(int j = n - 1; j >= 0; j--)
		{
			int di = a[i] - '0';
			int dj = b[j] - '0';
			num[i + j + 1] += (di * dj) + carry;
			carry = (num[i + j + 1] / 10);
			num[i + j + 1] %= 10;
		}
	string r;
	for(int i = 0, fl = 0; i < 2 * n; i++)
	{
		if(num[i]) fl = 1;
		if(fl) r.push_back(num[i] + '0');
	}
	return r;

