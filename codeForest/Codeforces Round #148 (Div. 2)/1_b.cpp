/*
 * Author:  Troy
 * Created Time:  2012/11/5 22:50:54
 * File Name: 1_b.cpp
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
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

struct Tnode {
    int id, num, group;
}d[Maxn];
int n, h;

bool cmp1(const Tnode &a, const Tnode &b) {
    return a.num < b.num;
}
bool cmp2(const Tnode &a, const Tnode &b) {
    return a.id < b.id;
}
int main() {
    sf("%d%d", &n, &h);
    REP(i, n) {
        sf("%d", &d[i].num);
        d[i].id = i;
        d[i].group = 1;
    }
    sort(d, d+n, cmp1);
    int mx = d[n-1].num + d[n-2].num;
    int mi = d[0].num + d[1].num;
    int ans = mx - mi;
    if (n == 2) {
        pf("%d\n", ans);
        puts("1 1");
    }
    else {
        mx = max(mx, d[0].num + d[n-1].num + h);
        mi = min(d[1].num + d[2].num, d[0].num  + d[1].num + h);
        if (mx - mi < ans) {
            ans = mx - mi;
            d[0].group = 2;
        }
        sort(d, d+n, cmp2);
        pf("%d\n", ans);
        REP(i, n)
            pf("%d%c", d[i].group, i == n-1 ? '\n' :' ');
    }
    
    return 0;
}

