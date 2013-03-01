/*
 * Author:  Troy
 * Created Time:  2012/8/11 21:38:23
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int k;
//string s1, s2;
char s1[1010], s2[1010];
int dp[1010][1010];
int LIS()
{
    memset(dp, 0, sizeof(dp));
    int n = strlen(s1), m = strlen(s2);
    FOR(i, 1, n+1)
        FOR(j, 1, m+1)
        {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            for (int p = 1; i - p >= 0 && j - p >= 0 && s1[i-p] == s2[j-p]; p++)
                if (p >= k) dp[i][j] = max(dp[i][j], dp[i-p][j-p] + p);
        }
    return dp[n][m];
}
int main() 
{
    //ios::sync_with_stdio(false);
    while (~sf("%d", &k), k)
    {
        //cin >>s1;
        //cin >>s2;
        sf("%s", s1);
        sf("%s", s2);
        pf("%d\n", LIS());
    }
    return 0;
}

