/*
 * Author:  Troy
 * Created Time:  2012/12/16 23:30:58
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
#define Maxn 4010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, a[Maxn], b[Maxn];
int dp[Maxn][Maxn];
int main() {
    sf("%d", &n);
    REP(i, n) sf("%d", &a[i]);
    memcpy(b, a, sizeof(a));
    sort(b, b+n);
    int m = unique(b, b+n) - b;
    REP(i, n) 
        a[i] = lower_bound(b, b+m, a[i]) - b;
    int ans = 1;
    if (n > 1) ans = 2;
    memset(dp, -1, sizeof(dp));
    REP(i, n) {
        for (int j = i-1; j >= 0; j--) dp[i][a[j]] = 2;
    }
    REP(i, n) {
        for (int j = i-1; j >= 0; j--) {
            if (dp[j][a[i]] != -1) {
                dp[i][a[j]] = max(dp[j][a[i]] + 1, dp[i][a[j]]);
                ans = max(dp[i][a[j]], ans);
            }
        }
    }
    pf("%d\n", ans);
    return 0;
}

