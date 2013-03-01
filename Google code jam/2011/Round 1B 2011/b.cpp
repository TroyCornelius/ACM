#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional> 
#define Maxn 1000010
using namespace std;


int n, T, C;
double D;
double pos[Maxn];
struct Tnode
{
       int p, v;
       }d[210];
inline bool check(double tt)
{
     double last = pos[0] - tt;
     for (int i=1; i<n; i++)
     {
         double tmp = last + D;
         if (pos[i] < tmp)
         {
            if (pos[i] + tt < tmp) return false;
            last = tmp;
         }
         else
         {
             double t1 = min(tt, pos[i] - tmp);
             last = pos[i] - t1;             
         }      
     }
     return true;
     }
double work()
{
     double le=0.0, ri=D*double(n), mid;
     for (int w=0; w<40; w++)
     {
         mid = (le + ri) / 2.0;
         if (check(mid)) ri = mid;
         else le = mid;         
     }
     return mid;
     }
bool cmp(const Tnode a, const Tnode b)
{
     return a.p < b.p;
     }
int main()
{
   // freopen("B-large.in", "r", stdin);
   // freopen("B-large.out", "w", stdout);
    cin >>T;
    for (int t=1; t<=T; t++)
    {
        cin >>C >>D;
        int p, v;
        n = 0;
        for (int i=0; i<C; i++)
        {
            scanf("%d%d", &d[i].p, &d[i].v);
        }
        sort(d, d+C, cmp);
        for (int i=0; i<C; i++)
        {
            while (d[i].v--) pos[n++] = double(d[i].p);
        }       
        printf("Case #%d: %.7lf\n", t, work());
        
    }
    
    
    return 0;
    }
