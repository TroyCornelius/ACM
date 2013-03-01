/*
 * Author:  Troy
 * Created Time:  2012/7/28 19:49:00
 * File Name: g.cpp
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

int n, m, ans;
vi g[250];
bool vis[240];
bool dfs(int u, int t)
{
    vis[u] = true;
    if (u == t) return true;
    REP(i, g[u].size())
    {
        int v = g[u][i];
        if (!vis[v])
        {
            if (dfs(v, t)) return true;
        }
    }
    return false;
}
int main() 
{
    int x, y, ca = 0;
    while (~sf("%d%d", &n, &m), n+m)
    {
        REP(i, n+1) g[i].clear();
        ans = 0;
        while (m--)
        {
            sf("%d%d", &x, &y);
            if (x == y) ans++;
            else
            {
                memset(vis, false, sizeof(vis));
                if (dfs(y, x)) ans++;
                else g[x].pb(y);
            }
        }
        pf("%d. %d\n", ++ca, ans);
    }
    return 0;
}

