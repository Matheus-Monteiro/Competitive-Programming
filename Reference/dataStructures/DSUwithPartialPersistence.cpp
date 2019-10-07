int n, pai[MAX], sz[MAX], his[MAX], tempo;

void init()
{
	tempo = 0;
	for(int i = 0; i < n; i++)
		pai[i] = i, sz[i] = 1, his[i] = 0;
}
 
int find(int x, int t)
{
	if(pai[x] == x) return x;
	if(his[x] > t) return x;
	return find(pai[x], t);
}
 
void join(int u, int v)
{
	tempo++;
	u = find(u, tempo);
	v = find(v, tempo);
	if(sz[u] > sz[v]) swap(u, v);
	pai[u] = v;
	his[u] = tempo;
	sz[v] += sz[u];
}
