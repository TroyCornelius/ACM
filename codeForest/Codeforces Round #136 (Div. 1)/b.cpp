/*
 * Author:  Troy
 * Created Time:  2012/8/31 23:32:52
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
#define Maxn 100100
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m;
int a[Maxn], ans[Maxn];
struct Query{
    int l, r, id;
    bool operator<(const Query &b) const{
        return r < b.r || (r == b.r && l < b.l);
    }
}q[Maxn];

int t[Maxn];
vi loc[Maxn];
void add(int idx, int val) {
    for (;idx <= n; idx += idx&-idx) t[idx] += val;
}
int query(int idx) {
    int ret = 0;
    for (;idx;idx-=idx&-idx) ret += t[idx];
    return ret;
}

inline int get_sum(int x, int y) {
    return query(y) - query(x-1);
}
 
int main() 
{
    int l, r;
    sf("%d%d", &n, &m);
    memset(t, 0, sizeof(t));
    for (int i = 1; i <= n; ++i) sf("%d", &a[i]);
    REP(i, m) {
        sf("%d%d", &q[i].l, &q[i].r);
        q[i].id = i;
    }
    sort(q, q+m);
    int now = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] <= n) {
            loc[a[i]].pb(i);
            int sz = loc[a[i]].size();
            if (sz >= a[i]) {
                if (sz > a[i]) {
                    add(loc[a[i]][sz - a[i] - 1], -2);
                    if (sz - a[i] - 2 >= 0) add(loc[a[i]][sz-a[i]-2], 1);
                }
                add(loc[a[i]][sz-a[i]], 1);
            }
        }
        if (now >= m) break;
        while (now < m && q[now].r == i) {
            ans[q[now].id] = get_sum(q[now].l, q[now].r);
            now++;
        }
    }
    REP(i, m) pf("%d\n", ans[i]);
    return 0;
}

