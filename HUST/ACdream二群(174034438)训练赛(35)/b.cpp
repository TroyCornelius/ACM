/*
 * Author:  Troy
 * Created Time:  2012/6/1 19:21:10
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
const int inf = 1<<29;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;


int n, badball;
int d[50], t[50];
bool flag;
int dp[50][5];
int main() 
{
    while (~sf("%d", &n), n)
    {
        flag = true;
        REP(i, n)
            sf("%d%d", &d[i], &t[i]);

        if (t[0] < d[0])
        {
            pf("NG 1\n");
            continue;
        }
        
        dp[0][1] = d[0];
        dp[0][2] = dp[0][3] = inf;
        
        FOR(i, 1, n)
        {
            FOR(j, 1, 4)
            {
                dp[i][j] = inf;
                int ti = t[i] - t[i-1];
                if (j > 1 && ti >= j * abs(d[i] - d[i-1]))
                {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + abs(d[i] - d[i-1]));
                }
                
                if (j == 1)
                {
                    FOR (k, 1, 4)
                    if (dp[i-1][k] != inf)
                    {
                        if (ti >= (k+1)*d[i-1] + d[i])
                        {
                            dp[i][j] = min(dp[i][j], dp[i-1][k] + d[i-1] + d[i]);
                        }
                    }
                }
            }
            flag = false; badball = i+1;
            FOR(j, 1, 4)
                if (dp[i][j] != inf) flag = true;
            if (!flag) break;            
            //FOR(j, 1, 4) cout <<dp[i][j] <<" ";
            //cout <<endl;
        }
        
        if (!flag)
        {
            pf("NG %d\n", badball);
            continue;
        }
        else
        {
            //FOR(j, 1, 4) cout <<dp[n-1][j] <<" ";
            //cout <<endl;
            int ans = inf;
            FOR(j, 1, 4)
                if (dp[n-1][j] != inf)
                    ans = min(ans, dp[n-1][j] + d[n-1]);
            pf("OK %d\n", ans);
        }
    }
    return 0;
}

