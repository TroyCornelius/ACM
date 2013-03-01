#include <iostream>
using namespace std;

int n;
unsigned long long f[55][3];
unsigned long long dp(int m)
{
     memset(f, 0, sizeof(f));
     f[1][0] =  f[2][1] = f[2][2] = 1;
     unsigned long long ans;
     for (int i=3; i<=m; i++)
       {
          for (int now=0; now<3; now++)
            {
               if (i==m && now==0) continue;
               for (int t=0; t<3; t++)
                 {
                   if (t != now) f[i][now] += f[i-2][t];
                   else
                     f[i][now] += f[i-2][t] * 2;     
                 }
            }              
       }
     return ans = (f[m][1] + f[m][2]) * 3;     
     }
int main()
{
    while (scanf("%d", &n) != EOF)
      {
         if (n==1) cout <<"3" <<endl;
         else 
         if (n==2) cout <<"6" <<endl;
         else
         cout <<dp(n) <<endl;          
      }
    return 0;
    }
