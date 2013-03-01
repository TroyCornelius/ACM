/*
 * Author:  Troy
 * Created Time:  2012/10/2 0:57:10
 * File Name: d.cpp
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
#define Maxn 5010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, h[Maxn], sum[Maxn];
int dp[Maxn], g[Maxn];
int main() {
    sf("%d", &n);
    FOR(i, 1, n+1) sf("%d", &h[i]);
    partial_sum(h, h+n+1, sum);
    g[0] = 0, dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (h[i] >= g[i-1]) {
            dp[i] = dp[i-1];
            g[i] = h[i];
        }
        else {
            g[i] = maxint;
            for (int j = i-1; j >= 0; j--) {
                if (sum[i] - sum[j] >= g[j]) {
                    g[i] = sum[i] - sum[j];
                    dp[i] = dp[j] + i - j - 1;
                    break;
                }
            }
        }
    }
    pf("%d\n", dp[n]);
    return 0;
}

