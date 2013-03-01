/*
 * Author:  Troy
 * Created Time:  2012/12/7 21:39:23
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m, k, p;
long long dp[21][21][13][245];
ll c[22][22];
void init() {
    memset(dp, 0, sizeof(dp));
    FOR(i, 3, m+1) dp[0][0][i][0] = 1;
    FOR(mi, 3, m+1)
        FOR(i, 1, n+1)
            FOR(j, mi*i, m*i+1)
                FOR(t, 1, m+1) {
                    if (t < mi) {
                    }
                    dp[i][mi][j] += dp[i-1][mi][j-t];
                }
}
ll pw(ll x, int y) {
    ll ret = 1;
    while (y--) ret *= x;
    return ret;
}
ll fact(int tot) {
    ll ret = 1;
    FOR(i, 1, tot+1) ret *= i;
    return ret;
}
ll get_C(int x, int y) {
    ll ret = 0;
    FOR(i, 1, min(x,y)+1)
        ret += c[x][i];
    return ret;
}
int main() {
    while (cin >>n >>m >>k >>p) {
        init();
        ll ans = 0;
        FOR(i, 3, m+1) {
            ans += dp[k][i][p] * pw(i - 3 + 1, n - k) * fact(n - k) * get_C(k+1, n-k);
        }
        cout <<ans <<endl;
    }
    return 0;
}

