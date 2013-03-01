/*
 * Author:  Troy
 * Created Time:  2013/1/20 22:28:48
 * File Name: chk.cpp
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
const ll inf = 1LL<<60;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, q;
int v[10100], c[10010];
ll dp[10010], a, b, ans;
ll solve() {
    ans = 0;
    REP(i, n+1) dp[i] = -inf;
    FOR(i, 1, n+1) {
        dp[i] = b * v[i];
        FOR(j, 1, i) {
            if (dp[j] != -inf) {
                if (c[j] == c[i]) dp[i] = max(dp[i], dp[j] + a*v[i]);
                else dp[i] = max(dp[i], dp[j] + b*v[i]);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}
int main() {
    freopen("c.in", "r", stdin);
    freopen("std.out", "w", stdout);
    cin >>n >>q;
    FOR(i, 1, n+1) cin >>v[i];
    FOR(i, 1, n+1) cin >>c[i];
    while (q--) {
        cin >>a >>b;
        cout <<solve() <<endl;
    }
    return 0;
}

