/*
 * Author:  Troy
 * Created Time:  2013/1/18 20:31:52
 * File Name: a.cpp
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
const int mod = 1000000007;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, a, b, c, ans;
vi num;
int dp[2][110][110][130];
void init() {
    num.clear();
    FOR(i, 1, b+1)
        if (b % i == 0) num.pb(i);
}
int gcd(int x, int y) {
    if (x % y == 0) return y;
    else return gcd(y, x%y);
}
inline int get_lcm(int x, int y) {
    return x * y / gcd(x, y);
}
int solve() {
    dp[0][0][1][0] = 1;
    int ret = 0;
    int p = 0, q = 1, lcm, x, d, jj;
    REP(tot, n) {
        REP(it, num.size()) {
            d = num[it];
            //cout <<d <<"-----" <<endl;
            REP(i, a+1) {
                if (i + d > a) break;
                FOR(j, 0, num.size()) {
                    jj = num[j];
                    lcm = get_lcm(d, jj);
                    if (lcm > b) continue;
                    REP(k, 128) {
                        x = k ^ d;
                        dp[q][i+d][lcm][x] += dp[p][i][jj][k];
                        if (dp[q][i+d][lcm][x] >= mod) dp[q][i+d][lcm][x] -= mod;
                        //if (dp[p][i][j][k] == 1 || dp[q][i][j][k] == 1)
                        //cout <<dp[q][i+d][lcm][x] <<"***" <<" "<<i+d <<" "<<lcm <<" "<<x <<endl;
                    }
                }
            }
        }
        q ^= 1;
        p ^= 1;
    }
    return dp[p][a][b][c];
}
int main() {
    int T;
    cin >>T;
    while (T--) {
        cin >>n >>a >>b >>c;
        memset(dp, 0, sizeof(dp));
        init();
        ans = solve();
        cout <<ans <<endl;
    }
    return 0;
}

