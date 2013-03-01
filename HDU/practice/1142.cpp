#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define Maxn 1024
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define FOR(i, a, b) for(int i(a); i<(b); i++)
#define REP(i, b) FOR(i, 0, b)
using namespace std;
const int inf = 1<<29;
int n, m, dis[Maxn], dp[Maxn];
typedef pair<int, int> pii;
vector<pii> g[Maxn];
bool vis[Maxn];
void spfa()
{
    queue<int> q;
    while (!q.empty()) q.pop();
    q.push(2);
    memset(vis, false, sizeof(vis));
    REP(i, n+1) dis[i] = inf;
    dis[2] = 0; 
    while (!q.empty())
    {
        int now = q.front();
        q.pop();  vis[now] = false;
        for (int i=0; i<g[now].size(); i++)
        {
            int v = g[now][i].fi, len = g[now][i].se;
            if (dis[now] + len < dis[v]) 
            {
                dis[v] = dis[now] + len;
                if (!vis[v])
                {
                    q.push(v);
                    vis[v] = true;                
                }
            }
        }
    }
    return;
}
int dfs(int x)
{
    if (dp[x] != 0) return dp[x];
    if (x == 2) return 1;
    for (int i=0; i<g[x].size(); i++)
    {
        int v = g[x][i].fi;
        if (dis[v] < dis[x]) dp[x] += dfs(v);    
    }
    return dp[x];
}
int main()
{
    int a, b, c;
    while (~scanf("%d", &n), n)
    {
        scanf("%d", &m);
        REP(i, n+5) g[i].clear();
        REP(i, m)
        {
            scanf("%d%d%d", &a, &b, &c);
            g[a].pb(mp(b, c));
            g[b].pb(mp(a, c));
        }
        spfa();
        memset(dp, 0, sizeof(dp));
        int ans = dfs(1);
        printf("%d\n", ans);
    }
    return 0;
}
