/*
 * Author:  Troy
 * Created Time:  2012/5/11 0:04:07
 * File Name: b.cpp
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
const int inf = 1999999999;
int n,m,r;
int cost[65][65][65];
int ans[65][65][65], dp[65][65][65];
int main() 
{
    sf("%d%d%d", &n, &m, &r);
    REP(i, m)
    {
        REP(j, n)
            REP(k, n)
                sf("%d", &cost[i][j][k]);
        
        REP(k, n)
            REP(x, n)
                REP(y, n)
                {
                    if (cost[i][x][y] > cost[i][x][k] + cost[i][k][y])
                        cost[i][x][y] = cost[i][x][k] + cost[i][k][y];
                }
    }
    
    int tmp = inf;
    REP(i, n)
        REP(j, n)
        {
            tmp = inf;
            REP(k, m)
                if (cost[k][i][j] < tmp) tmp = cost[k][i][j];
            ans[1][i][j] = tmp;
        }
    
    FOR(k, 2, n+2)
    {
        REP(i, n)
            REP(j, n)
            {
                if (i == j) ans[k][i][j] = tmp = 0;
                else ans[k][i][j] = tmp = inf;
                
                REP(x, n)
                {
                    if (ans[1][i][x] + ans[k-1][x][j] < tmp) tmp = ans[1][i][x] + ans[k-1][x][j];
                }
                ans[k][i][j] = tmp;
            }
    }
    
    int st, en, ki;
    while (r--)
    {
        sf("%d%d%d", &st, &en, &ki);
        if (ki > n) ki = n;
        st--; en--;
        pf("%d\n", ans[ki+1][st][en]);
    }
        




    return 0;
}

