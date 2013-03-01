/*
 * Author:  Troy
 * Created Time:  2013/1/20 21:31:34
 * File Name: c.cpp
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
const ll inf = 1LL<<60;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, q, pw;
int c[Maxn], v[Maxn];
ll ans;

ll t[Maxn*30];
inline ll MAX(ll x, ll y) {
    return x > y ? x : y;
}
void update(int p) {
    t[p] = MAX(t[p<<1], t[p<<1|1]);
}
void init() {
    pw = 1;
    while (pw <= n+3) pw <<=1;
    FOR(i, 1, n+1) t[i+pw] = -inf;
    for (int i = pw-1; i; --i) update(i);
}
void modify(int p, ll val) {
    p += pw;
    t[p] = MAX(t[p], val);
    for (p >>=1; p ; p>>=1) update(p);
}
ll query(int l, int r) {
    ll ret = -inf;
    for (l += pw-1, r += pw+1; l^r^1; l>>=1, r>>=1) {
        if (~l & 1) ret = MAX(ret, t[l^1]);
        if (r & 1) ret = MAX(ret, t[r^1]);
    }
    return ret;
}
ll solve(ll a, ll b) {
    ans = 0;
    init();
    ll tmp, tmp2;
    FOR(i, 1, n+1) {
        tmp = MAX(MAX(query(1, c[i]-1), query(c[i]+1, n))+1LL*b*v[i], 1LL*b*v[i]);
        tmp2 = (t[c[i]+pw] != -inf) ? t[c[i]+pw]+1LL*a*v[i] : -inf;
        if (tmp > tmp2) {
            modify(c[i], tmp);
        }
        else if (t[c[i]+pw] != -inf) {
            modify(c[i], t[c[i]+pw]+1LL*a*v[i]);
        }
        ans = MAX(ans, t[c[i]+pw]);
    }
    return ans;
}
int main() {
    //freopen("c.in", "r", stdin);
    //freopen("my.out", "w", stdout);
    sf("%d%d", &n, &q);
    FOR(i, 1,n+1) sf("%d", &v[i]);
    FOR(i, 1,n+1) sf("%d", &c[i]);
    int a, b;
    while (q--) {
        sf("%d%d", &a, &b);
        //pf("%I64d\n", solve(a, b));
        cout <<solve(a, b) <<endl;
    }
    return 0;
}

