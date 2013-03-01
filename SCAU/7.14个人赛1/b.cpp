/*
 * Author:  Troy
 * Created Time:  2012/7/14 13:56:01
 * File Name: b.cpp
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

#define PRECISION  1e-8
#define N 1010
int n, m;
typedef struct _POINT
{
    double x, y;
} POINT;
POINT plist[N];
POINT ch[N]; 
POINT pp[N];
double cross_det(const POINT &o, const POINT &a, const POINT &b) {
    return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
}
int cmpzero(double d) {
    return (fabs(d) < PRECISION) ? 0 : (d > 0 ? 1 : -1);
}
inline double sqr(double x) {
    return x * x;
}
bool cmp_angle(const POINT &p1, const POINT &p2) {
    return cross_det(plist[0], p1, p2) > 0;
}
double pt_distance(const POINT &p1, const POINT &p2) {
    return sqrt(sqr(p1.x - p2.x) + sqr(p1.y - p2.y));
}
inline bool farer(const POINT &p1, const POINT &p2)
{
    return pt_distance(p1, plist[0]) > pt_distance(p2, plist[0]);
}
void remove_point()
{
    int idx = 1;
    for (int i = 2; i < n; ++i) {
        if (cmpzero(cross_det(plist[0], plist[i], plist[idx])))
            plist[++idx] = plist[i];
        else if (farer(plist[i], plist[idx]))
            plist[idx] = plist[i];
    }
    n = idx + 1;
}
int graham_scan()
{
    int top;
    for (int i = 1; i < n; i++)
        if (plist[i].y < plist[0].y || (plist[i].y == plist[0].y && plist[i].x
                    < plist[0].x))
            swap(plist[i], plist[0]);
    sort(plist + 1, plist + n, cmp_angle);
    remove_point();
    ch[0] = plist[0];
    ch[1] = plist[1];
    ch[2] = plist[2];
    top = 2;
    for (int i = 3; i < n; ++i) {
        while (!(cross_det(ch[top - 1], plist[i], ch[top]) < 0))
            --top;
        ch[++top] = plist[i];
    }
    return top;
}
bool onsegment(POINT a, POINT b, POINT c)
{
    if (fabs(cross_det(a,b,c)) < eps && ((c.x >= a.x && c.x <= b.x) || (c.x >= b.x && c.x <= a.x))) return true;
    else return false;    
}
bool check()
{
    if (n <= 5) return false;
    int nn = graham_scan();
    ch[++nn] = ch[0];
    REP(i, nn)
    {
        int cnt = 0;
        REP(j, m)
        {
            if (onsegment(ch[i], ch[i+1], pp[j])) cnt++;
        }
        if (cnt < 3) return false;
    }
    return true;
}
int main() 
{
    int T;
    sf("%d", &T);
    while (T--)
    {
        sf("%d", &n);
        m = n;
        REP(i, n){
            sf("%lf%lf", &plist[i].x, &plist[i].y);
            pp[i] = plist[i];
        }
        bool ans = check();
        if (ans) pf("YES\n");
        else pf("NO\n");
    }
    return 0;
}

