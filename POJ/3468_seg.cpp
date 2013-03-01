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
#define Maxn 100100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<long long,long long> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m, num[Maxn];
long long tree[Maxn*4][2];

int pw;

void build() {
    memset(tree, 0, sizeof(tree));
    pw = 1;
    while (pw <= n+3) pw <<= 1;  //zkw segment tree only can query [1...2^n-2]
}

void modify(int p, int x, long long val) {
    for (x += pw; x; x >>=1) {
        tree[x][p] += val;
    }
}

long long query(int s, int t, int p) {
    long long ret = 0;
    for (s=s+pw-1, t=t+pw+1; s^t^1 ;s>>=1, t>>=1) {
        if (~s&1) ret += tree[s^1][p];
        if (t&1) ret += tree[t^1][p];
    }
    return ret;
}

int main() {
    num[0] = 0;
    int a, b, x;
    char op[3];
    while (~sf("%d%d", &n, &m)) {
        FOR(i, 1, n+1) sf("%d", &num[i]);
        build();
        FOR(i, 1, n+1) {
            modify(0, i, num[i]-num[i-1]);
            modify(1, i, 1LL*i*(num[i]-num[i-1]));
        }
        while (m--) {
            sf("%s%d%d", op, &a, &b);
            if (op[0] == 'Q') {
                long long ans = query(0, a, b) * (b-a+1) - query(1, a, b);
                pf("%I64d\n", ans);
            }
            else {
                sf("%d", &x);
                modify(0, a, x); if (b+1<n) modify(0, b+1, -x);
                modify(1, a, a*x); if (b+1<n) modify(1, b+1, -1LL*(b+1)*x);
            }
        }
    }
    return 0;
}

