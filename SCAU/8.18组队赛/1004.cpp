/*
 * Author:  Troy
 * Created Time:  2012/8/18 20:17:21
 * File Name: 1004.cpp
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
using namespace std;
const int Maxn = (1<<6) + 10;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

const int mod = 1000000007;
int st[55];
int dp[2][Maxn][Maxn][Maxn];
int n, m;
int can[55][Maxn];
inline bool check(int ss, int now) {
    REP(i, m)
        if ((1<<i)&now) {
            int next = i + 1;
            while (next < m && !((1<<next)&now)) next++;
            if (next < m && next == i+1) return false; 
            if (next >= m) break;
            bool flag = false;
            for (int x = i+1; x < next; x++) {
                if ((1<<x)&ss) {flag = true;break;}
            }
            if (!flag) return false;
        }
    return true;
}
void init() {
    int all = (1 << m), t;
    FOR(i, 1, n+1) {
        int tot = 0;
        REP(j, all)
        if (!(st[i] & j) && check(st[i], j)) can[i][++tot] = j;
        can[i][0] = tot;
    }
}
int work_dp() {
    memset(dp, 0, sizeof(dp));
    int all = (1 << m) - 1;
    dp[0][0][0][0] = 1;
    int now = 0, q = 1;
    FOR(i, 1, n+1) {
        now ^= 1; q ^= 1;
        memset(dp[now], 0, sizeof(dp[now]));
        REP(x, all+1)
            REP(y, all+1)
                REP(z, all+1)
                if (dp[q][x][y][z]) {
                    int t1 = x, t2 = ((y<<1)&all), t3 = ((z>>1)&all);
                    t1 ^= (t1 & st[i]), t2 ^= (t2 & st[i]), t3 ^= (t3 & st[i]);
                    int tmp = (t1 | t2 | t3);
                    for (int p = 1; p <= can[i][0]; p++) {
                        int v = can[i][p];
                        if (!(v & tmp)) {
                            int &ret = dp[now][t1|v][t2|v][t3|v];
                            ret += dp[q][x][y][z];
                            if (ret >= mod) ret -= mod;
                        }
                    }
                }
    }
    int ans = mod - 1;
    REP(x, all+1)
        REP(y, all+1)
            REP(z, all+1) {
                ans += dp[now][x][y][z];
                if (ans >= mod) ans -= mod;
            }
    return ans;
}
int main() {
    int T, ca = 0;
    char str[10];
    sf("%d", &T);
    while (T--) {
        sf("%d%d", &n, &m);
        FOR(i, 1, n+1) {
            st[i] = 0;
            sf("%s", str);
            REP(j, m)
                if (str[j] == '#') st[i] |= (1<<j);
        }
    init();
    pf("Case %d: %d\n", ++ca, work_dp());
    }
    return 0;
}

