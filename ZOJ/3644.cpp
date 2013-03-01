/*
 * Author:  Troy
 * Created Time:  2012/10/1 13:18:56
 * File Name: 3644.cpp
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
#define Maxn 2010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

const int mod = 1000000007;
int n, m, k;
int p[Maxn];
int id[1000015], dp[Maxn][Maxn];
vi num;
vector<pii > edge;
int main() {
    int u, v, w;
    while (~sf("%d%d%d", &n, &m, &k)) {
        edge.clear();
        REP(i, m) {
            sf("%d%d", &u, &v);
            edge.pb(mp(u, v));
        }
        FOR(i, 1, n+1) sf("%d", &p[i]);
        memset(id, -1, sizeof(id));
        num.clear();
        FOR(i, 1, k+1)
            if (k % i == 0) {
                num.pb(i);
                id[i] = num.size();
            }
        if (id[p[1]] == -1) puts("0");
        else {
            memset(dp, 0, sizeof(dp));
            dp[id[p[1]]][1] = 1;
            for (int i = 0; i < num.size(); i++) {
                for (int j = 0; j < edge.size(); j++) {
                    int x = p[edge[j].se], y = num[i];
                    long long tmp = 1LL * x * y / __gcd(x, y);
                    if (tmp > k || id[tmp] == -1 || tmp == y) continue;
                    else {
                        dp[id[tmp]][edge[j].se] += dp[id[num[i]]][edge[j].fi];
                        if (dp[id[tmp]][edge[j].se] >= mod) dp[id[tmp]][edge[j].se] -= mod;
                    }
                }
            }
            pf("%d\n", dp[(int)num.size()][n]);
        }
    }
    return 0;
}

