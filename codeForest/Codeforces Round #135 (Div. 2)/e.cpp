/*
 * Author:  Troy
 * Created Time:  2012/8/28 0:34:43
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
#define sf scanf
#define pf printf
#define Maxn 600100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m;
int le[Maxn], ri[Maxn], sl[Maxn], sr[Maxn], sm[Maxn];
int mxlen[Maxn];
int park[Maxn*4];
void build(int p, int l, int r) {
    le[p] = l, ri[p] = r;
    sl[p] = sr[p] = sm[p] = mxlen[p] = r - l + 1;
    if (l == r) return;
    int mid = (l + r) >>1;
    build(p<<1, l, mid);
    build(p<<1|1, mid+1, r);
}
void update(int p) {
    int lson = (p<<1), rson = (p<<1|1);
    sl[p] = sl[lson], sr[p] = sr[rson];
    if (sl[lson] == ri[lson] - le[lson] + 1) sl[p] += sl[rson];
    if (sr[rson] == ri[rson] - le[rson] + 1) sr[p] += sr[lson];
    sm[p] = max(sm[lson], sm[rson]);
    sm[p] = max(sm[p], sr[lson] + sl[rson]);
    mxlen[p] = max(sl[p], max(sr[p], sm[p]));
    return;
}
void modify(int p, int pos, int op) {
    if (le[p] == ri[p]) {
        sl[p] = sm[p] = sr[p] = mxlen[p] = op;
        return;
    }
    int mid = (le[p] + ri[p]) >>1;
    if (pos <= mid) modify(p<<1, pos, op);
    else modify(p<<1|1, pos, op);
    update(p);
}
int query(int p, int tar) {
    if (le[p] == ri[p]) return le[p];
    if (le[p] == 1 && sl[p] >= tar) return 1;
    int lson = (p<<1), rson = (p<<1|1), mid = (le[p] + ri[p])>>1;
    if (mxlen[lson] + 1 >= tar * 2) return query(lson, tar);
    if (sr[lson] + sl[rson] + 1>= tar * 2) return (mid - sr[lson] + tar);
    return query(rson, tar);
}
int main() 
{
    sf("%d%d", &n, &m);
    build(1, 1, n);
    int op, tid;
    memset(park, 0, sizeof(park));
    while (m--) {
        sf("%d%d", &op, &tid);
        if (op == 1) {
            int mx = (mxlen[1]+1)/2;
            mx = max(mx, max(sl[1], sr[1]));
            int pos = query(1, mx);
            park[tid] = pos;
            modify(1, pos, 0);
            pf("%d\n", pos);
        }
        else {
            int pos = park[tid];
            modify(1, pos, 1);
        }
    
    }
    return 0;
}

