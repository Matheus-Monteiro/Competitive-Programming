// a ^ kcongb mod m
 
int value[1000008];
int cor[1000008], tempo = 1;
 
// com vetor o modulo deve ser <= 10^7 fica O(sqrt(m))
inline int discreteLogarithm(int a, int b, int m) { 
    tempo++;
	a %= m; b %= m;
    int n = (int)sqrt(m + .0) + 1, an = 1; 
	for(int i = 1; i <= n; i++) an = (an * 1LL * a) % m;
    for(int i = 1, cur = an; i <= n; i++) { 
    	if(cor[cur] < tempo) value[cur] = i, cor[cur] = tempo;
        cur = (cur * 1LL * an) % m; 
    }
    for(int j = 0, cur = b; j <= n; j++) { 
        if(cor[cur] == tempo) { 
            int ans = value[cur] * n - j; 
            if(ans < m)
                return ans;
        } 
		cur = (cur * 1LL * a) % m;
    } 
	return -1;
} 
 
// com mapa o modulo pode ser ateh <= 10^12 fica O(sqrt(m) * log(m))
int discreteLogarithm(int a, int b, int m)
{ 
	a %= m; b %= m;
    int n = (int)sqrt(m + .0) + 1, an = 1; 
	for(int i = 1; i <= n; i++) an = (an * a) % m;
    unordered_map<int, int> value;
    for(int i = 1, cur = an; i <= n; i++) { 
    	if(!value.count(cur)) value[cur] = i;
        cur = (cur * an) % m; 
    }
    for(int j = 0, cur = b; j <= n; j++) { 
        if(value[cur]) { 
            int ans = value[cur] * n - j; 
            if(ans < m) 
                return ans; 
        } 
		cur = (cur * a) % m;
    } 
    return -1; 
} 