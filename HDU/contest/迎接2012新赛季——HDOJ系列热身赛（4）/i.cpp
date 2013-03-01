/*
 * Author:  Troy
 * Created Time:  2012/4/3 14:45:01
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
#define Maxn 1010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const double inf = 1000000010.0;
typedef pair<int, double> pid;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, st, ans1, ans2;
pdd ship[Maxn], cap;
pid dp[Maxn];
inline int get_cap()
{
    REP(i, n)
        if (ship[i] == cap) return i;
}
inline double calc(pdd s, double x, int pat)
{
    if (pat == 0)
    {
        if (s.fi + s.se <= x) return s.fi;
        else return x - s.se;
    }
    else
    {
        if (x <= s.fi - s.se) return s.fi;
        else return x + s.se;
    }
}
int main() 
{
    int T;
    sf("%d", &T);
    while (T--)
    {
        sf("%d", &n);
        REP(i, n) sf("%lf%lf", &ship[i].fi, &ship[i].se);
        cap = ship[0];
        sort(ship, ship + n);
        ans1 = ans2 = 0;
        st = get_cap();
        REP(i, st) dp[i] = mp(0, -inf);
        FOR(i, st+1, n) dp[i] = mp(0, inf);
        
        dp[st] = mp(0, cap.fi - cap.se / 2.0);
        FORD(i, st-1, 0)
        {
            FOR(j, i+1, st+1)
            if (dp[j].se >= ship[i].fi)
            {
                if (dp[i].fi < dp[j].fi + 1)
                {
                    dp[i].fi = dp[j].fi + 1;
                    ans1 = max(ans1, dp[i].fi);
                    dp[i].se = calc(ship[i], dp[j].se, 0);
                }
                else
                if (dp[i].fi == dp[j].fi + 1)
                {
                    dp[i].se = max(dp[i].se, calc(ship[i], dp[j].se, 0));
                }
            }
        }
        cout <<dp[st-2].fi <<" "<<dp[st-2].se <<endl;
        dp[st] = mp(0, cap.fi + cap.se / 2.0);
        FOR(i, st+1, n)
        {
            FORD(j, i-1, st)
            if (dp[j].se <= ship[i].fi)
            {
                if (dp[j].fi + 1 > dp[i].fi)
                {
                    dp[i].fi = dp[j].fi + 1;
                    ans2 = max(ans2, dp[i].fi);
                    dp[i].se = calc(ship[i], dp[j].se, 1);
                }
                else
                if (dp[j].fi + 1 == dp[i].fi)
                {
                    dp[j].se = min(dp[j].se, calc(ship[i], dp[j].se, 1));
                }
            }
        }
        //cout <<ans1 <<" "<<ans2 <<" "<<cap.fi <<" "<<cap.se <<endl;
        pf("%d\n", ans1 + ans2 + 1);
        
    }
    return 0;
}

