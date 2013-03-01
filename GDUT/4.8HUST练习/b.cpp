/*
 * Author:  Troy
 * Created Time:  2012/4/10 14:07:28
 * File Name: b.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <time.h>
#include <cctype>
#include <functional>
#include <deque>
#include <iomanip>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <sstream>
#include <utility>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const long long inf = 1LL << 58;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m;
vi a;
long long g[15][15], ans;
inline long long MIN(long long a, long long b)
{
    return a < b ? a : b;
}
int main() 
{
    int u, v;
    long long w;
    while (~sf("%d%d", &n, &m))
    {
        REP(i, n+1)
            REP(j, n+1) g[i][j] = inf;
        a.clear();
        FOR(i,1,n+1) a.pb(i);
        REP(i, m)
        {
            sf("%d%d%I64d", &u, &v, &w);
            if (w < g[u][v]) g[u][v] = g[v][u] = w;
        }
        ans = -1;
        long long cnt;
        sort(all(a));
        do
        {
            cnt = 0;
            REP(i, n-1)
            {
                if (g[a[i]][a[i+1]] == inf) {cnt = -1; break;}
                else cnt += g[a[i]][a[i+1]];
            }
            if (cnt != -1)
            {
                if (ans == -1) ans = cnt;
                else ans = MIN(ans, cnt);
            }
        }while (next_permutation(all(a)));
        pf("%I64d\n", ans);
    }
    return 0;
}

