#define ll long long
#define Pll complex<ll>
#define Y imag()
#define X real()

bool intersec(Pll a, Pll b, Pll c, Pll d)
{
	if(cross(c - a, c - b) * cross(d - a, d - b) <= 0  and 
		cross(a - c, a - d) * cross(b - c, b - d) <= 0)
		return true;
	return false;
}
