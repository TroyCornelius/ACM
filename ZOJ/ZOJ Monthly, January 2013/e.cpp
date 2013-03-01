/*
 * Author:  Troy
 * Created Time:  2013/1/21 12:58:14
 * File Name: e.cpp
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

int s1, s2, n;
int d[210], sum[210];
map<pair<pii, int>, int> dp;
int dfs(int m, int a, int b) {
    if (m >= n) return a == s1 && b == s2 ? 1 : 0;
    if (dp.find(mp(mp(a, b), m)) != dp.end()) return dp[mp(mp(a, b), m)];
    pair<pii, int> st = mp(mp(a, b), m);
    dp[st] = 0;
    //cout <<a <<" "<<b <<" === "  << sum[n] - sum[m] <<" "<<sum[n] <<endl;
    if (a + sum[n] - sum[m] < s1 || b + sum[n] - sum[m] < s2) return dp[st];
    if (d[m] % 2 == 0) {
        if (a + d[m]/2 <= s1 && b + d[m]/2 <= s2) dp[st] += dfs(m+1, a+d[m]/2, b+d[m]/2);
    }
    if (a + d[m] <= s1) dp[st] = (dp[st] + dfs(m + 1, a + d[m], b)) % mod;
    if (b + d[m] <= s2) dp[st] = (dp[st] + dfs(m + 1, a, b + d[m])) % mod;
    //cout <<m <<" "<<a <<" "<<b <<dp[st] <<endl;
    return dp[st];
}
int main() {
    while (cin >>s1 >>s2) {
        cin >>n;
        REP(i, n) cin >>d[i];
        sum[0] = 0;
        REP(i, n) sum[i+1] = sum[i] + d[i];
        dp.clear();
        int ans = dfs(0, 0, 0);
        cout <<ans <<endl;
    }
    return 0;
}

