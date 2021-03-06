// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   poj 1811                                                 *
*****************************************************************************/

#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }
inline int    nextInt() { int x; scanf("%d", &x); return x; }
inline int64  nextI64() { int64  d; cin >> d; return d; }
inline char   nextChr() { scanf(" "); return getchar(); }
inline double nextDbf() { double x; scanf("%lf", &x); return x; }
inline int64  next64d() { int64 d; scanf("%I64d",&d); return d; }

const int64 MaxN = 105;
int64 gcd(int64 a, int64 b)
{
    if (a == 0) return 1;
    if (a < 0) return gcd(-a, b);
    while (b)
    {
        int64 t = a; a = b; b = t % b;
    }
    return a;

}

int64 mul_mod(int64 a, int64 b, int64 m)
{
	int64 t = 0; a %= m; b %= m;
	while (b)
	{
		if (b & 1) t += a, t = (t >= m)? t - m: t;
		a <<= 1; a = (a >= m)? a - m: a; b >>= 1;
	}
	return t;
}

int64 pow_mod(int64 a, int64 b, int64 m)
{
	int64 ans = 1; a %= m;
	while (b)
	{
		if (b & 1) ans = mul_mod(ans, a, m);
		b >>= 1; a = mul_mod(a, a, m);
	}
	return ans;
}

bool test(int64 a, int64 n, int64 x, int64 t)
{
    int64 ret = pow_mod(a, x, n);
    int64 last = ret;
    for (int i = 1; i <= t; i++)
    {
        ret = mul_mod(ret, ret, n);
        if (ret == 1 && last != 1 && last != n - 1)
            return true;
        last = ret;
    }
    if (ret != 1) return true;
    else return false;
}

bool isPrime(int64 n)
{
    int64 x = n - 1, t = 0;
    while ((x & 1) == 0) { x >>= 1; t++; }
    bool flag = 1;
    if (t >= 1 && (x & 1) == 1)
    {
        for (int k = 0; k < 25; k++)
        {
            int64 a = rand() % (n - 1) + 1;
            if (test(a, n, x, t)) { flag = 1; break; }
            flag = 0;
        }
    }
    if (!flag || n == 2) return 1;
    return 0;
}

int64 Pollard_rho(int64 x, int64 c)
{
    int64 i = 1, k = 2;
    int64 x0 = rand() % (x - 1) + 1;
    int64 y = x0;
    while (true)
    {
        i++;
        x0 = (mul_mod(x0, x0, x) + c) % x;
        int64 d = gcd(y - x0, x);
        if (d != 1 && d != x) return d;
        if (y == x0) return x;
        if (i == k) { y = x0; k += k; }
    }
}

int64 tot, result[MaxN];
void findfac(int64 n)
{
    if (n == 1) return;
    if (isPrime(n)) { result[tot++] = n; return; }
    int64 p = n;
    while (p >= n) p = Pollard_rho(p, rand() % (n - 1) + 1);
    findfac(p); findfac(n / p);
}

int t; int64 n;

void solve()
{
    n = next64d();
    if (isPrime(n)) puts("Prime");
    else
    {
        tot = 0; findfac(n);
        int64 ans = result[0];
        for (int i = 0; i < tot; i++)
            updateMin(ans, result[i]);
        printf("%I64d\n", ans);
    }
}

int main()
{
    srand(time(0));
    t = nextInt(); while (t--) solve();
    return 0;
}
