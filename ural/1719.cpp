/*
 * Author:  Troy
 * Created Time:  2012/9/24 21:33:47
 * File Name: 1719.cpp
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
#define zero(x) (((x)>0?(x):-(x))<eps) 
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

struct Point {double x,y;}p[5];
struct Line {
    Point a, b;
    Line() {}
    Line(Point _x, Point _y)
    :a(_x), b(_y) {}
};
double ans;
int d[5];
Point O;

inline double get_dis(Point a, Point b) {
    double tx = a.x - b.x, ty = a.y - b.y;
    return sqrt(tx*tx + ty*ty);
}

inline double xmult(Point p1,Point p2,Point p0){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

int same_side(Point p1,Point p2,Line l){
    return xmult(l.a,p1,l.b)*xmult(l.a,p2,l.b)>eps;
}
int dots_inline(Point p1,Point p2,Point p3){
    return zero(xmult(p1,p2,p3));
}

int dot_online_in(Point p,Line l){
    return zero(xmult(p,l.a,l.b))&&(l.a.x-p.x)*(l.b.x-p.x)<eps&&(l.a.y-p.y)*(l.b.y-p.y)<eps;
}

int intersect_in(Line u,Line v){
    if (!dots_inline(u.a,u.b,v.a)||!dots_inline(u.a,u.b,v.b))
        return !same_side(u.a,u.b,v)&&!same_side(v.a,v.b,u);
    return dot_online_in(u.a,v)||dot_online_in(u.b,v)||dot_online_in(v.a,u)||dot_online_in(v.b,u);
}

Point intersection(Point u1,Point u2,Point v1,Point v2){
    Point ret=u1;
    double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))
             /((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
    ret.x+=(u2.x-u1.x)*t;
    ret.y+=(u2.y-u1.y)*t;
    return ret;
}


double gao() {
    Line L1(p[d[0]], p[d[1]]);
    Line L2(p[d[2]], p[d[3]]);
    
    if (intersect_in(L1, L2)) {
        Point tmp = (intersection(L1.a, L1.b, L2.a, L2.b));
        ans = min(ans, get_len(O, tmp));
    }
    
    
}
int main() {
    while (~sf("%lf%lf", &p[0].x, p[0].y)) {
        FOR(i, 1, 4) sf("%lf%lf", &p[i].x, &p[i].y);
        ans = 1e100;
        O.x = O.y = 0;
        REP(i, 4) d[i] = i;
        do {
        
        
        }while (next_permutation(d, d+4));
        pf("%.6f\n", ans);
    }
    return 0;
}

