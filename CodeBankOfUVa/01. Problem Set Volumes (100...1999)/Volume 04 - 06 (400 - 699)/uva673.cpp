// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   uva 673                                                  *
*****************************************************************************/
// 人一我百，人十我万！追逐青春的梦想，怀着自信的心，永不放弃！
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

const bool WIN  = true;
const bool LOSE = false;
const char aye[] = "Yes";
const char nay[] = "No";
const char ace[] = "Alice";
const char bob[] = "Bob";

char buf[205];
char s[205];

void solve()
{
    int i;
    memset(s, 0, sizeof(s));
    gets(buf);
    int t =0;
    int len = strlen(buf);
    for (i = 0; i < len; i++)
    {
        char ch = buf[i];
        if (ch == '(' || ch == '[') s[t++] = ch;
        else if (ch == ')')
        {
            if (s[t - 1] == '(') s[--t] = '\0';
            else s[t++] = ch;
        }
        else if (ch == ']')
        {
            if (s[t - 1] == '[') s[--t] = '\0';
            else s[t++] = ch;
        }
    }
    if (s[0] == '\0') puts(aye);
    else puts(nay);
}

int main()
{
    int t = nextInt(); scanf(" ");
    while (t--) solve();
    return 0;
}
