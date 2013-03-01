/*
 * Author:  Troy
 * Created Time:  2012/2/23 10:25:02
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
#define Maxn 200000
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
int n, m, c;
int x[Maxn];
double v[Maxn], p[Maxn];
double ans;
double sum[Maxn*5], lm[Maxn*5], rm[Maxn*5], opt[Maxn*5]; 
void updata(int p)
{
    sum[p] = sum[p<<1] + sum[p<<1|1];
    lm[p] = max(lm[p<<1], sum[p<<1] + lm[p<<1|1]);
    rm[p] = max(rm[p<<1|1], sum[p<<1|1] + rm[p<<1]);
    opt[p] = max(opt[p<<1], max(opt[p<<1|1], rm[p<<1] + lm[p<<1|1]));
}
void build(int p, int le, int ri)
{
    if (le == ri)
    {
        sum[p] = v[le];
        lm[p] = rm[p] = opt[p] = max(0.0, v[le]);
        return ;
    }
    int mid = (le + ri) >>1;
    build(p<<1, le, mid);
    build(p<<1|1, mid+1, ri);
    updata(p);   
}
double ret;
double query(int p, int le, int ri, int l, int r, double &ls, double &rs)
{
    if (l <= le && ri <= r)
    {
        ret = max(ret, opt[p]);
        ls = lm[p]; rs = rm[p];
        return sum[p];
    }
    else
    {        
        int mid = (le + ri) >> 1;
        if (r <= mid) query(p<<1, le, mid, l, r, ls, rs);
        else if (l > mid) query(p<<1|1, mid+1, ri, l, r, ls, rs);
        else
        {
            double ls1, rs1, ls2, rs2; 
            double s1 = query(p<<1, le, mid, l, r, ls1, rs1);
            double s2 = query(p<<1|1, mid+1, ri, l, r, ls2, rs2);
            ret = max(ret, rs1 + ls2);
            ls = max(ls1, s1 + ls2);
            rs = max(rs2, s2 + rs1);
        }
    }
}
int main() 
{
    scanf("%d%d%d", &n, &m, &c);
    FOR(i, 1, n+1) scanf("%d", &x[i]);
    FOR(i, 1, n)
    {
        scanf("%lf", &p[i]);
        v[i] = 1.0*(x[i+1] - x[i]) / 2.0 - 1.0*p[i]/100.0*c;
    }
    build(1, 1, n-1);
    ans = 0.0;
    int a, b;
    REP(i, m)
    {
        scanf("%d%d", &a, &b);
        if (a == b) continue;
        ret = 0;
        double ls, rs;
        query(1, 1, n-1, a, b-1, ls, rs);
        ans += ret;
    }
    printf("%.9f\n", ans);
    return 0;
}
