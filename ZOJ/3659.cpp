/*
 * Author:  Troy
 * Created Time:  2012/10/14 23:05:25
 * File Name: 3659.cpp
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
#define Maxn 222222
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n;
struct Edge{
    int u, v, w;
    bool operator<(const Edge &b) const {
        return w > b.w;
    }
}e[Maxn];
int fa[Maxn*2];
long long sz[Maxn*2], dp[Maxn*2];
int nn;
int find(int x) {
    if (fa[x] == x) return x;
    else {
        int tmp = find(fa[x]);
        dp[x] += dp[fa[x]];
        fa[x] = tmp;
        return tmp;
    }
}
int Union(int x, int y, int w) {
     x = find(x), y = find(y);
    dp[x] += 1LL * sz[y] * w, dp[y] += 1LL * sz[x] * w;
    fa[x] = fa[y] = nn;
    fa[nn] = nn; dp[nn] = 0; sz[nn] = sz[x] + sz[y];
    nn++;
}
int main() {
    while (~sf("%d", &n)) {
        REP(i, n-1) sf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
        sort(e, e+n-1);
        nn = n + 1;
        FOR(i, 1, 2*n+1) fa[i] = i, sz[i] = 1, dp[i] = 0;
        long long ans = 0;
        REP(i, n-1) {
            Union(e[i].u, e[i].v, e[i].w);
        }
        FOR(i, 1, n+1) {
            find(i);
            ans = max(ans, dp[i]);
        }
        cout <<ans <<endl;
    }
    return 0;
}

