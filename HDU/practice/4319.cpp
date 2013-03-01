/*
 * Author:  Troy
 * Created Time:  2012/8/20 13:24:52
 * File Name: 4319.cpp
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
#define Maxn 100010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, a[Maxn];
struct Point{int x,y;} pt[Maxn], up[2][Maxn], low[2][Maxn];
Point mm[Maxn+Maxn];
int stk[Maxn];

inline bool check(int x1, int y1, int x2, int y2, bool is_up) {
    if (is_up) return 1LL*x1*y2 > 1LL*x2*y1;
    else return 1LL*x1*y2 < 1LL*x2*y1;
}
//凸包维护上凸或者下凸
int get_bound(Point *pt, int len, Point *out, bool is_up) {
    if (len <= 0) return 0;
    if (len == 1) {out[0] = pt[0]; return 1;}
    stk[0] = 0; stk[1] = 1;
    int top = 2;
    for (int i = 2; i < len; ++i) {
        while (top >= 2 && check(pt[stk[top-1]].x - pt[stk[top-2]].x,
                    pt[stk[top-1]].y - pt[stk[top-2]].y,
                    pt[i].x - pt[stk[top-1]].x,
                    pt[i].y - pt[stk[top-1]].y, is_up)) --top;
        stk[top++] = i;
    }
    for (int i = 0; i < top; ++i) out[i] = pt[stk[i]];
    return top;
}

inline Point pt_add(Point a1, Point b1) {
    Point ret = {a1.x+b1.x, a1.y+b1.y};
    return ret;
}
//合并两个凸包
int merge_bound(Point *a0, int len0, Point *a1, int len1, Point *out, bool is_up) {
    int p0 = 1, p1 = 1, now = 0;
    out[now++] = pt_add(a0[0], a1[0]);
    while (p0 < len0 || p1 < len1) {
        if (p0 == len0) {
            out[now++] = pt_add(a0[p0-1], a1[p1++]);
            continue;
        }
        if (p1 == len1) {
            out[now++] = pt_add(a0[p0++], a1[p1-1]);
            continue;
        }
        
        Point t0 = pt_add(a0[p0-1], a1[p1-1]);
        Point t1 = pt_add(a0[p0], a1[p1-1]);
        Point t2 = pt_add(a0[p0-1], a1[p1]);
        if (check(t1.x-t0.x, t1.y-t0.y, t2.x-t0.x, t2.y-t0.y, is_up)) {
            out[now++] = t2;
            ++p1;
        }
        else {
            out[now++] = t1;
            ++p0;
        }
    }
    return now;
}

double solve(int l, int r) {
    if (l == r) {
        return abs(a[l]);
    }
    int mid = (l + r) >>1;
    double ans_l = solve(l, mid);
    double ans_r = solve(mid+1, r);
    double ans = max(ans_l, ans_r);
    
    int np = 0, sum = 0;
    for (int i = mid; i >= l; i--) {
        sum += a[i];
        pt[np].x = mid - i + 1;
        pt[np].y = sum;
        np++;
    }
    int len_up0 = get_bound(pt, np, up[0], true);
    int len_low0 = get_bound(pt, np, low[0], false);
    
    np = sum = 0;
    for (int i = mid+1; i <= r; i++) {
        sum += a[i];
        pt[np].x = i - mid;
        pt[np].y = sum;
        ++np;
    }
    int len_up1 = get_bound(pt, np, up[1], true);
    int len_low1 = get_bound(pt, np, low[1], false);
    
    int len0 = merge_bound(up[0], len_up0, up[1], len_up1, mm, true);
    int len1 = merge_bound(low[0], len_low0, low[1], len_low1, mm+len0, false);
    for (int i = 0; i < len0 + len1; ++i) {
        double tmp = (double)abs(mm[i].y) / (sqrt((double)mm[i].x));
        if (tmp > ans) ans = tmp;
    }
    return ans;
}


int main() {
    while (~sf("%d", &n)) {
        REP(i, n) sf("%d", &a[i]);
        double ans = solve(0, n-1);
        pf("%.6f\n", ans*ans);
    }
        
    return 0;
}

