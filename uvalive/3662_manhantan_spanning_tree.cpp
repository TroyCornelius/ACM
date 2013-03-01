/*
 * Author:  Troy
 * Created Time:  2012/10/8 11:37:48
 * File Name: 3241_Æ½ÃæÍ¼MST.cpp
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
#define Maxn 110010
using namespace std;
const int inf = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
int lim = 1000000008;
int n, k;
struct Point {
    int x, y, idx;
    bool operator<(const Point &b) const {
        return x < b.x || (x == b.x && y < b.y);
    }
}d[Maxn];
int num[Maxn], id[Maxn], fa[Maxn];
void Discarate() {
    FOR(i, 1, n+1) num[i] = d[i].y - d[i].x;
    sort(num, num+n);
    int nn = unique(num, num+n) - num;
    FOR(i, 1, n+1) id[i] = lower_bound(num, num+nn, d[i].y-d[i].x) - num + 1;
}
int find_fa(int x) {
    return fa[x] == x ? x : (fa[x] = find_fa(fa[x]));
}
struct Edge {
    int u, v, w;
    Edge() {}
    Edge(int _u, int _v, int _w)
    :u(_u), v(_v), w(_w) {}
    bool operator<(const Edge &tmp) const {
        return w < tmp.w;
    }
}e[1000010];
int tot_edge;
void addedge(int u, int v, int w) {
    e[tot_edge++] = Edge(u, v, w);
}
inline int get_dis(int i, int j) {
    return abs(d[i].x-d[j].x) + abs(d[i].y-d[j].y);
}
int t[Maxn], p[Maxn];
void add(int idx, int val, int pos) {
    for (;idx; idx-=idx&-idx)
        if (t[idx] > val) t[idx] = val, p[idx] = pos;
}
int query(int idx) {
    int ret = inf, pos = n+1;
    for (; idx <= n; idx += idx&-idx)
        if (t[idx] < ret) ret = t[idx], pos = p[idx];
    return pos;
}
void solve() {
    sort(d+1, d+n+1);
    Discarate();
    for (int i = 1; i <= n; i++) fa[i] = i;
    int pos;
    REP(i, n+10) t[i] = inf;
    for (int i = n; i >= 1; i--) {
        pos = query(id[i]);
        if (pos != n+1) addedge(d[i].idx, d[pos].idx, get_dis(i, pos));
        add(id[i], d[i].y+d[i].x, i);
    }
}
int ca = 0;
void Kruskal() {
    long long ans = 0;
   int cnt = n - 1;
    sort(e, e+tot_edge);
    for (int i = 0; i < tot_edge && cnt; i++) {
        int x = find_fa(e[i].u), y = find_fa(e[i].v);
        if (x != y) {
            fa[x] = y;
            cnt--;
            ans += e[i].w;
        }
    }
    pf("Case %d: Total Weight = %lld\n", ++ca, ans);
}
void work() {
    FOR(i, 1, n+1) d[i].idx = i;
    tot_edge = 0;
    REP(i, 4) {
        if (i == 2) {
            FOR(j, 1, n+1) d[j].x = lim - d[j].x;
        }
        if (i == 1 || i == 3) {
            FOR(j, 1, n+1) swap(d[j].x, d[j].y);
        }
        solve();
    }
    Kruskal();
}
int main() {
    while (~sf("%d", &n), n) {
        FOR(i, 1, n+1) sf("%d%d", &d[i].x, &d[i].y);
        work();
    }
    return 0;
}

