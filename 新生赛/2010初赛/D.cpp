#include <iostream>
#include <algorithm>
#include <functional>
#include <cmath>
#define Maxn 100005
using namespace std;

int T, n, m;
int sal[Maxn], peo[Maxn];

void init()
{
     scanf("%d", &n);
     for (int i=0; i<n; i++) scanf("%d", &sal[i]);
     scanf("%d", &m);
     for (int i=0; i<m; i++) scanf("%d", &peo[i]);
     sort(sal, sal+n);     
     }
int binary_search(int d)
{
    int lo = 0, hi = n-1, mid;
    while (lo+1 < hi)
      {
          mid = (lo+hi)/2;
          if (sal[mid] > d) hi = mid;
          else lo = mid;
      }
    int tmp=999999999, ret;
    for (int i=max(0, lo-1); i<=min(n-1, hi+1); i++)
      {
        if (abs(sal[i]-d) < tmp)
          {
             tmp = abs(sal[i]-d);
             ret = i;                          
          }             
      }
    return ret;
    }
void work()
{
     for (int i=0; i<m; i++)
       {
          int loc = binary_search(peo[i]);
          printf("%d\n", sal[loc]);              
       }
     printf("\n");
     }
int main()
{
    scanf("%d", &T);
    for (;T>0;T--)
      {
         init();
         work();                  
      }
    return 0;
    }
