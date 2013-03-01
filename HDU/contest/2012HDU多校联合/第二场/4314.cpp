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
#define Maxn 2212
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const int inf = 1<<30;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, H;
pii d[Maxn];
int dp[Maxn][Maxn], sum[Maxn];
bool cmp(const pii &a, const pii &b)
{
    return a.fi+a.se > b.fi + b.se;
}
int main() 
{
    while (~sf("%d", &n))
    {
        FOR(i, 1, n+1) sf("%d%d",&d[i].fi, &d[i].se);
        sf("%d", &H);
        sort(d+1, d+n+1, cmp);
        sum[0] = 0;
        FOR(i, 1, n+1) sum[i] = sum[i-1] + d[i].fi;
        REP(i, n+1)
            REP(j, n+1)
            dp[i][j] = inf;
        dp[0][0] = 0;
        FOR(i, 1, n+1)
        {
            dp[i][0] = dp[i-1][0] - d[i].fi;
            FOR(j, 1, i+1)
            {
                dp[i][j] = dp[i-1][j] - d[i].fi;
                dp[i][j] = min(dp[i][j], max(dp[i-1][j-1], H - sum[i] - d[i].se));
            }
        }
        FORD(i, n, 0)
            if (dp[n][i] <= 0)
            {
                pf("%d\n", i);
                break;
            }
    }
    return 0;
}


