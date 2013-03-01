#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int T, n, ans;
int d[1010];
int main()
{
  //  freopen("C-small-attempt0.in", "r", stdin);
  //  freopen("C-small-attempt0.out", "w", stdout);
    cin >>T;
    for (int t=1; t<=T; t++)
    {
       scanf("%d", &n);
       for (int i=0; i<n; i++) scanf("%d", &d[i]);
       ans = -1;
       int sa, sb,xa,xb;
       for (int p=1; p<(1<<n)-1; p++)
       {
          xa = -1; xb=-1; sa=0; sb=0;
          for (int j=0; j<n; j++)
          {
              if ((1<<j)&p)
              {
                 if (xa==-1) xa = d[j];
                 else xa^=d[j];
                 sa += d[j];          
              }
              else
              {
                  if (xb==-1) xb = d[j];
                  else xb^=d[j];
                  sb += d[j];                  
              }              
          }
          if (xa == xb) ans >?= max(sa, sb);           
       }
       if (ans == -1) printf("Case #%d: NO\n", t);
       else
       printf("Case #%d: %d\n", t, ans);        
    }
    
    
    
    return 0;
    }
