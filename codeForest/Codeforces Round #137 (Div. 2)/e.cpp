/*
 * Author:  Troy
 * Created Time:  2012/9/11 1:11:02
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
#define sf scanf
#define pf printf
#define Maxn 100010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const int mod = 1000000007;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int dp[Maxn][55][55];
int n, m, k;
int w[256];
bool can[55][55];
int main() 
{
    char s[3];
    sf("%d%d%d", &n, &m, &k);
    memset(can, true, sizeof(can));
    for (char ch = 'a'; ch <= 'z'; ch++) w[ch] = ch - 'a' + 1;
    for (char ch = 'A'; ch <= 'Z'; ch++) w[ch] = ch - 'A' + 27;
    REP(i, k) {
        sf("%s", s);
        can[w[s[0]]][w[s[1]]] = false;
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; ++i) dp[1][i] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            for (int x = 1; x <= m; x++)
                if (can[j][x]) {
                    dp[i][x] += dp[i-1][j];
                    if (dp[i][x] >= mod) dp[i][x] -= mod;
                }
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        ans += dp[n][i];
        if (ans >= mod) ans -= mod;
    }
    pf("%d\n", ans);
    return 0;
}

