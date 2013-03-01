/*
 * Author:  Troy
 * Created Time:  2012/7/22 16:49:01
 * File Name: 4036_树DP.cpp
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
#define Maxn 300100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

vector<pii> g[Maxn];
long long val[Maxn];
int n;
long long ans, cnt[Maxn], sum[Maxn];

void dfs(int u, int fa, int col)
{
    int last_col = -1;
    long long tot = 0, st = 0;
    long long ts = 0, tt = 0;
    cnt[u] = 1; sum[u] = val[u];
    
    REP(i, g[u].size())
    {
        int v = g[u][i].se, ncol = g[u][i].fi;
        if (v == fa) continue;
        dfs(v, u, ncol);
        if (ncol != last_col) tot = tt, st = ts;
        last_col = ncol;
        
        ans += st * cnt[v]; //两边通过点u交叉相连
        ans += tot * sum[v];
        ans += cnt[v] * tot * val[u];
        ts += sum[v];
        tt += cnt[v];
        
        if (col != ncol)
        {
            cnt[u] += cnt[v];
            sum[u] += sum[v] + cnt[v] * val[u]; 
        }
    }
    if (u != 1) ans += cnt[u] * val[fa] + sum[u];//与父边相连
}
int main() 
{
    int a, b, c;
    while (~sf("%d", &n))
    {
        FOR(i, 1, n+1) sf("%I64d", &val[i]);
        REP(i, n+1) g[i].clear();
        REP(i, n-1)
        {
            sf("%d%d%d", &a, &b, &c);
            g[a].pb(mp(c, b));
            g[b].pb(mp(c, a));
        }
        FOR(i, 1, n+1) sort(all(g[i]));
        ans = 0;
        dfs(1, -1, -1);
        //cout <<ans <<endl;
        pf("%I64d\n", ans);
    }
    return 0;
}

