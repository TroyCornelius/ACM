#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i(a); i<(b); i++)
#define REP(i, b) FOR(i,0,b)
#define ll long long
#define maxn 100050
#define maxm 1000000
using namespace std;
const int inf = 1 << 30;
int n, m, s, l;
struct Edge {
    int u, v, cost, next;
}et[maxm];
int eh[maxn], tot, dist[maxn], cnt[maxn];
bool vis[maxn];
int ans = 0;

void init() 
{
    tot = 0;
    memset(eh, -1, sizeof (eh));
}

void addedge(int u, int v, int cost) 
{
    Edge e = {u, v, cost, eh[u]};
    et[tot] = e;
    eh[u] = tot++;
}

bool spfa(int s) 
{
    REP(i, n+1) vis[i] = false, dist[i] = inf, cnt[i] = 0;
    dist[s] = 0, vis[s] = true, cnt[s]++;
    queue<int> que;
    que.push(s);
    while (!que.empty())
    {
        int u = que.front();
        que.pop(), vis[u] = false;
        for (int i = eh[u]; i != -1; i = et[i].next) 
        {
          int v = et[i].v, cost = et[i].cost;
            if (dist[v] > cost + dist[u]) 
            {
                dist[v] = cost + dist[u];
                if (!vis[v]) 
                {
                    vis[v] = true;
                    que.push(v);
                    cnt[v]++;
                    if (cnt[v] >= n) return false; 
                }
            }
        }
    }
    return true;
}

int main() 
{
    ios::sync_with_stdio(false);
    int u, v, cost;
    //while(1) {
        cin >> n >> m >> s;
        init();
        for(int i = 0; i < m; i++) 
        {
            cin >> u >> v >> cost;
            addedge(u, v, cost);
            addedge(v, u, cost);
        }
        cin >> l;
        ans = 0;
        spfa(s);
        for(int i = 1; i <= n; i++) 
        {
            if(dist[i] == l) 
            {
                ans++;
            }
        }
        for(int i = 0; i < tot; i += 2) 
        {
            u = et[i].u, v = et[i].v, cost = et[i].cost;
            int minn = min(dist[u], dist[v]), maxx = max(dist[u], dist[v]);
            if(l <= minn) continue;
            int t1 = 0, t2 = 0;
            if(l > minn && cost + minn > l && cost + minn - l + maxx >= l) ans++, t1 = 1;
            if(l > maxx && cost + maxx > l && cost + maxx - l + minn >= l) ans++, t2 = 2;
            if(t1 && t2) 
            {
                if(2 * l - minn - maxx == cost) ans--;
            }
        }
        cout << ans << endl;
    //} 
    return 0;
}
