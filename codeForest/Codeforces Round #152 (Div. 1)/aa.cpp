/*
 * Author:  Troy
 * Created Time:  2012/11/26 1:23:04
 * File Name: aa.cpp
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
#define ll long long
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
const int inf = 1 << 29;
const double dinf = 1e30;
const ll linf = 1LL << 55;
const double eps = 1e-8;
double yl, yh, yw, xb, yb, r;

struct Point {
    double x, y;
    Point(){};
    Point(double _x, double _y) {
        x = _x, y = _y;
    }
};
Point getLP(Point p1,Point p2,Point p){
    double A=p2.x-p1.x;
    double B=p2.y-p1.y;
    double C=A*p.x+B*p.y;
    double D=B*p1.x-A*p1.y;
    Point ret;
    ret.x=(B*D+A*C)/(A*A+B*B);
    ret.y=(B*C-A*D)/(A*A+B*B);
    return ret;
}

int main() {
    cin >> yl >> yh >> yw >> xb >> yb >> r;
    yl += r;
    double x = (yw - r - yl) * xb / (2 * yw - 2 * r - yl - yb);
    Point p = getLP(Point(0, yl), Point(x, yw - r), Point(0, yh));
    double dist = sqrt(p.x * p.x + (p.y - yh) * (p.y - yh));
    if(dist + eps < r) {
        puts("-1");
    } 
    else pf("%.11f\n", x);
    return 0;
}

