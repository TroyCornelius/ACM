/*
 * Author:  Troy
 * Created Time:  2012/2/9 11:54:16
 * File Name: Task_Scheduling.cpp
 */

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define aleft(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define REP(i,b) FOR(i,0,b)
#define Maxn 100100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, ovs[Maxn], ans[Maxn], id[Maxn];
int mark[Maxn*4], ms[Maxn*4];
int left[Maxn*4], rr[Maxn*4];
pair<pii, int> d[Maxn];

void updata(int p)
{
    ms[p] = max(ms[p<<1], ms[p<<1|1]);
}
void build(int p, int le, int ri)
{
    mark[p] = 0;
    left[p] = le; rr[p] = ri;
    if (le == ri)
    {
        ms[p] = ovs[le];
        return;
    }
    int mid = (le + ri) >>1;
    build(p<<1, le, mid);
    build(p<<1|1, mid+1, ri);
    updata(p);
}
void pushdown(int p)
{
    if (!mark[p]) return;
    ms[p<<1] += mark[p], ms[p<<1|1] += mark[p];
    mark[p<<1] += mark[p], mark[p<<1|1] += mark[p];
    mark[p] = 0;
    return;
}
void change(int p, int le, int ri, int val)
{
    if (le <= left[p] && rr[p] <= ri)
    {
        ms[p] += val; mark[p] += val;
        return;
    }
    pushdown(p);
    int mid = (left[p] + rr[p]) >>1;
    if (le <= mid) change(p<<1, le, ri, val);
    if (ri > mid) change(p<<1|1, le, ri, val);
    updata(p);
}
bool cmp(pair<pii, int> a, pair<pii, int> b)
{
    return (a.fi.fi < b.fi.fi) ||(a.fi.fi == b.fi.fi && a.se < b.se);
}
int main() 
{
    while (~scanf("%d", &n))
    {
        REP(i, n)
        {
            scanf("%d%d", &d[i].fi.fi, &d[i].fi.se);
            d[i].se = i;
        }
        sort(d, d+n, cmp);   
        int tot_ti = 0;
        REP(i, n)
        {
            id[d[i].se] = i;
            tot_ti += d[i].fi.se;
            ovs[i] = tot_ti - d[i].fi.fi;
        }
        build(1, 0, n-1);
        for (int i=n-1; i>=0; i--)
        {
            ans[i] = ms[1];
            change(1, id[i], n-1, -d[id[i]].fi.se);
        }
        REP(i, n) printf("%d\n", max(0,ans[i]));
        
    }
    
    return 0;
}

