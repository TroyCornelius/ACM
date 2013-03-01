/*
 * Author:  Troy
 * Created Time:  2012/11/5 1:13:20
 * File Name: d.cpp
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
#define Maxn 100100
using namespace std;
const int inf = 1<<29;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, h;
pii a[Maxn];
int ans[Maxn], num[Maxn];

struct Tnode{
    int c1, c2, p1, p2, st1, st2;
    Tnode() {}
    Tnode(int _c1, int _c2, int _p1, int _p2, int _st1, int _st2)
    :c1(_c1), c2(_c2), p1(_p1), p2(_p2), st1(_st1), st2(_st2) {}
}sch;

void update(int id, int flag) {
    if (flag) ans[id] = 2;
    else ans[id] = 1;
}
int calc(int st) {
    int ret = inf, v;
    int mx = -inf, mi = inf;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++) {
            v = a[i].fi + a[j].fi;
            if (((st>>i)&1) != ((st>>j)&1)) v += h;
            mi = min(mi, v);
            mx = max(mx, v);
        }
    return mx - mi;
}
int main() {
    while (~sf("%d%d", &n, &h)) {
        REP(i, n) {
            sf("%d", &a[i].fi);
            a[i].se = i;
        }
        if (n < 8) {
            int mi = inf, st;
            REP(i, 1<<n) {
                int t = calc(i);
                if (t < mi) {
                    mi = t;
                    st = i;
                }
            } 
            REP(i, n) {
                if ((1<<i)&st) ans[i] = 2;
                else ans[i] = 1;
            }
            pf("%d\n", mi);
            REP(i, n) pf("%d%c", ans[i], i == n-1 ? '\n' : ' ');
        }
        else {
            sort(a, a+n);
            int mi = inf;
            for (int c1 = 0; c1 < 4; c1++)
                for (int c2 = c1+1; c2 < 4; c2++) {
                    for (int st1 = 0; st1 < 4; st1++) {
                        int v1 = a[c1].fi + a[c2].fi;
                        if ((st1&1) != ((st1&2)>>1)) v1 += h;

                        for (int p1 = n-1; p1 >= 4; p1--)
                            for (int p2 = p1-1; p2 >= 4; p2--) {
                                for (int st2 = 0; st2 < 4; st2++) {
                                    int v2 = a[p1].fi + a[p2].fi;
                                    if ((st2&1) != ((st2&2)>>1)) v2 += h;
                                    cout <<v1 <<" "<<v2 <<endl;
                                    if (abs(v1 - v2) < mi) {
                                        mi = abs(v1 - v2);
                                        sch = Tnode(c1, c2, p1, p2, st1, st2);
                                    }
                                }
                            }
                    }
                }
            for (int i = 0; i <= n; i++) ans[i] = 1;
            update(a[sch.c1].se, sch.st1&1);
            update(a[sch.c2].se, ((sch.st1>>1)&1));
            update(a[sch.p1].se, sch.st2&1);
            update(a[sch.p2].se, ((sch.st2>>1)&1));
            pf("%d\n", mi);
            pf("%d", ans[0]);
            for (int i = 1; i < n; i++) pf(" %d", ans[i]);
            puts("");
        }
    }
    return 0;
}

