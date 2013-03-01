/*
 * Author:  Troy
 * Created Time:  2013/1/18 21:37:08
 * File Name: d.cpp
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
#define Maxn 100010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, a[Maxn], ans;
bool vis[1<<20];
vi loc[21][2];
void init() {
    REP(i, 21) {
        loc[i][0].clear();
        loc[i][1].clear();
    }
    REP(i, n) {
        REP(j, 20)
            if ((a[i]>>j)&1) loc[j][1].pb(i);
            else loc[j][0].pb(i);
    }
}
void solve() {
    ans = 0;
    int num, x, y;
    vector<pii> p1, p0;
    REP(i, n) {
        num = a[i];
        vis[num] = true;
        p1.clear();
        p0.clear();
        REP(j, 20) {
            if (!((num >> j) & 1)) {
                vit it = upper_bound(all(loc[j][1]), i);
                if (it != loc[j][1].end()) p1.pb(mp(*it, j));
            }
            else {
                vit it = upper_bound(all(loc[j][0]), i);
                if (it != loc[j][0].end()) p0.pb(mp(*it, j));
            }
        }
        //for or
        sort(all(p1));
        x = 0;
        while (x < p1.size()) {
            for (y = x; y < p1.size() && p1[y].fi == p1[x].fi; y++) {
                num |= (1<<p1[y].se);
            }
            vis[num] = true;
            x = y;
        }
        //for and
        num = a[i];
        sort(all(p0));
        x = 0;
        while (x < p0.size()) {
            for (y = x; y < p0.size() && p0[y].fi == p0[x].fi; y++) {
                num ^= (1<<p0[y].se);
            }
            vis[num] = true;
            x = y;
        }
    }
    REP(i, 1<<20)
        if (vis[i]) ans++;
    pf("%d\n", ans);
}
int main() {
    int T;
    sf("%d", &T);
    while (T--) {
        sf("%d", &n);
        REP(i, n) sf("%d", &a[i]);
        memset(vis, false, sizeof(vis));
        init();
        solve();
    }
    return 0;
}

