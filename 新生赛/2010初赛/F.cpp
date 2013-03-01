#include <iostream>
#include <algorithm>
using namespace std;
struct fruit
{
       int ti, wi;
       }d[1005];
int n, lasttime, ans;

bool cmp(const fruit &a, const fruit &b)
{
     if (a.ti != b.ti) return a.ti > b.ti;
     else return a.wi < b.ti;
     }
int main()
{
    scanf("%d", &n);
    lasttime = 0;
    for (int i=0; i<n; i++)
    {
      scanf("%d%d", &d[i].wi, &d[i].ti);
      lasttime >?= d[i].ti;
    }
    sort(d, d+n, cmp);
    ans = 0;
    int tmp, dx;
    for (int day=lasttime; day>0; day--)
      {
         tmp = 0;
         for (int i=0; i<n; i++)
           if (d[i].ti>=day && d[i].wi > 0) 
             {
                if (d[i].wi > tmp)
                  {
                    tmp = d[i].wi;
                    dx = i;                            
                  }
             }
           else
           if (d[i].ti < day) break;
         ans += tmp;             
         d[dx].wi = -1;
      }
    cout <<ans <<endl;

    return 0;
    }
