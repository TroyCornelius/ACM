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
#define Maxn 1110
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
double f[Maxn];
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
    int T, now;
    sf("%d", &T);
    while (T--)
    {
        sf("%d", &n);
        REP(i, n) sf("%lf%lf", &ship[i].fi, &ship[i].se);
        cap = ship[0];
        sort(ship, ship + n);
        ans1 = ans2 = 0;
        st = get_cap();
        
        REP(i, n) f[i] = -inf;
        f[0] = cap.fi - cap.se / 2.0;
        FORD(i, st-1, 0)
        {
        //REP(j, n) pf("%.2f ", f[j][now]);//cout <<f[j][now] <<" ";
        //cout <<endl;
            FORD(j, n, 1)
                if (f[j-1] != -inf && f[j-1] >= ship[i].fi)
                {
                    double tmp = calc(ship[i], f[j-1], 0);
                    f[j] = max(f[j], tmp);
                    ans1 = max(ans1, j);
                }
            //cout <<i <<" "<<ans1 <<" "<<ship[i].fi <<endl;
        //REP(j, n) pf("%.2f ", f[j][now]);//cout <<f[j][now] <<" ";
        //cout <<endl;
        }
        //REP(j, n) pf("%.2f ", f[j][now]);//cout <<f[j][now] <<" ";
        //cout <<endl;
        
        REP(i, n) f[i] = inf;
        f[0] = cap.fi + cap.se / 2.0;
        FOR(i, st+1, n)
        {
            FORD(j, n, 1)
                if (f[j-1] != inf && f[j-1] <= ship[i].fi)
                {
                    double tmp = calc(ship[i], f[j-1], 1);
                    f[j] = min(f[j], tmp);
                    ans2 = max(ans2, j);
                }
           
        }
        //cout <<ans1 <<" "<<ans2 <<" "<<cap.fi <<" "<<cap.se <<endl;
        pf("%d\n", ans1 + ans2 + 1);
        
    }
    return 0;
}

