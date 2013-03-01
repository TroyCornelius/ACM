/*
 * Author:  Troy
 * Created Time:  2012/12/14 21:06:35
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m;
int g[110][110], Link[110];
bool vis[110];
int dfs(int k, int id) {
    FOR(i, 1, n+1) {
        if (i != id && !vis[i] && g[k][i] < g[m][id]) {
            vis[i] = true;
            if (!Link[i] || dfs(Link[i], id) == 1) {
                Link[i] = k;
                return 1;
            }
        }
    }
    return 0;
}
bool check(int k) {
    memset(Link, 0, sizeof(Link));
    int tot = 1;
    Link[k] = m;
    FOR(i, 1, n+1) {
        if (i == m) continue;
        memset(vis, false, sizeof(vis));
        tot += dfs(i, k);
    }
    return tot == n;
}
int main() {
    while (~sf("%d", &n, &m)) {
        FOR(i, 1, n+1)
            FOR(j, 1, n+1)
                sf("%d", &g[i][j]);
        sf("%d", &m);
        vi ans;
        ans.clear();
        FOR(i, 1, n+1) {
            if (check(i)) ans.pb(i);
        }
        if (ans.size() == 0) puts("-1");
        else {
            REP(i, ans.size())
                pf("%d%c", ans[i], i == ans.size() - 1 ?'\n':' ');
        }
    }
    return 0;
}

