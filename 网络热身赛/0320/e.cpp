#include <iostream>
#include <cstdio>
using namespace std;

int n, m, d[110];
long long f[110][110], ans;
int main()
{
    while (scanf("%d%d",&n,&m))
    {
          if (n==0 && m==0) break;
          for (int i=0; i<n; i++) scanf("%d", &d[i]);
          memset(f, 0, sizeof(f));
          for (int i=0; i<n; i++) f[i][1] = 1;
          for (int i=1; i<n; i++)
          {
              for (int j=2; j<=m; j++)
              {
                  for (int k=0; k<i; k++)
                    if (d[k] < d[i]) f[i][j] += f[k][j-1];                  
              }              
          }
          ans = 0;
          for (int i=0; i<n; i++) ans += f[i][m];
          cout <<ans <<endl;
    }
    system("pause");
    
    return 0;
    }
