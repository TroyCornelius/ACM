/*
 * Author:  Troy
 * Created Time:  2012/9/20 0:36:17
 * File Name: c.cpp
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
const int inf =  1<<29;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m, x, y;
char g[1010][1010];
int sum[1010];
int dp[1010][3];
int main() {
    sf("%d%d%d%d", &n, &m, &x, &y);
    REP(i, n) sf("%s", g[i]);
    REP(i, m) 
        REP(j, n)
        if (g[j][i] == '.') sum[i+1]++;
    sum[0] = 0;
    for (int i = 1; i <= m; i++) sum[i] += sum[i-1];
    
    REP(i, m+1) 
        REP(k, 3) dp[i][k] = inf;
    dp[0][0] = dp[0][1]  = dp[0][2] = 0;
    int ans = inf;
    for (int i = x; i <= m; i ++) {
            //if (sum[i] - sum[i-1] != 0 && sum[i]-sum[i-1] != n) {
                //dp[i][2] = min(dp[i][2], min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2])));
            //}
            //else {
                //dp[i][2] = min(dp[i][2], min(dp[i-1][2], min(dp[i-1][0], dp[i-1][2])+1));
            //}
            for (int j = x; j <= y && i - j >= 0; j++) {
                dp[i][0] = min(dp[i][0], dp[i-j][1] + sum[i] - sum[i-j]);
                dp[i][1] = min(dp[i][1], dp[i-j][0]+ j*n-(sum[i]-sum[i-j]));
            }
    }
    cout <<min(dp[m][0], dp[m][1]) <<endl;

    return 0;
}

