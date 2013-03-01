/*
 * Author:  Troy
 * Created Time:  2012/11/30 20:33:48
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
#define ll long long
#define sf scanf
#define pf printf
#define Maxn 50100 
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, sum[Maxn], ans;
vi g[Maxn];
void dfs(int u, int fa) {
    sum[u] = 1;
    int mx = n - 1;
    REP(i, g[u].size()) {
        int v = g[u][i];
        if (v != fa) {
            dfs(v, u);
            sum[u] += sum[v];
            mx = min(n - sum[v], mx);
        }
    }
    if (fa != -1) mx = min(sum[u], mx);
    ans = max(ans, mx);
    //cout <<u <<" "<<sum[u] <<endl;
}
int main() {
    while (~sf("%d", &n)) {
        REP(i, n+1) g[i].clear();
        int u, v;
        REP(i, n-1) {
            sf("%d%d", &u, &v);
            g[u].pb(v);
            g[v].pb(u);
        }
        memset(sum, 0, sizeof(sum));
        ans = 1;
        dfs(1, -1);
        pf("%d\n", ans);
    }
    return 0;
}
