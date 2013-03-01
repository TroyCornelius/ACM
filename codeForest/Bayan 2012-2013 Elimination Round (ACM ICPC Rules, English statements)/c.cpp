/*
 * Author:  Troy
 * Created Time:  2012/11/1 23:45:12
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
#define ll long long
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
//const double eps = 1e-1;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

const double eps = 0.082;
double delta = 0.000065;
int n, m;
double hl, hr;
struct glass {
    double x1, x2, y;
    int val, id;
    glass() {}
    glass(int _val, double _x1, double _x2, double _y, int _id)
    :val(_val), x1(_x1), x2(_x2), y(_y), id(_id) {}
}g[110][2];
int tot[2];

struct Point{double x,y;};

Point symmetric_point(Point p1, Point l1, Point l2){
    Point ret;
    if (l1.x > l2.x - eps && l1.x < l2.x + eps){
        ret.x = (2 * l1.x - p1.x);
        ret.y = p1.y;
    }
    else{
        double k = (l1.y - l2.y ) / (l1.x - l2.x);
        ret.x = (2*k*k*l1.x + 2*k*p1.y - 2*k*l1.y - k*k*p1.x + p1.x) / (1 + k*k);
        ret.y = p1.y - (ret.x - p1.x ) / k;
    }
    return ret;
}

void get_line(const Point &x, const Point &y, double &a, double &b, double &cc) {
    a = y.y - x.y;
    b = x.x - y.x;
    cc = y.x * x.y - x.x * y.y;
}

inline bool is_equal(double nx, double x) {
    return fabs(nx - x) < eps;
}
inline bool is_between(double nx, glass &tmp) {
    return (nx > tmp.x1 && nx < tmp.x2) || (is_equal(nx, tmp.x1)) || (is_equal(nx, tmp.x2));
}
bool vis[110];
int calc(double k) {
    memset(vis, false, sizeof(vis));
    int ret = 0;
    double nx;
    int p, p1 = 0, p2 = 0;
    if (k > 0) {
        p = 0;
        nx = (100.0 - hl) / k;
    }
    else {
        p = 1;
        nx = -hl / k;
    }
    
    bool flag;
    double nb = -1000000000.0;
    while (true) {
        if (p == 0) {
            flag = false;
            while (p1 < tot[0]) {
                if (is_between(nx, g[p1][0])) {
                    vis[g[p1][0].id] = true;
                    ret += g[p1][0].val;
                    flag = true;
                    k *= -1.0;
                    nb = 100.0 - nx*k;
                    nx = -nb / k;
                    p1++;
                    break;
                }
                else p1++;
            }
            if (flag) {
                p = 1;
            }
            else break;
        }
        else {
            flag = true;
            while (p2 < tot[1]) {
                if (is_between(nx, g[p2][1])) {
                    vis[g[p2][1].id] = true;
                    ret += g[p2][1].val;
                    flag = true;
                    k *= -1.0;
                    nb = -k*nx;
                    nx = (100.0-nb) / k;
                    p2++;
                    break;
                }
                else p2++;
            }
            if (flag) {
                p = 0;
            }
            else break;
        }
    }
    double ny;
    //cout <<ret <<" ";
    ny = k * 100000.0 + nb;
    if (ret == 1605) {
        cout <<ret<<" "<<ny <<" "<<hr <<endl;
    }
    if (!is_equal(ny, hr)) ret = 0;
    //cout <<ret <<" "<<ny <<endl;
    return ret;
}

int main() {
    while (~sf("%lf%lf%d", &hl, &hr, &n)) {
        tot[0] = tot[1] = 0;
        int v;
        char str[3];
        double x1, x2;
        REP(i, n) {
            sf("%d%s%lf%lf", &v, str, &x1, &x2);
            if (x1 > x2) swap(x1, x2);
            if (str[0] == 'T') {
                g[tot[0]++][0] = glass(v, x1, x2, 100.0, i);
            }
            else {
                g[tot[1]++][1] = glass(v, x1, x2, 0.0, i);
            }
        }
        
        int ans = 0, tmp;
        
        for (double ang = delta; ang < 90.0; ang += delta) {
            double k = tan(ang/180.0*pi);
            tmp = calc(k);
            ans = max(ans, tmp);
            tmp = calc(-k);
            ans = max(ans, tmp);
        }
        pf("%d\n", ans);
    }
    return 0;
}

