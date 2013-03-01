/*
 * Author:  Troy
 * Created Time:  2012/10/2 0:17:15
 * File Name: b.cpp
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
#define Maxn 100010
using namespace std;
const int inf = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m;
vector<pii> g[Maxn];
vi arrive_time[Maxn];
int dist[Maxn];
bool hash[Maxn];

int spfa(int st, int en) {
    memset(hash, false, sizeof(hash));
    FOR(i, 1, n+1) dist[i] = inf;
    dist[st] = 0;
    queue<int> que;
    que.push(st);
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        hash[now] = false;
        
        REP(i, g[now].size()) {
            int v = g[now][i].fi, w = g[now][i].se;
            vit it = lower_bound(all(arrive_time[now]), dist[now]);
            if (it == arrive_time[now].end() || *it > dist[now]) {
                if (dist[now] + w < dist[v]) {
                    dist[v] = dist[now] + w;
                    if (!hash[v]) {
                        hash[v] = true;
                        que.push(v);
                    }
                }
            }
            else {
                int cnt = 0;
                for (int num = dist[now]; it < arrive_time[now].end() && *it == num && dist[now]+w+cnt < dist[v]; it++, num++, cnt++);
                if (dist[now] + w + cnt < dist[v]) {
                    dist[v] = dist[now] + w + cnt;
                    if (!hash[v]) {
                        hash[v] = true;
                        que.push(v);
                    }
                }
            }
        }
    }
    return dist[en] == inf ? -1 : dist[en];
}
int main() {
    int u, v, w;
    sf("%d%d", &n, &m);
    REP(i, m) {
        sf("%d%d%d", &u, &v, &w);
        g[u].pb(mp(v, w));
        g[v].pb(mp(u, w));
    }
    int k, ti;
    FOR(i, 1, n+1) {
        sf("%d", &k);
        while (k--) {
            sf("%d", &ti);
            arrive_time[i].pb(ti);
        }
    }
    int ans = spfa(1, n);
    pf("%d\n", ans);
    return 0;
}

