/*
 * Author:  Troy
 * Created Time:  2012/7/14 21:43:27
 * File Name: h.cpp
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
typedef pair<double, double> pdd;

int n, m;
pdd a[110], b[110];

inline double calc(pdd p1, pdd p2)
{
    return (p1.fi - p2.fi) * (p1.fi - p2.fi) + (p1.se -p2.se)*(p1.se - p2.se);
}

inline double get_area(pdd p, pdd p1, pdd p2)
{
    
}
double mul_det(pdd p, pdd q, pdd o)
{
    return (p.fi - o.fi) * (q.fi - o.fi) + (p.se - o.se) * (q.se - o.se);
}
double dist(pdd p, pdd p1, pdd p2)
{
    double ret = calc(p, p1);
    ret = min(ret, calc(p, p2));
    
    if (mul_det(p, p1, p2) < eps || (mul_det(p, p2, p1) < eps)) return sqrt(ret);
    
    //double area = get_area(p, p1, p2);
    //double ta = p1.se - p2.se;
    //double tb = p2.fi - p1.fi;
    //double tc = p1.fi * p2.se - p2.fi * p1.se;
    //double tmp = fabs((ta * p.fi + tb * p.se + tc) / sqrt(ta * ta + tb * tb));
    //ret = min(ret, tmp);
    double area = (p1.fi - p.fi) * (p2.se - p1.se) - (p1.se - p.se) * (p2.fi - p1.fi);
    //area /= 2.0;
    area = fabs(area) / sqrt(calc(p1, p2));
    return area;
}

int main() 
{
    int T;
    sf("%d", &T);
    while (T--)
    {
        sf("%d", &n);
        REP(i, n) sf("%lf%lf", &a[i].fi, &a[i].se);
        sf("%d", &m);
        REP(i, m) sf("%lf%lf", &b[i].fi, &b[i].se);
        
        double ans = 1e100;
        a[n] = a[0]; b[m] = b[0];
        REP(i, n)
            REP(j, m)
            {
                ans = min(ans, dist(a[i], b[j], b[j+1]));
                ans = min(ans, dist(b[j], a[i], a[i+1]));
            }
        pf("%.8f\n", ans / 2.0);
    }
    return 0;
}

