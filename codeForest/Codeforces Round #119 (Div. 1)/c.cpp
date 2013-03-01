/*
 * Author:  Troy
 * Created Time:  2012/5/11 1:05:11
 * File Name: c.cpp
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
#define Maxn 100100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const int inf = 1<<29;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

vi g[Maxn];
int n, m, k, s, t;
bool vol[Maxn], vis[Maxn];
int dis[Maxn];

bool check(int q)
{
    REP(i, n+1) dis[i] = inf;
    memset(vis, false, sizeof(vis));
    vis[s] = true;
    dis[s] = 0;
    
    queue<int> que;
    que.push(s);
    
    while (!que.empty())
    {
        int now = que.front();
        vis[now] = false;
        que.pop();
        if (dis[now] > q) continue;
        if (now == t) return true;
        if (vol[now]) dis[now] = 0;
        //cout <<now <<" "<<vol[now] <<" "<<dis[now] <<endl;
        
        REP(i, g[now].size())
        {
            int v = g[now][i];
            if (dis[v] > dis[now] + 1)
            {
                dis[v] = dis[now] + 1;
                if (!vis[v])
                {
                    vis[v] = true;
                    que.push(v);
                }
            }
        }
    }
    return false;
}

int main() 
{
    int num, u, v;
    memset(vol, false, sizeof(vol));
    sf("%d%d%d", &n, &m, &k);
    REP(i, k)
    {
        sf("%d", &num);
        vol[num] = true;
    }
    
    REP(i, m)
    {
        sf("%d%d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }
    
    sf("%d%d", &s, &t);
    int lo = 1, hi = n+10, mid;
    while (lo+1<hi)
    {
        mid = (lo + hi) >>1;
        if (check(mid)) hi = mid;
        else lo = mid;
        //cout <<endl;
    }
    
    int ans = -1;
    if (check(lo)) ans = lo;
    else if (check(mid)) ans = mid;
    else ans = hi;
    if (ans == -1 || ans >= n) pf("-1\n");
    else pf("%d\n", ans);
    //cout <<check(3) <<endl;
    return 0;
}

