#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define Maxn 100030
#define inf 999999999
#define pb push_back
using namespace std;
const int MOD = 1000000007;
int n, m, tot, total;
struct Tnode
{
       int s, t, si, ti;
       }bus[Maxn];
int b[Maxn*2], c[Maxn*2];
int t[Maxn*2], nx, ans;
int bsearch(int x)
{
    int lo=0, hi=total-1, mid=0;
    while (lo+1<hi)
    {
       mid = (lo+hi)>>1;
       if (c[mid] == x) return mid;
       if (c[mid] > x) hi = mid;
       else lo = mid;      
    }
    if (c[hi]==x) return hi;
    else if (c[mid]==x) return mid;
    else if (c[lo]==x) return lo;
    else return -1;
    }
void updata(int idx, int val)
{
     while (idx <= nx)
     {
        t[idx] = (t[idx] + val) % MOD;        
        idx += idx & -idx;           
     }
     }
int gsum(int idx)
{
    int ret = 0;
    while (idx > 0)
    {
       ret+=t[idx];
       ret%=MOD;
       idx-=idx&-idx;          
    }
    return ret;
    }
int query(int l, int r)
{
    int ret = gsum(r) - gsum(l-1);
    if (ret < 0) ret+=MOD;
    return ret;
    }
bool cmp(const Tnode &a, const Tnode &b)
{
     if (a.ti!=b.ti) return a.ti < b.ti;
     else return a.si < b.si;
     }
int main()
{
    scanf("%d%d", &n, &m);
    tot = 0;
    for (int i=0; i<m; i++) 
    {
        scanf("%d%d", &bus[i].s, &bus[i].t);
        b[tot++] = bus[i].s;
        b[tot++] = bus[i].t;        
    }
    b[tot++] = 0;
    sort(b, b+tot);
    total = 1;
    c[0] = b[0];
    for (int i=1; i<tot; i++)
    if (b[i] != c[total-1]) c[total++] = b[i];
    for (int i=0; i<m; i++)
    {
        bus[i].si = bsearch(bus[i].s) + 1;
        bus[i].ti = bsearch(bus[i].t) + 1;        
    }
    nx = bsearch(n);
    int tmp;
    if (nx == -1) printf("0\n");
    else
    {
        memset(t, 0, sizeof(t));
        nx++;
        sort(bus, bus+m, cmp);
        updata(1, 1);
        for (int i=0; i<m; i++)
        {
            tmp = query(bus[i].si, bus[i].ti-1);
            updata(bus[i].ti, tmp);     
        }
        ans = query(nx, nx);
        printf("%d\n", ans%MOD);    
    }   
   // system("pause");
    return 0;
    }
