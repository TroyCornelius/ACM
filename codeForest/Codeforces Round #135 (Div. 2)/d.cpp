/*
 * Author:  Troy
 * Created Time:  2012/8/27 23:51:03
 * File Name: d.cpp
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
#define Maxn 200100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const int inf = 1<<29;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
vector<pii> g[Maxn];
int n;
int dp[Maxn], rec[Maxn];
int dep[Maxn], res[Maxn];
vector<int> out;
void dfs(int u, int fa, int w, int d)
{
    rec[u] = rec[fa] + w;
    dep[u] = d, dp[u] = 0;
    for(int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i].fi, id = g[u][i].se;
        if(v == fa) continue;
        dfs(v, u, id, d + 1);
        dp[u] += dp[v] + id;
    }
}
int main() 
{
    ios::sync_with_stdio(false);
    cin >>n;
    for(int i = 1; i <= n; i++) g[i].clear();
    int a, b;
    for(int i = 1; i < n; i++) 
    {
        cin >> a >> b;
        g[a].pb(mp(b, 0));
        g[b].pb(mp(a, 1));
    }
    dfs(1, 0, 0, 0);
    int ans = inf;
    for(int i = 1; i <= n; i++) 
    {
        res[i] = dp[1] + (dep[i] - rec[i]) - rec[i];
        ans = min(ans, res[i]);
    }
    for(int i = 1; i <= n; i++) 
    {
        if(res[i] == ans) out.pb(i);
    }
    cout << ans << endl;
    for(int i = 0; i < out.size(); i++)
        if(i == out.size() - 1) cout << out[i] << endl;
        else cout << out[i] << " ";
    return 0;
}
