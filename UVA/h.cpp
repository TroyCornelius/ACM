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
#define Maxn 200100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m;

int le[Maxn*4], ri[Maxn*4];
long long sum[Maxn*4], add[Maxn*4];
long long tsum[Maxn*4];
inline void update(int p) {
    sum[p] = sum[p<<1] + sum[p<<1|1];
    tsum[p] = tsum[p<<1] + tsum[p<<1|1];
}
void build(int p, int l,int r) {
    le[p] = l; ri[p] = r;
    add[p] = 0;
    if (l == r) {
        tsum[p] = 100; 
        sum[p] = 1LL*l*100;
        return;
    }
    int mid = (l + r)>>1;
    build(p<<1, l, mid);
    build(p<<1|1, mid+1, r);
    update(p);
}
void push_down(int p) {
    int lson = p<<1, rson = (p<<1|1);
    sum[lson] += 1LL*add[p]*(le[lson] + ri[lson]) * (ri[lson]-le[lson]+1)/2;               
    tsum[lson] += 1LL*(ri[lson] - le[lson] + 1) * add[p];
    sum[rson] += 1LL*add[p]*(le[rson] + ri[rson]) * (ri[rson]-le[rson]+1)/2;               
    tsum[rson] += 1LL*(ri[rson] - le[rson] + 1) * add[p];
    add[p<<1] += add[p];
    add[p<<1|1] += add[p];
    add[p] = 0;
}
void modify(int p, int l, int r, int val) {
    if (l <= le[p] && ri[p] <= r) {
        add[p] += val;
        sum[p] += 1LL*val*(le[p] + ri[p]) * (ri[p]-le[p]+1)/2;               
        tsum[p] += 1LL*(ri[p] - le[p] + 1) * val;
        return;
    }
    if (add[p] != 0) push_down(p);
    int mid = (le[p] + ri[p])>>1;
    if (l <= mid) modify(p<<1, l, r, val);
    if (r > mid) modify(p<<1|1, l, r, val);
    update(p);
}

long long query(int p, int l, int r, int op) {
    long long ret = 0;
    if (l <= le[p] && ri[p] <= r) {
        if (op == 1) return sum[p] ;
        else return tsum[p];
    }
    if (add[p] != 0) push_down(p);
    int mid = (le[p] + ri[p])>>1;
    if (l <= mid) ret += query(p<<1, l, r, op);
    if (r > mid) ret += query(p<<1|1, l, r, op);
    update(p);
    return ret;
}
long long zy[Maxn];
void add_num(int l, int r, int c) {
    for (int i = l; i <= r; i ++) zy[i] += c;
}
long long solve(int l, int r) {
    long long ret = 0;
    for (int i = l, j = 1; i <= r; i++, j++) ret += zy[i] * j;
    return ret;
}
int main() {
    int T, ca = 0;
    sf("%d", &T);
    while (T--) {
        pf("Case %d:\n", ++ca);
        sf("%d%d", &n, &m);
        build(1, 1, n);
        char cmd[10];
        int a, b, c;
        while (m--) {
            sf("%s", cmd);
            if (cmd[0] == 'q') {
                sf("%d%d", &a, &b);
                long long s1 = query(1, a, b, 1);
                long long s2 = 1LL*(a-1) * query(1, a, b, 0);
                cout <<s1 - s2 <<endl;
            }
            else {
                sf("%d%d%d", &a, &b, &c);
                modify(1, a, b, c);
            }
        }
    }
    return 0;
}
/*
4 11
change 3 4 89
change 3 3 9
query 1 3




*/
