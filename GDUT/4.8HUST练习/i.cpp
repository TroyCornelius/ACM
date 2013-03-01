/*
 * Author:  Troy
 * Created Time:  2012/4/10 17:13:25
 * File Name: i.cpp
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

int n, t, q, m;
int dp[110][110];
pii sk[110];
int work()
{
    int ret = 100, last;
    FOR(i, 1, m+1)
    {
        REP(j, 101)
        {
            dp[i][min(100, j+t)] = dp[i-1][j] - 1;
            if (dp[i][j] <= 0) return i;
            
            REP(k, n)
            {
                int now = min(100, j+t);
                if (now >= sk[k].fi)                
                {
                    if (dp[i-1][j] - sk[k].se <= 0) return i;
                    dp[i][now-sk[k].fi] = min(dp[i][now-sk[k].fi], dp[i-1][j] - sk[k].se);
                }
            }            
        }
    }
    return -1;
}
int main() 
{
    while (~sf("%d%d%d", &n, &t, &q))
    {
        if (!n && !t && !q) break;
        REP(i, n) sf("%d%d", &sk[i].fi, &sk[i].se);
        REP(i, 101)
            REP(j, 101) dp[i][j] = 100;
        
        m = 100 / q + (100 % q == 0 ? 0 : 1);
        int ans = work();
        if (ans == -1) pf("My god\n");
        else pf("%d\n", ans);

        
    }
    return 0;
}

