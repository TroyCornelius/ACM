/*
 * Author:  Troy
 * Created Time:  2012/2/25 19:19:04
 * File Name: 
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
#define Maxn 100100
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, ans, sum;
int c[Maxn], len[Maxn];
vector<pii> g[Maxn];
void dfs(int x, int fa)
{
    REP(i, g[x].size())
    {
        int v = g[x][i].fi, cost = g[x][i].se;
        if (v == fa) continue;
        len[v] = len[x] + cost;
        dfs(v, x);
    }
}
int main() 
{
    int u, v, cost;
    while (~scanf("%d", &n))
    {
        REP(i, n+1) scanf("%d", &c[i]);
        REP(i, n+1) g[i].clear();
        sum = 0;
        REP(i, n)
        {
            scanf("%d%d%d", &u, &v, &cost);
            g[u].pb(mp(v, cost));
            g[v].pb(mp(u, cost));
            sum += cost * 2;
        }
        len[0] = 0;
        dfs(0, -1);
        ans = maxint;
        REP(i, n+1)
        {
            if (sum - len[i] + c[i] < ans) ans = sum - len[i] + c[i]; 
        }
        printf("%d\n", ans);
    }
    return 0;
}

