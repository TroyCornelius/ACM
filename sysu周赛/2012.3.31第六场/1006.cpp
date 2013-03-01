/*
 * Author:  Troy
 * Created Time:  2012/3/31 22:15:54
 * File Name: 1006.cpp
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
const int mod = 97654321;

int u, l, n;
int dp[256][256][210], ans;
pii d[210];
int main() 
{
    ios::sync_with_stdio(false);
    string s;
    while (cin >>u >>l >>n)
    {
        REP(i, n)
        {
            cin >>s;
            if (isupper(s[0])) d[i].fi = s[0] - 'A';
            else d[i].fi = s[0] - 'a' + 26;
            
            if (isupper(s[1])) d[i].se = s[1] - 'A';
            else d[i].se = s[1] - 'a' + 26;
        }
        memset(dp, 0, sizeof(dp));
        REP(i, 26) dp[1][0][i] = 1;
        FOR(i, 26, 52) dp[0][1][i] = 1;
        
        REP(i, u+1)
            REP(j, l+1)
            {
                if (!i && !j) continue;
                REP(t, n)
                {
                    if (d[t].se < 26 && i>0)
                    {
                        dp[i][j][d[t].se] += dp[i-1][j][d[t].fi];
                        dp[i][j][d[t].se] %= mod;
                    }
                    else
                    if (d[t].se >= 26 && j>0)
                    {
                        dp[i][j][d[t].se] += dp[i][j-1][d[t].fi];
                        dp[i][j][d[t].se] %= mod;
                    }
                }
            }
        ans = 0;
        REP(i, 52) ans = (ans + dp[u][l][i]) % mod;
        pf("%d\n", ans);
    }
    return 0;
}

