#include <iostream>
using namespace std;

long long n, ans;
long long f[100][2], s[105];
long long sum[100][2], tot[100];;
int d[100];
void init()
{
     memset(f, 0, sizeof(f));
     memset(sum, 0, sizeof(sum));
     memset(s,0,sizeof(s));
     memset(tot, 0, sizeof(tot));
     f[1][1] = f[2][0] = 1;
     f[1][0] = f[2][1] = 0;
     s[1] = 1; s[2] = 3;
     for (int i=3; i<=79; i++)
       {
          f[i][0] = f[i-1][0] + f[i-2][0];
          f[i][1] = f[i-1][0];   
          s[i] = s[i-1] + (f[i][0] + f[i][1]) * i;           
       }
     sum[0][1] = sum[0][0] = 0;
     sum[1][1] = 1; sum[1][0] = 0;
     sum[2][0] = 1; sum[2][1] = 0;
     for (int i=3; i<=79; i++)
       {
          sum[i][0] = sum[i-1][1] + sum[i-1][0];
          sum[i][1] = sum[i-1][0] + f[i][1];              
       }   
     tot[0] = 1;
     for (int i=1; i<=79; i++)
       tot[i] = tot[i-1] + f[i][1]+f[i][0] - f[i-1][1]-f[i-1][0];   
     }
long long dfs(int len, long long rest)
{
     memset(d, 0, sizeof(d));
     long long ss = 0;
     long long ki = rest / len;
     d[len] = 1; d[len-1] = 0;  ss = ki;
     int i = len - 2;
     while (i>=1 && ki>0)
       {
          if (tot[i-1] >= ki)
            {
              d[i] = 0;    
              i--;                    
            }
          else
            {
              d[i] = 1; d[i-1] = 0;
              ki -= tot[i-1]; //(f[i-1][0] + f[i-1][1]);
              ss += ki;
              i-=2;                   
            }
       }
     long long tt = rest % len;
     if (tt != 0)
       {
          for (int j=1; j<len; j++)
            if (d[j]==0 && d[j+1] == 0)
              {
                d[j] = 1;
                for (int c=j-1; c>0; c--) d[c] = 0; 
                break;                       
              }
          for (int i=len; i>=1; i--)
            {
               if (d[i]==1) ss++;
               tt--;
               if (tt <= 0) break;                   
            }                  
       }
     return ss;
     }
int main()
{
   // freopen("11.in", "r", stdin);
    //freopen("11.out", "w", stdout);

    init();
    while (cin >>n)
    {
      ans = 0;
      int i;
      for (i=1 ; i<=79; i++)
        if (s[i] > n) break;
        else
        {
           ans += sum[i-1][0] + sum[i-1][1];           
        }
       ans += sum[i-1][1] + sum[i-1][0];
       ans += dfs(i, n - s[i-1]);       
       cout <<ans <<endl;
    }
    return 0;
    }
