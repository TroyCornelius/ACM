/*
 * Author:  Troy
 * Created Time:  2012/9/4 20:28:02
 * File Name: 3468_seg.cpp
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
typedef pair<long long,long long> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
int n, m, num[Maxn];
int sz[Maxn*3];
long long sum[Maxn*3], add[Maxn*3];
int pw;
void build() {
    pw = 1;
    memset(add, 0, sizeof(add));
    while (pw <= n+3) pw <<= 1;  //zkw segment tree only can query [1...2^n-2]
    for (int i =1; i<=n; ++i) sz[i+pw] = 1, sum[i+pw] = num[i];
    for (int i = pw; i; --i) {
        sz[i] = sz[i<<1] + sz[i<<1|1];
        sum[i] = sum[i<<1] + sum[i<<1|1];
    }
}
void modify(int s, int t, long long val) {
    int sz_l = 0, sz_r = 0;
    for (s=s+pw-1, t=t+pw+1; s^t^1; ) {
        if (~s&1) sum[s^1] += sz[s^1]*val, sz_l += sz[s^1], add[s^1] += val; 
        if (t&1) sum[t^1] += sz[t^1]*val, sz_r += sz[t^1], add[t^1] += val;
        s >>=1; t >>=1;
        sum[s] += sz_l * val;
        sum[t] += sz_r * val;
    }
    sz_l += sz_r;
    for (s>>=1; s; s>>=1) sum[s] += sz_l * val;
}
long long query(int s, int t) {
    long long ret = 0;
    int sz_l = 0, sz_r = 0;
    for (s=s+pw-1, t=t+pw+1; s^t^1 ;) {
        if (~s&1) ret += sum[s^1], sz_l += sz[s^1];
        if (t&1) ret += sum[t^1], sz_r += sz[t^1];
        s >>=1; t >>=1;
        ret += sz_l * add[s];
        ret += sz_r * add[t];
    }
    sz_l += sz_r;
    for (s>>=1; s; s>>=1) ret += sz_l * add[s];
    return ret;
}
int main() {
    int a, b, x;
    char op[3];
    while (~sf("%d%d", &n, &m)) {
        FOR(i, 1, n+1) sf("%d", &num[i]);
        build();
        while (m--) {
            sf("%s%d%d", op, &a, &b);
            if (op[0] == 'Q') {
                long long ans = query(a, b);
                pf("%I64d\n", ans);
            }
            else {
                sf("%d", &x);
                modify(a, b, x);
            }
        }
    }
    return 0;
}
