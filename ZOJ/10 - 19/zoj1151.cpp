// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   zoj 1151                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
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

/*//Computational Geometry
#include <complex>
#define x real()
#define y imag()
typedef complex<double> point;
*/

void solve()
{
    int n = nextInt(); cin.get();
    while (n--)
    {
        string s, t; getline(cin, s);
        for (int i = 0, sz = s.size(); i < sz; i++)
        {
            if (s[i] == ' ') { cout << t << " "; t = ""; }
            else t = s[i] + t;
        }
        cout << t << endl;
    }
}

int main()
{
    int t = nextInt();
    while (t--)
    {
        solve();
        if (t > 0) cout << endl;
    }
    return 0;
}
// g++ B.cpp -o B.exe -std=c++11