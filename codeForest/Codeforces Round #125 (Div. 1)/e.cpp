/*
 * Author:  Troy
 * Created Time:  2012/6/23 0:55:49
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
#define Maxn 251000
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const int maxm = 250010*3;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int mx[maxm], le[maxm], ri[maxm];
void build(int p, int l, int r)
{
    le[p] = l; ri[p] = r;
    if (l == r)
    {
        mx[p] = 0;
        return;
    }
    int mid = (l + r) >>1;
    build(p<<1, l, mid);
    build(p<<1|1, mid+1, r);
    mx[p] = max(mx[p<<1], mx[p<<1|1]);    
}

void insert(int p, int l, int val)
{
    if (le[p] == ri[p])
    {
        mx[p] = max(mx[p], val);
        return;
    }
    int mid = (le[p] + ri[p]) >>1;
    if (l <= mid) build(p<<1, l, val);
    else build(p<<1|1, l, val);
    mx[p] = max(mx[p<<1], mx[p<<1|1]);
}

int query(int p, int l, int r)
{
    if (l <= le[p] && ri[p] <= r) return mx[p];
    int ret = 0, mid = (le[p] + ri[p]) >>1;
    if (l <= mid) ret = max(ret, query(p<<1, l, r));
    if (r > mid) ret = max(ret, query(p<<1|1, l, r));
    return ret;
}

int n, tot;
long long r0, p0, x0, yy;
struct Tnode
{
    long long x, y, m, r, pp, dis;
}d[Maxn];
long long b[Maxn];
bool cmp(const Tnode a, const Tnode c)
{
    if (a.dis != c.dis) return a.dis < c.dis;
    else return a.m < c.m;
}
int main() 
{
    ios::sync_with_stdio(false);
    cin >>x0 >>yy >>p0 >>r0 >>n;
    b[1] = r0*r0;
    tot = 2;
    REP(i, n)
    {
        cin >>d[i].x >>d[i].y >>d[i].m >>d[i].pp >>d[i].r;
        d[i].dis = (d[i].x - x0) * (d[i].x - x0) + (d[i].y - yy) * (d[i].y - yy);
        b[tot++] = d[i].r * d[i].r;
    }
    sort(d, d+n, cmp);
    build(1, 1, tot);
    insert(1, 1, p0);
    sort(b+1, b+1+tot);
    
    int ans = 0;
    REP(i, n)
    {
        //if (d[i].dis > )
        int pid = lower_bound(b+1, b+1+tot, d[i].r) - b;
        int tmp = query(1, pid, tot);
        if (tmp < d[i].m) continue;
        else
        {
            ans++;
            insert(1, pid, d[i].pp);
        }
    }
    cout <<ans <<endl;
    
    
    
    return 0;
}

