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
const int inf = 1<<30;
const int mm = 1<<11;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
int n, a[22], m;
vi num[22];
int dp[22][mm + 100], cnt[mm+100], st[22];
int calc(int x)
{
    int ret = 0;
    for (; x; x -= x&-x) ret++;
    return ret;    
}
int main() 
{
    int x;
    REP(i, mm) cnt[i] = calc(i);    
    while (~sf("%d", &n))
    {
        m = 0;
        REP(i, n)
        {
            num[i].clear();
            sf("%d", &x);
            for (; x; x /= 2) num[i].pb(x%2);
            if (num[i].size() > m) m = num[i].size();
        }
        memset(st, 0, sizeof(st));
        REP(i, n)
            REP(j, num[i].size())
            if (num[i][j] == 1) st[j] |= (1<<i);
        m++;
        REP(i, (1<<n)+5)
            REP(j, m+1) dp[j][i] = inf;
        int tmp;
        FOR(i, 0, m)
            REP(j, 1<<n)
            if ((i == 0 && j == 0) || (i > 0 && dp[i-1][j] != inf))
            {
                tmp = j & st[i];
                FOR(t, tmp, 1<<n)
                {
                    if ((t & tmp) == tmp)
                    {
                        if ((((st[i] ^ j) & (t ^ tmp)) == (t ^ tmp)))
                        {
                            int nst = ((st[i] ^ j) ^ (t ^ tmp));
                            if ((cnt[nst]&1) == 0 || cnt[nst] < n) dp[i][t] = min(dp[i][t], (i == 0 ? 0 : dp[i-1][j])+ (cnt[t ^ tmp] + (cnt[nst]&1)) * (1 << (i)));
                        }
                    }
                }
            }
        if (dp[m-1][0] >= inf) pf("impossible\n");
        else pf("%d\n", dp[m-1][0]);
    }
    return 0;
}
