#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m, ans;
char g[30][30];
int st[30];
inline int calc(int k)
{
       int s1=0, s2=0, tmp=0;
       for (int i=0; i<n; i++)
         if ((1<<i)&k) s1++;
         else tmp |= st[i];
       for (int i=0; i<m; i++)
         if ((1<<i)&tmp) s2++;
       return s1>s2?s1:s2;    
       }
inline bool check(int k)
{
       for (int i=0; i<n; i++)
       if (((1<<i)&k) && (st[i]==0)) return false;
       return true;
       }
int main()
{
    ios::sync_with_stdio(false);
    int tmp;
    while (cin >>n >>m)
    {
          memset(st, 0, sizeof(st));
          ans = min(n, m);
          for (int i=0; i<n; i++)
          {
            for (int j=0; j<m; j++)
            {
                cin >>g[i][j];
                if (g[i][j] == '*') st[i] |= (1<<j);
            }
          }          
          for (int i=0; i<(1<<n); i++)
          {
              if (!check(i)) continue;
              tmp = calc(i);
              if (tmp < ans) ans = tmp;
              if (ans == 1) break;
          }
          cout <<ans <<endl;
    }    
    return 0;
    }
