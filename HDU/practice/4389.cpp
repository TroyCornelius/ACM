/*
 * Author:  Troy
 * Created Time:  2012/8/21 18:56:45
 * File Name: 4380.cpp
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
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int dp[11][83][83][83], ten[11];
void init() {
    ten[0] = 1;
    FOR(i, 1, 10) ten[i] = ten[i-1] * 10;
    memset(dp, 0, sizeof(dp));
    REP(i,  10)
       FOR(j, 1, 82) dp[1][j][i][i%j] = 1;
    FOR(i, 1, 9)
        FOR(j, 1, 82)
            REP(x, i*9+1)
                REP(y, j+1)
                if (dp[i][j][x][y]) {
                    for (int k = 0; k < 10 && x + k < 82; k++) {
                        dp[i+1][j][x+k][(y*10+k)%j] += dp[i][j][x][y];
                    }
                }
    return;
}
int a[12];

int calc(int x) {
    if (x <= 10) return x;
    int n = 0, s = 0;
    for (int tmp = x; tmp; tmp /= 10, n++) s += tmp % 10, a[n+1] = tmp % 10;
    int ret = 0;
    int sum, num;
    for (int y = 1; y <= 9 * n; y++) {
        if (y > x) break;
        sum = y;
        num = 0;
        for (int i = n; i > 1; i--) {
            for (int j = 0; j < a[i] && j <= sum; j++) {
                for (int mod = 0; mod < y; mod++) {
                    if ((num + j * ten[i-1] + mod) % y == 0)
                        ret += dp[i-1][y][sum - j][mod];
                }
            }
            sum -= a[i];
            num += a[i] * ten[i-1];
        }
    }
    while (1) {
        if (x % s == 0) ret++;
        if (x % 10 == 0) break;
        x--; s--;
    }
    return ret;
}
int main() {
    init();
    int a, b, T, ca = 0;
    sf("%d", &T);
    while (T--) {
        sf("%d%d", &a, &b);
        pf("Case %d: %d\n", ++ca, calc(b) - calc(a - 1));
    }
    return 0;
}


