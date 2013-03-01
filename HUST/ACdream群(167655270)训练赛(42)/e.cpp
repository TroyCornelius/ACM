/*
 * Author:  Troy
 * Created Time:  2012/7/14 23:01:10
 * File Name: e.cpp
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
const long long inf = 1LL << 60;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n;
long long d;
long long h[110];
inline long long ABS(long long x)
{
    return x >= 0 ? x : -x;
}
vector<long long> b;
long long dp[2][110*510];
int main() 
{
    int T;
    sf("%d", &T);
    while (T--)
    {
        sf("%d%I64d", &n, &d);
        REP(i, n) sf("%I64d", &h[i]);
        if (ABS(h[0] - h[n-1]) > 1LL * (n - 1) * d)
        {
            pf("impossible\n");
            continue;
        }
        
        b.clear();
        REP(i, n)
        {
            for (long long j = -(n-1); j <= n-1; j++) b.pb(h[i] + j * d);
        }
        
        sort(all(b));
        b.erase(unique(all(b)), b.end());
        int m = b.size(), p = 0, q;
        REP(i, m) 
            if (b[i] != h[0]) dp[p][i] = inf;
            else dp[p][i] = 0;
        FOR(i, 1, n)
        {
            q = p ^ 1;
            REP(j, m) dp[q][j] = inf;
            int k = 0;
            REP(j, m)
            {
                while (k < m && b[k] < b[j] - d) k++;
                while (k+1 < m && b[k+1] <= b[j] + d && dp[p][k+1] <= dp[p][k]) k++;
                dp[q][j] = min(dp[q][j], dp[p][k] + ABS(b[j] - h[i]));
            }
            p = q;
        }
        REP(i, m)
            if (b[i] == h[n-1])
            {
                pf("%I64d\n", dp[p][i]);
                break;
            }      
        
    }
    return 0;
}

