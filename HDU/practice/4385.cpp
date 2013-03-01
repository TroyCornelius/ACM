/*
 * Author:  Troy
 * Created Time:  2012/8/22 23:58:17
 * File Name: 4385.cpp
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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n;
pii p[20];
int dp[(1<<19)+10];
int dis[21][21];
pii rec[(1<<19)+10];

int dfs(int st) {
    if (st == 0) return dp[st] = 0;
    if (dp[st] != -1) return dp[st];
    int &ret = dp[st];
    ret = maxint;
    pii t;
    REP(i, n) {
        if ((st&(1<<i))) {
            int tmp = dfs(st^(1<<i)) + dis[i][n] + dis[i][n];
            if (tmp < ret) {
                ret = tmp;
                t = mp(i, i);
            }
            
            FOR(j, i+1, n) {
                if ((st&(1<<j))) {
                    int tmp = dfs((st^(1<<i))^(1<<j)) + dis[i][n] + dis[i][j] + dis[j][n];
                    if (tmp < ret) {
                        ret = tmp;
                        t = mp(i, j);
                    }
                }
            }
        }
    }
    rec[st] = t;
    return ret;
}
int out[20], tot;
vector<pii> path;
void get_path(int st) {
    if (st == 0) return;
    path.pb(rec[st]);
    int x = rec[st].fi, y = rec[st].se;
    if (x == y) get_path(st^(1<<x));
    else get_path((st^(1<<x))^(1<<y));
}
int main() {
    int T, ca = 0;
    int x, y;
    sf("%d", &T);
    while (T--) {
        sf("%d%d", &x, &y);
        sf("%d", &n);
        p[n] = mp(x, y);
        REP(i, n) sf("%d%d", &p[i].fi, &p[i].se);
        REP(i, n+1)
            FOR(j, i+1, n+1)
                dis[i][j] = dis[j][i] = (p[i].fi-p[j].fi)*(p[i].fi-p[j].fi) + (p[i].se-p[j].se)*(p[i].se-p[j].se);
        
        int all = (1<<n) - 1;
        memset(dp, -1, sizeof(dp));
        int ans = dfs(all);
        pf("Case %d:\n", ++ca);
        pf("%d\n", ans);
        tot = 0;
        path.clear();
        get_path(all);
        sort(all(path));
        REP(i, path.size())
            if (path[i].fi == path[i].se) out[tot++] = path[i].fi;
            else {
                out[tot++] = path[i].fi;
                out[tot++] = path[i].se;
            }
        REP(i, tot) pf("%d%c", out[i]+1, i == tot-1 ? '\n':' ');
    }
    return 0;
}

