/*
 * Author:  Troy
 * Created Time:  2012/5/11 21:42:57
 * File Name: f.cpp
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

int n, m;
int a[20];
int dp[15][15];
int main() 
{
    int T, ca = 0;
    cin >>T;
    while (T--)
    {
        memset(dp, 0, sizeof(dp));
        cin >>m >>n;
        REP(i, m)
        {
            cin >>a[i];
            dp[1][i] = 1;
        }
        FOR(i, 2, n+1)
        {
            REP(j, m)
                REP(k, m)
                {
                    if (abs(a[j] - a[k]) <= 2) dp[i][j] += dp[i-1][k];
                }
        }
        int ans = 0;
        REP(i, m) ans += dp[n][i];
        cout <<"Case " <<++ca <<": " <<ans <<endl;
        
    }
    return 0;
}

