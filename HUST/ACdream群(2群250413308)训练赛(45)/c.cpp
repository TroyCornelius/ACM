/*
 * Author:  Troy
 * Created Time:  2012/7/23 19:34:52
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
#define Maxn 1110
using namespace std;
const int maxint = 1<<30;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int lim[Maxn], pri[Maxn], d[Maxn], n; 
int dp[2][110];
int main() 
{
    int T;
    sf("%d", &T);
    while (T--)
    {
        sf("%d", &n);
        FOR(i, 1, n+1) sf("%d%d%d", &pri[i], &lim[i], &d[i]);
        //REP(i, n) sf("%d", &lim[i]);
        //REP(i, n) sf("%d", &d[i]);
        /*
        int ans = 0, res = 0;
        REP(i, n)
        {
            if (res > 0) d[i] -= res, res = 0;
            if (d[i] >= 0)
            {
                lim[i] -= d[i];
                ans += d[i] * p[i];
                if (lim[i] > 0 && i+1 < n)
                {
                    if (p[i] <= p[i+1])
                    {
                        res = min(lim[i], d[i+1]);
                        ans += res * p[i];
                    }
                    else
                    {
                        if (d[i+1] > lim[i+1])
                        {
                            res = d[i+1] - lim[i+1];
                            ans += res * p[i];
                        }
                    }
                }
            }
        }
        pf("%d\n", ans);*/
        int p = 0, q;
        REP(k, 2)
            REP(j, 101) dp[k][j] = maxint;
        dp[0][0] = 0;
        
        FOR(i, 1, n+1)
        {
            q = p; p ^= 1;
            REP(j, 101) dp[p][j] = maxint;
            REP(j, d[i]+1)
                if (dp[q][j] != maxint)
                {
                    for (int x = d[i] - j; x <= lim[i] && x - (d[i] - j) <= 100; x++)
                        dp[p][x-d[i]+j] = min(dp[p][x-d[i]+j], dp[q][j] + x * pri[i]);
                }
        }
        pf("%d\n", dp[p][0]);
    }
    return 0;
}

