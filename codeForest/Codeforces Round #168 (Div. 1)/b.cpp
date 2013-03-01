/*
 * Author:  Troy
 * Created Time:  2013/2/20 23:46:47
 * File Maxn: d.cpp
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
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
const int inf = 1 << 29;
const double dinf = 1e30;
const ll linf = 1LL << 56;

const int Maxn = 111000;
vector<int> g[Maxn];
ll dp[Maxn][2];
ll ans, w[Maxn];
int n;
ll rec[Maxn];

void dfs(int u, int fa) {
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa) continue;
        dfs(v, u);
        dp[u][0] = max(dp[u][0], dp[v][0]);
        dp[u][1] = max(dp[u][1], dp[v][1]);
    }
    w[u] += dp[u][0];
    w[u] -= dp[u][1];
    if (w[u] > 0) dp[u][1] += w[u];
    else dp[u][0] -= w[u];
}

int main() {
    cin >>n;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    memset(dp, 0, sizeof(dp));
    ans = 0;
    dfs(1, 0);
    cout << dp[1][0] + dp[1][1] << endl;
    return 0;
}

