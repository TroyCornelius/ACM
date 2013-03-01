#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define Maxn 128
using namespace std;
const int inf = 1<<30;
const int upp[]={0,1,1,2,1,2,2,3};
const int low[8][8]={
      {0,1,1,1,1,2,1,1},
      {0,0,1,1,1,1,1,1},
      {0,1,0,1,1,2,1,1},
      {0,0,0,0,1,1,1,1},
      {0,1,1,1,0,1,1,1},
      {0,0,1,1,0,0,1,1},
      {0,1,0,1,0,1,0,1},
      {0,0,0,0,0,0,0,0}
      };
int n, k, matr[Maxn][3], ans;
int dp[Maxn][8][8], sum[Maxn][8];
int main()
{
    /*for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++) cout <<low[i][j] <<" ";
        cout <<endl;
        
    }*/
    while (~scanf("%d%d", &n, &k))
    {
          for (int j=0; j<3; j++)
            for (int i=1; i<=n; i++)
              scanf("%d", &matr[i][j]);
          
          for (int i=0; i<=n; i++)
            for (int j=0; j<8; j++)
              for (int t=0; t<=k; t++)
                dp[i][j][t] = -inf;
          memset(sum, 0, sizeof(sum));
          
          for (int i=1; i<=n; i++)
            for (int j=0; j<8; j++)
              for (int t=0; t<3; t++)
                sum[i][j] += ((1<<t)&j) ? matr[i][t] : 0;

          /* for (int i=0; i<=n; i++)
           {
               for (int j=0; j<8; j++) cout <<sum[i][j]<<" ";
               cout <<endl;
               
           } */

          dp[0][0][0] = 0;
          for (int i=0; i<n; i++)
            for (int ns=0; ns<8; ns++)
              for (int t=0; t<=k; t++)
              if (dp[i][ns][t] != -inf)
              {
                  for (int ts=0; ts<8; ts++)
                    for (int c=low[ns][ts]; c<=upp[ts]; c++)
                    if (t + c <= k)
                    {
                        dp[i+1][ts][t+c] = max(dp[i+1][ts][t+c], dp[i][ns][t] + sum[i+1][ts]);                          
                    }                  

              }
              //cout <<i+1<<": ";
                  for (int p=0; p<8; p++) cout <<dp[n-1][p][k] <<" ";
                  cout <<endl<<"-----------" <<endl;
                  for (int p=0; p<8; p++) cout <<dp[n-2][p][k-1] <<" ";
                  cout <<endl<<"-----------" <<endl;
          ans = -inf;
          for (int i=0; i<8; i++) ans = max(ans, dp[n][i][k]);
          printf("%d\n", ans);
    }
    return 0;
    }
