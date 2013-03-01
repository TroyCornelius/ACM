#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <functional>
#include <cctype>
#include <cmath>
using namespace std;

struct Tnode
{
       double sx, sy;
       double wi;
       }d[1010];
int T, n;
double x, s, r;
double ans, t;
bool cmp(const Tnode &a, const Tnode &b)
{
     return a.wi < b.wi;
     }
int main()
{
   // freopen("A-large.in", "r", stdin);
//    freopen("A-large.out", "w", stdout);
    cin >>T;
    for (int ct=1; ct<=T; ct++)
    {
        scanf("%lf%lf%lf%lf%d", &x, &s, &r, &t, &n);
        double tmp = x;
        for (int i=0; i<n; i++) 
        {
            scanf("%lf%lf%lf", &d[i].sx, &d[i].sy, &d[i].wi);
            tmp -= (d[i].sy - d[i].sx);
        }
        sort(d, d+n, cmp);      
        ans = min(t, tmp / r);
        tmp -= r * ans;
        t -= ans;
        if (t == 0.0) 
        {
           ans += tmp / s;
           for (int i=0; i<n; i++) 
             ans += (d[i].sy-d[i].sx) / (s + d[i].wi);
        }
        else
        {
            
            for (int i=0; i<n; i++)
            {
                if (t != 0.0)
                {
                   double c = r + d[i].wi;
                   double st = (d[i].sy - d[i].sx) / c;
                   
                   if (st < t)
                   {
                      ans += st;
                      t -= st;                          
                   }
                   else
                   {
                       double tt = ((d[i].sy - d[i].sx) - t * c) / (s + d[i].wi);
                       ans += (tt + t);
                       t = 0.0;                   
                   }
                      
                }
                else
                ans += (d[i].sy-d[i].sx) / (s + d[i].wi);
            }
            
        }
        printf("Case #%d: %.6lf\n", ct, ans);
    }
    
    return 0;
    }
