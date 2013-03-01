#ifdef NALP_PROJECT
#pragma hdrstop
#else
#define _SECURE_SCL 0
#endif
 
#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:64000000")
 
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <utility>
 
#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <memory.h>
 
#include <iostream>
#include <sstream>
 
using namespace std;
 
typedef long long int64;
 
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define y1 YYYYYYYYYYYY1
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define Abs(x) (((x) >= 0) ? (x) : (-(x)))
 
const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;
 
const int MAXN = 100100;
const int LOG = 17;
 
int gcd(int a, int b) {
	if (min(a, b) == 0) return a + b;
	return gcd(b % a, a);
}
 
int n, m, x[MAXN], y[MAXN], next[MAXN][LOG], value[MAXN];
int T = 0, tin[MAXN], tout[MAXN], d[MAXN], hls = 0;
vector<int> g[MAXN], hl[MAXN], tree[MAXN], a[MAXN], upd[MAXN];
vector<pair<int, int> > b[MAXN];
 
int DFS(int v, int prev) {
	int &ans = d[v];
 
	next[v][0] = prev;
	for(int i = 1; i < LOG; i++)
		next[v][i] = next[next[v][i - 1]][i - 1];
 
	ans = 1;
	tin[v] = ++T;
	forn(i, g[v].size()) {
		int u = g[v][i];
		if (u != prev) ans += DFS(u, v);
	}
 
	tout[v] = ++T;
	return ans;
}
 
void build(int v, int prev, int id) {
	x[v] = id;
	y[v] = (int)hl[id].size();
	hl[id].pb(v);
	forn(i, g[v].size()) {
		int u = g[v][i];
		if (u != prev)
			if (d[u]*2 >= d[v])
				build(u, v, id);
			else {
				hls++;
				build(u, v, hls - 1);
			}
	}
}
 
bool isPrev(int v, int u) {
	return tin[v] <= tin[u] && tout[u] <= tout[v];
}
 
int getLCA(int v, int u) {
	if (isPrev(v, u)) return v;
	if (isPrev(u, v)) return u;
 
	ford(i, LOG)
		if (!isPrev(next[v][i], u))
			v = next[v][i];
 
	return next[v][0];
}
 
int get(int id, int l, int r) {
	int s = (int)sqrt(0.0 + a[id].size());
	int ans = 0, vl = l / s, vr = r / s;
	if (vl == vr) {
		for(int i = l; i <= r; i++)
			ans = gcd(ans, a[id][i] + upd[id][vl]);
	} else {
		for(int i = l; i < (vl + 1)*s; i++)
			ans = gcd(ans, a[id][i] + upd[id][vl]);
 
		for(int i = vl + 1; i <= vr - 1; i++)
			ans = gcd(ans, gcd(b[id][i].first + upd[id][i], b[id][i].second));
 
		for(int i = vr*s; i <= r; i++)
			ans = gcd(ans, a[id][i] + upd[id][vr]);
	}
 
	return ans;
}
 
void recalc(int id, int v) {
	int s = (int)sqrt(0.0 + a[id].size());
	int l = v*s, r = min((int)a[id].size(), (v + 1)*s) - 1;
	b[id][v].first = a[id][l] + upd[id][v];
	b[id][v].second = 0;
	for(int i = l; i <= r; i++) {
		a[id][i] += upd[id][v];
		b[id][v].second = gcd(b[id][v].second, abs(a[id][i] - a[id][l]));
	}
 
	upd[id][v] = 0;
}
 
void updateDecomposition(int id, int l, int r, int value) {
	if (l > r) return;
	int s = (int)sqrt(0.0 + a[id].size());
	int vl = l / s, vr = r / s;
	if (vl == vr) {
		for(int i = l; i <= r; i++)
			a[id][i] += value;
	} else {
		for(int i = l; i < (vl + 1)*s; i++)
			a[id][i] += value;
 
		for(int i = vl + 1; i <= vr - 1; i++)
			upd[id][i] += value;
 
		for(int i = vr*s; i <= r; i++)
			a[id][i] += value;
	}
 
	recalc(id, vl);
	recalc(id, vr);
}
 
int getGCD(int v, int u) {
	int ans = 0;
	while (x[v] != x[u]) {
		ans = gcd(get(x[u], 0, y[u]), ans);
		u = next[hl[x[u]][0]][0];
	}
 
	return gcd(get(x[v], y[v], y[u]), ans);
}
 
void update(int v, int u, int value, int dec) {
	while (x[v] != x[u]) {
		updateDecomposition(x[u], 0, y[u], value);
		u = next[hl[x[u]][0]][0];
	}
 
	updateDecomposition(x[v], y[v] + dec, y[u], value);
}
 
int main() {
//#ifdef NALP_PROJECT
	freopen("tst.in", "r", stdin);
	freopen("slow.out", "w", stdout);
//#else
//#endif
    int start = clock(); 
	cin >> n;
	forn(i, n - 1) {
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].pb(u);
		g[u].pb(v);
	}
 
	forn(i, n)
		scanf("%d", &value[i]);
 
	hls = 1;
	DFS(0, 0);
	build(0, 0, 0);
	forn(i, hls) {
		b[i].assign(hl[i].size(), mp(0, 0));
		upd[i].assign(hl[i].size(), 0);
		a[i].assign(hl[i].size(), 0);
	}
 
	forn(i, n)
		a[x[i]][y[i]] = value[i];
 
	forn(i, hls) {
		int s = (int)sqrt(0.0 + a[i].size());
		for(int j = 0; j <= (int(a[i].size()) - 1) / s; j++)
			recalc(i, j);
	}
 
	cin >> m;
	forn(query, m) {
		int v, u;
		char command[3];
		scanf(" %s%d%d", command, &v, &u);
 
		int lca = getLCA(v, u);
		if (command[0] == 'F') {
			int gv = getGCD(lca, v), gu = getGCD(lca, u);
			printf("%d\n", gcd(gv, gu));
		} else {
			int d;
			scanf("%d", &d);
			update(lca, v, d, 0);
			update(lca, u, d, 1);
		}
	}
    cout <<clock() - start <<endl;
	return 0;
}
 

