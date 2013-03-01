/*
 * Author:  Troy
 * Created Time:  2012/11/12 0:14:40
 * File Name: e.cpp
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

int n, m;
int a[Maxn], sum[Maxn*4][22], mark[Maxn*4][22];
int le[Maxn*4], ri[Maxn*4];
long long two[25];
void push_up(int p) {
    REP(i, 21)
        sum[p][i] = sum[p<<1][i] + sum[p<<1|1][i];
}

void build(int p, int l, int r) {
    le[p] = l; ri[p] = r;
    if (l == r) {
        //cout <<l <<" "<<r <<" "<<a[l] <<" : " <<endl;
        REP(i, 21) {
            if (a[l]&1) sum[p][i] = 1;
            else sum[p][i] = 0;
            a[l] >>=1;
        }
        //REP(i, 21) cout <<sum[p][i] <<" ";
        //cout <<endl;
        return;
    }
    int mid = (l + r) >>1;
    build(p<<1, l, mid);
    build(p<<1|1, mid+1, r);
    push_up(p);
}
void push_down(int p, int i) {
    int lson = (p<<1), rson = (p<<1|1);
    sum[lson][i] = ri[lson] - le[lson] + 1 - sum[lson][i];
    mark[lson][i] ^= 1;
    sum[rson][i] = ri[rson] - le[rson] + 1 - sum[rson][i];
    mark[rson][i] ^= 1;
    mark[p][i] = 0;
}
void modify(int p, int l, int r, int x) {
    if (l <= le[p] && ri[p] <= r) {
        int tmp = x;
        REP(i, 21) {
            if (tmp&1) {
                mark[p][i] ^= 1;
                sum[p][i] = ri[p] - le[p] + 1 - sum[p][i];
            }
            tmp >>=1;
        }
        return;
    }
    REP(i, 21)
        if (mark[p][i]) push_down(p, i);
    int mid = (le[p] + ri[p]) >>1;
    if (l <= mid) modify(p<<1, l, r, x);
    if (r > mid) modify(p<<1|1, l, r, x);
    push_up(p);
}
long long query(int p, int l, int r) {
    long long ret = 0;
    if (l <= le[p] && ri[p] <= r) {
        REP(i, 21)
            ret += two[i] * sum[p][i];
        //cout <<le[p] <<" "<<ri[p] <<" "<<ret <<endl;
        return ret;
    }
    REP(i, 21)
        if (mark[p][i]) push_down(p, i);
    int mid = (le[p] + ri[p]) >>1;
    if (l <= mid) ret += query(p<<1, l, r);
    if (r > mid) ret += query(p<<1|1, l, r);
    return ret;
}
int main() {
    sf("%d", &n);
    for (int i = 1; i <= n; i++) sf("%d", &a[i]);
    memset(sum, 0, sizeof(sum));
    memset(mark, 0, sizeof(mark));
    two[0] = 1;
    for (int i = 1; i <= 21; i++) two[i] = two[i-1] * 2;
    build(1, 1, n);
    sf("%d", &m);
    int op, l, r, x;
    long long ans;
    while (m--) {
        sf("%d", &op);
        if (op == 1) {
            sf("%d%d", &l, &r);
            ans = query(1, l, r);
            pf("%I64d\n", ans);
        }
        else {
            sf("%d%d%d", &l, &r, &x);
            modify(1, l, r, x);
        }
    }
    return 0;
}

