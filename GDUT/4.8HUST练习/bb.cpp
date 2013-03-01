/*
 * Author:  Troy
 * Created Time:  2012/4/10 15:55:49
 * File Name: bb.cpp
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
const int maxint = 1<<29;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int g[15][15];
int n, m, ans;
int dp[1<<11][12][3];
void init()
{
    int u, v, w;
    //REP(i, n+1)
        //REP(j, n+1) g[i][j] = maxint;
    REP(i, m)
    {
        sf("%d%d%d", &u, &v, &w);
        u--; v--;
        g[u][v] = g[v][u] = min(g[v][u], w);
    }
    memset(dp, -1, sizeof(dp));
   /* REP(i, 1<<n)
        REP(j, n)
            REP(k, 3)
                dp[i][j][k] = maxint;
    REP(i, n) dp[0][i][0] = 0;*/
}
int dfs(int st, int now, int ti)
{
    int &ret = dp[st][now][ti];
    if (ret != -1) return ret;
    if (st == 0)
    {
        ret = (ti == 0) ? 0 : maxint;
        return ret;
    }
    if (((1<<now)&st) && (ti == 0))
    {
        ret = maxint;
        return ret;
    }
    ret = maxint;
    REP(i, n)
        if ((1<<i)&st)
        {
            int nxt = st ^ (1<<now);
            if (ti == 2) ret = min(ret, min(dfs(st, i, 1), min(dfs(st, i, 2), dfs(st, i, 0))) + g[i][now]);
            else
            if (ti == 1) ret = min(ret, min(dfs(nxt, i, 1), min(dfs(nxt, i, 2), dfs(nxt, i, 0))) + g[i][now]);
        }
    //cerr <<st <<" "<<now <<" "<<ti <<" "<<ret <<endl;
    return ret;
}
int main() 
{
    
    while (~sf("%d%d", &n, &m))
    {
        init();
        ans = maxint;
        int tar = (1 << n) - 1;
        REP(i, n)
        {
            ans = min(ans, dfs(tar, i, 1));
            ans = min(ans, dfs(tar, i, 2));
        }
        cerr <<ans <<endl;
        pf("%d\n", ans >= maxint?-1:ans);
    }    
    return 0;
}

