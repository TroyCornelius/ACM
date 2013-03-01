/*
 * Author:  Troy
 * Created Time:  2012年07月20日 星期五 01时07分21秒
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
#define Maxn 310
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
const int mod = 10007;

int n, r;
int g[Maxn][Maxn], a[Maxn][Maxn], b[Maxn][Maxn];
pii p[Maxn];
map<pii,pii> rec[Maxn];

void init()
{
	memset(g, 0, sizeof(g));
	memset(a, 0, sizeof(a));
	REP(i, n) rec[i].clear();
}
void build()
{
	r = r * r;
	sort(p, p+n);
	REP(i, n)
		FOR(j, i+1, n)
		if ((p[i].fi - p[j].fi)*(p[i].fi - p[j].fi) + (p[i].se - p[j].se) * (p[i].se - p[j].se) <= r)
		{
			pii tmp = mp(p[j].fi - p[i].fi, p[j].se - p[i].se);
			int v = __gcd(abs(tmp.fi), abs(tmp.se));
			if (v == 0) v = 1;
			tmp.fi /= v; tmp.se /= v;
			if (rec[i].find(tmp) == rec[i].end())
			{
				g[i][j] = g[j][i] = 1;
				rec[i][tmp] = p[j];
			}
		}
	REP(i, n)
	{
		int cnt = 0;
		REP(j, n) if (g[i][j]) cnt++;
		a[i][i] = cnt;
	}
	REP(i, n)
		REP(j, n)
		if (g[i][j]) a[i][j] = -1;
}
int fni(int x)
{
	int tmp = mod - 2, ret = 1, tt = x;
	while (tmp)
	{
		if (tmp & 1) ret = (ret * tt) % mod;
		tt = (tt * tt) % mod;
		tmp >>= 1;
	}
	return ret;
}
int solve()
{
	n--;
	int ret = 1;
	REP(i, n)
		REP(j, n)
		b[i][j] = a[i][j];
	REP(i, n)
	{
		if (b[i][i] == 0)
		{
			int j = i + 1;
			while (j < n && !b[j][i]) j++;
			if (j == n) return 0;
			FOR(k, i, n) swap(b[i][k], b[j][k]);
		}
		ret = (ret * b[i][i]) % mod;
		FOR(k, i+1, n) b[i][k] = b[i][k] * fni(b[i][i]) % mod;
		FOR(j, i+1, n)
			FOR(k, i+1, n)
			{
				b[j][k] -= b[j][i] * b[i][k] % mod;
				b[j][k] = (b[j][k] % mod + mod) % mod;
			}
	}
	return ret;
}
int main() 
{
	int T;
	sf("%d", &T);
	while (T--)
	{
		sf("%d%d", &n, &r);
		REP(i, n) sf("%d%d", &p[i].fi, &p[i].se);
		init();
		build();
		int ans = solve();
		if (ans == 0) ans = -1;
		pf("%d\n", ans);
	}
    return 0;
}

