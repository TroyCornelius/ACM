/*
 * Author:  Troy
 * Created Time:  2012/11/11 23:26:09
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
#define ll long long
#define sf scanf
#define pf printf
#define Maxn 100100
using namespace std;
const int inf = 1<<29;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

const int dx[] = {1,1,-1,-1,0,0,1,-1};
const int dy[] = {1,-1,1,-1,1,-1,0,0};
int n;
struct Lines{
    int r, a, b;
    bool operator<(const Lines &p) const {
        return r < p.r || (r == p.r && a < p.a);
    }
}d[Maxn];
vi g[Maxn];
pii st, en;
map<pii, int> pid;
int tot;
const int lim = 1000000000;
void build_graph() {
    int i = 0;
    tot = 0;
    while (i < n) {
        int j = i+1;
        int x = d[i].a, y = d[i].b;
        for (; j < n && d[j].r == d[i].r && d[j].a <= y; j++) {
            y = max(y, d[j].b);
        }
        for (int p = x; p <= y; p++) {
            pid[mp(d[i].r, p)] = ++tot;
        }
        i = j;
    }
    for (map<pii, int>::iterator it = pid.begin(); it != pid.end(); it++) {
        pii t = it->fi;
        int id = it->se;
        REP(i, 8) {
            int tx = t.fi + dx[i], ty = t.se + dy[i];
            if (tx > 0 && tx < lim && ty > 0 && ty < lim && pid.find(mp(tx, ty)) != pid.end()) {
                g[id].pb(pid[mp(tx, ty)]);
                //cout <<t.fi <<" "<<t.se <<" --- " <<tx <<" "<<ty << " : " <<id <<" "<<pid[mp(tx, ty)] <<endl;
            }
        }
    }
}
int dist[Maxn];
int bfs() {
    int beg = pid[st], tar = pid[en];
    REP(i, 100010)
        dist[i] = inf;
    dist[beg] = 0;
    queue<int> que;
    que.push(beg);
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        //cout <<now <<" "<<dist[now] <<endl;
        REP(i, g[now].size()) {
            int v = g[now][i];
            if (dist[now] + 1 < dist[v]) {
                dist[v] = dist[now] + 1;
                if (v == tar) return dist[v];
                que.push(v);
            }
        }
    }
    return -1;
}
int main() {
    sf("%d%d%d%d", &st.fi, &st.se, &en.fi, &en.se);
    int r, a, b;
    sf("%d", &n);
    REP(i, n) {
        sf("%d%d%d", &d[i].r, &d[i].a, &d[i].b);
    }
    sort(d, d+n);
    build_graph();
    int ans = bfs();
    pf("%d\n", ans);
    
    return 0;
}

