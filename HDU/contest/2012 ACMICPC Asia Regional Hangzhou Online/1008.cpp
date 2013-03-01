/*
 * Author:  Troy
 * Created Time:  2012/9/23 12:25:04
 * File Name: 1008.cpp
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
#define Maxn 200000
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

struct Tnode
{
       int num, id;
       }d[Maxn];
int t[20][Maxn], s[20][Maxn];
int n, m;
bool cmp(const Tnode &a, const Tnode &b)
{
     return a.num < b.num;
     }
void build(int h, int l, int r)
{
     if (l == r) return ;
     int mid = (l+r)>>1, p = 0;
     for (int i=l; i<=r; i++)
     {
         if (t[h][i] <= mid)
         {
            t[h+1][l+p] = t[h][i];
            s[h][i] = ++p;   
         }
         else
         {
             t[h+1][mid+1+i-l-p] = t[h][i];
             s[h][i] = p;             
         }   
     }
     build(h+1, l, mid);
     build(h+1, mid+1, r);
     }
int find(int h, int l, int r, int le, int ri, int k)
{
    if (le == ri) return t[h][le];
    int mid = (l+r)>>1;
    int ls=0, rs = s[h][ri];
    if (le > l) ls = s[h][le-1];
    if (rs - ls >= k) return find(h+1, l, mid, l+ls, l+rs-1, k);
    else return find(h+1, mid+1, r, mid+1+le-l-ls, mid+ri-l+1-rs, k-(rs-ls));    
}

int get_ans(int x, int y, int H) {
    int lo = 1, hi = y - x + 1, mid;
    int ret = 0;
    while (lo <= hi) {
        mid = (lo + hi)>>1;
        int tmp = d[find(0, 1, n, x, y, mid)].num;
        if (tmp <= H) {
            ret = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    return ret;
}
int main()
{
    int T, ca = 0;
    sf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i=1; i<=n; i++)
        {
            scanf("%d", &d[i].num);
            d[i].id = i;        
        }
        sort(d+1, d+n+1, cmp);
        for (int i=1; i<=n; i++) t[0][d[i].id] = i;    
        build(0, 1, n);
        int x, y, H;
        pf("Case %d:\n", ++ca);
        for (int i=0; i<m; i++)
        {
            scanf("%d%d%d", &x, &y, &H);  
            x++, y++;
            //printf("%d\n", d[find(0, 1, n, x, y, kth)].num);        
            pf("%d\n", get_ans(x, y, H));
        }
    }
    return 0;
}

