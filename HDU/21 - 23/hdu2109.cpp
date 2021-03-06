// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   hdu 2109                                                 *
*****************************************************************************/

//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

//#include <bits/stdc++.h>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <string>
#include <limits>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }
inline int    nextInt() { int x; scanf("%d", &x); return x; }
inline int64  nextI64() { int64  d; cin >> d; return d; }
inline char   nextChr() { scanf(" "); return getchar(); }
inline string nextStr() { string s; cin >> s; return s; }
inline double nextDbf() { double x; scanf("%lf", &x); return x; }
inline int64  nextlld() { int64 d; scanf("%lld", &d); return d; }
inline int64  next64d() { int64 d; scanf("%I64d",&d); return d; }

const int MaxN = 128;
int n, a[MaxN], b[MaxN];

void solve()
{
	for (int i = 0; i < n; i++) a[i] = nextInt();
	for (int i = 0; i < n; i++) b[i] = nextInt();
	sort(a, a + n); sort(b, b + n);
	int as = 0, bs = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < b[i]) bs += 2;
		else if (a[i] > b[i]) as += 2;
		else { as++; bs++; }
	}
	printf("%d vs %d\n", as, bs);
}

int main()
{
	while (cin >> n && n) solve();
	return 0;
}