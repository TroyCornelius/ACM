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
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define Maxn 10100
using namespace std;
const int inf = 1<<30;
string s; 
int n, dp[128][64][2][2];  //1 for minn
int main()
{
  while (1){
    cin >>s;
    cin >>n;
    memset(dp, 0, sizeof(dp));
    for (int x=0; x<=n; x+=2)
    if (s[0] == 'F') dp[0][x][0][0] = dp[0][x][0][1] = 1, dp[0][x][1][0] = -inf, dp[0][x][1][1] = inf;
    else dp[0][x+1][0][0] = dp[0][x+1][0][1] = 1, dp[0][x][0][0] = -inf, dp[0][x][0][1] = inf;
    int len = s.length();
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] =='F')
        {
           for (int j=0; j<=n; j++)
           {
              for (int t=0; t<2; t++)
              {
                  for (int x=0; x<=j; x+=2)
                  {
                // dp[i][j][t][0] = max(dp[i][j][t][0], max((dp[i-1][j][t][0] + (t == 1 ? -1 : 1)), (dp[i-1][j][t][1] + (t==1?-1:1)) ));
                    if (dp[i-1][j-x][t][0] >= -len) dp[i][j][t][0] = max(dp[i][j][t][0], dp[i-1][j-x][t][0]+(t==1?-1:1));//
               //   dp[i][j][t][0] = max(dp[i][j][t][0],max(dp[i-1][j-x][t][0]+(t==1?-1:1), dp[i-1][j-x][t][1]+(t==1?-1:1)));
                  //  dp[i][j][t][1] = min(dp[i][j][t][1], min(dp[i-1][j][t][0] + (t == 1 ? -1 : 1), dp[i-1][j][t][1] + (t==1?-1:1)));
                    if (dp[i-1][j-x][t][1] <= len) dp[i][j][t][1] = min(dp[i][j][t][1], dp[i-1][j-x][t][1]+(t==1?-1:1));//min(dp[i-1][j-x][t][0]+(t==1?-1:1), dp[i-1][j-x][t][1]+(t==1?-1:1)));
                  }
                 if (j!=0)
                 { 
                    for (int x=1; x<=j; x+=2)
                    {
                       if (dp[i-1][j-x][1-t][0]>=-len) dp[i][j][t][0] = max(dp[i][j][t][0], dp[i-1][j-x][1-t][0]);//max(dp[i-1][j-x][1-t][0], dp[i-1][j-x][1-t][1]));   
                       if (dp[i-1][j-x][1-t][1]<=len)  dp[i][j][t][1] = min(dp[i][j][t][1], dp[i-1][j-x][1-t][1]);//min(dp[i-1][j-x][1-t][0], dp[i-1][j-x][1-t][1]));  
                    }
                 }
              }
           }
        }
        else
        if (s[i] == 'T')
        {
           for (int j=0; j<=n; j++)
           {
               for (int t=0; t<2; t++)
               {
                   for (int x=0; x<=j; x+=2)
                   {
                     if (dp[i-1][j-x][1-t][0]>=-len) dp[i][j][t][0] = max(dp[i][j][t][0], dp[i-1][j-x][1-t][0]);//max(dp[i-1][j-x][1-t][0], dp[i-1][j-x][1-t][1]));
                     if (dp[i-1][j-x][1-t][1]<=len)  dp[i][j][t][1] = min(dp[i][j][t][1], dp[i-1][j-x][1-t][1]);//min(dp[i-1][j-x][1-t][0], dp[i-1][j-x][1-t][1]));
                   }
                   if (j!=0)
                   {
                      for (int x=1; x<=j; x+=2)
                      {
                         //dp[i][j][t] = max(dp[i][j][t], dp[i-1][j-x][1-t] + (t==1?1:-1));          
                         if (dp[i-1][j-x][t][0]>=-len) dp[i][j][t][0] = max(dp[i][j][t][0], dp[i-1][j-x][t][0] + (t==1?-1:1));//max(dp[i-1][j-x][t][0] + (t==1?-1:1),dp[i-1][j-x][t][1] + (t==1?-1:1)));
                         if (dp[i-1][j-x][t][1] <=len) dp[i][j][t][1] = min(dp[i][j][t][1], dp[i-1][j-x][t][1] + (t==1?-1:1));//min(dp[i-1][j-x][t][0] + (t==1?-1:1),dp[i-1][j-x][t][1] + (t==1?-1:1)));
                      }                 
                   }                   
               }
           }
        } 
              
    }
     int nn = s.length()-1;
     int tmp = max(abs(dp[nn][n][0][1]), abs(dp[nn][n][1][0]));
     //cout <<dp[nn][n][0][1] <<" "<<dp[nn][n][1][0] <<endl;
     cout <<max(tmp ,max(abs(dp[nn][n][0][0]), abs(dp[nn][n][1][1]))) <<endl;
     
     nn = len - 11;
     cout <<dp[nn][n][0][0] <<" "<<dp[nn][n][0][1]<<" "<<dp[nn][n][1][0]<<" "<<dp[nn][n][1][1]<<endl;
     cout <<dp[nn][3][0][0] <<" "<<dp[nn][3][0][1]<<" "<<dp[nn][3][1][0]<<" "<<dp[nn][3][1][1]<<endl;
   //  nn++;
    // cout <<dp[nn][n][0][0] <<" "<<dp[nn][n][0][1]<<" "<<dp[nn][n][1][0]<<" "<<dp[nn][n][1][1]<<endl;
}
    return 0;
    }
