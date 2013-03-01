/*
 * Author:  Troy
 * Created Time:  2012/3/30 18:50:19
 * File Name: a.cpp
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
#include <cctype>


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
typedef pair<double,double> pdd;

int n;
pdd d[Maxn];
double ans, m;
bool cmp(const pdd &a, const pdd &b)
{
    return (a.fi * b.se) > (a.se * b.fi);
}
int main() 
{
    while (~sf("%lf%d", &m, &n))
    {
        if (m == -1) break;
        REP(i, n) sf("%lf%lf", &d[i].fi, &d[i].se);
        ans = 0;
        sort(d, d+n, cmp);
        REP(i, n)
        {
            if (m <= 0.0) break;
            if (m >= d[i].se)
            {
                ans += d[i].fi;
                m -= d[i].se;
            }
            else
            {
                ans += d[i].fi * (m / d[i].se);
                m = 0.0;
            }
        }
        pf("%.3f\n", ans);
    }
    return 0;
}

