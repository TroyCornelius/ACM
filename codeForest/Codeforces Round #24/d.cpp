/*
 * Author:  Troy
 * Created Time:  2012/5/2 21:29:03
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
#define Maxn 1010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m, sx, sy;
double f1[Maxn], f2[Maxn], ans[Maxn];
double dp[Maxn][Maxn];
int main() 
{
    cin >>n >>m;
    cin >>sx >>sy;
    if (m == 1)
    {
        double tmp = 2.0 * (n - sx);
        pf("%.10f\n", tmp);
        return 0;
    }
    memset(dp, 0, sizeof(dp));
    FORD(i, n-1, sx)
    {
        //REP(k, 100)
        {
            FOR(j, 2, m)
            {
                dp[i][j] = (dp[i][j] + dp[i+1][j] + dp[i][j-1] + dp[i][j+1]);
            }
            dp[i][1] = (dp[i][1] + dp[i][2] + dp[i+1][1]) / 3.0 + 1.0;
            dp[i][m] = (dp[i][m] + dp[i+1][m] + dp[i][m-1]) / 3.0 + 1.0;
        }
    }
    pf("%.10f\n", dp[sx][sy]);
    return 0;
}

