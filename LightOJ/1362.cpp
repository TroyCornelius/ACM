/*
 * Author:  Troy
 * Created Time:  2013/3/1 20:42:18
 * File Name: 1362.cpp
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
#define ll long long
#define sf scanf
#define pf printf
using namespace std;
const int inf = 1<<30;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int n = 8;
int pl, pw, tot;
char g[n+5][n+5];
int cost[n+5][n+5], dp[(1<<n)+10][n][n];
pii tar, h[(1<<n) + 10];
bool vis[n][n];
void spfa(int dp[n][n]) {
    queue<pii> que;
    memset(vis, false, sizeof(vis));
    REP(i, n) 
        REP(j, n) {
            if (dp[i][j] != inf) {
                que.push(mp(i, j));
                vis[i][j] = true;
            }
        }
    while (!que.empty()) {
        pii now = que.front();
        vis[now.fi][now.se] = false;
        que.pop();
        REP(i, 4) {
            int tx = now.fi + dx[i], ty = now.se + dy[i];
            if (tx >= 0 && tx < n && ty >= 0 && ty < n) {
                int nv = dp[now.fi][now.se] + cost[tx][ty] + 1;
                if (nv < dp[tx][ty]) {
                    dp[tx][ty] = nv;
                    if (!vis[tx][ty]) {
                        que.push(mp(tx,ty));
                        vis[tx][ty] = true;
                    }
                }
            }
        }
    }
}
inline int calc_one(int x) {
    int ret = 0;
    while (x) {
        if (x & 1) ret++;
        x >>= 1;
    }
    return ret;
}
int solve() {
    FOR(st, 1, 1<<tot) {
        REP(i, n)
            REP(j, n) {
                dp[st][i][j] = inf;
                for (int k = (st - 1) & st; k; k = (k - 1) & st)
                    dp[st][i][j] = min(dp[st][i][j], dp[k][i][j] + dp[st^k][i][j] - cost[i][j]);
            }
        if (calc_one(st) == 1) {
            int lb = (st & -st);
            dp[st][h[lb].fi][h[lb].se] = 0;
        }
        spfa(dp[st]);
    }
    return dp[(1<<tot)-1][tar.fi][tar.se];
}
int main() {
    int T, ca = 0;
    //cout <<(1<<n+10) <<endl;
    sf("%d", &T);
    while (T--) {
        sf("%d%d", &pl, &pw);
        tot = 0;
        memset(cost, 0, sizeof(cost));
        REP(i, n) {
            sf("%s", g[i]);
            REP(j, n) {
                if (g[i][j] == 'H') {h[1<<tot] = mp(i, j); tot++;}
                if (g[i][j] == 'G') tar = mp(i, j);
                if (g[i][j] == 'W') cost[i][j] = pw; 
                if (g[i][j] == '.') cost[i][j] = pl;
            }
        }
        pf("Case %d: %d\n", ++ca, solve());
    }
    return 0;
}

/*
5
1 2
.H......
HGH.....
.H......
........
........
........
........
........
 */ 
