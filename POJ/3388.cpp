#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
#define Maxn 50100
using namespace std;

int n, k;
struct element
{
       int id, tot;
       bool operator <(const element &a)const
       {
            return tot > a.tot;
       }
       }d[Maxn];
inline bool check(int len)
{
     int cnt = n;
     for (int i=1; i<=k; i++)
     {
         cnt -= d[i].tot/len;
         if (cnt <= 0) return true;         
     }
     return false;
     }
void print(int ans)
{
     int cnt = n;
     printf("%d\n", ans);
     for (int i=1; i<=k; i++)
       for (int j=d[i].tot; j-ans>=0 && cnt; j-=ans)
       {
         printf("%d\n", d[i].id);     
         cnt--;
       }

     }
void work()
{
     int lo = 1, hi = n, mid=n;
     while (lo+1<hi)
     {
         mid = (lo+hi)>>1;
         if (check(mid)) lo = mid;
         else hi = mid;           
     }     
     if (check(hi)) print(hi);
     else
     if (check(mid)) print(mid);
     else
     if (check(lo)) print(lo);
     }
int main()
{
    scanf("%d%d", &n, &k);
    for (int i=1; i<=k; i++) 
    {
        scanf("%d", &d[i].tot);
        d[i].id = i;        
    }
    sort(d+1, d+1+k);
    work();
    return 0;
    }
