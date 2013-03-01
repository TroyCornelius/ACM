/*
 * Author:  Troy
 * Created Time:  2013/1/17 0:54:24
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
#define Maxn 100015
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

vi nei[Maxn];
int n, ans[Maxn];
bool vis[Maxn];
bool check(int a, int b) {
    REP(i, nei[a].size())
        if (nei[a][i] == b) return true;
    return false;
}
bool solve() {
    memset(vis, false, sizeof(vis));
    vis[1] = vis[ans[0]] = vis[ans[2]] = true;
    int now = ans[2], p = 3, fa = ans[2];
    int a, b;
    bool flag = true;
    while (flag) {
        flag = false;
        now = ans[p-1];
        a = ans[p-2];
        REP(i, nei[now].size()) {
            b = nei[now][i];
            if (!vis[b] && check(a, b)) {
                vis[b] = true;
                ans[p++] = b;
                flag = true;
            }
        }
        if (p > n) break;
    }
    if (p != n || !check(ans[1], ans[n-1]) || !check(ans[0], ans[n-2])) return false;
    else return true;
}
bool judge() {
    FOR(i, 1, n+1)
        if (nei[i].size() != 4) return false;
    return true;
}
int main() {
    sf("%d", &n);
    int a, b;
    REP(i, 2*n) {
        sf("%d%d", &a, &b);
        nei[a].pb(b);
        nei[b].pb(a);
    }
    if (judge()) {
        REP(i, nei[1].size())
            FOR(j, i+1, nei[1].size()) {
                a = nei[1][i], b = nei[1][j];
                if (!check(a, b)) continue;
                ans[0] = a, ans[1] = 1, ans[2] = b;
                if (solve()) {
                    REP(i, n)
                        pf("%d%c", ans[i], i==n-1?'\n':' ');
                    return 0;
                }
            }
    }
    puts("-1");
    return 0;
}

