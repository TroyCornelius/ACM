#include <stdio.h>
#define Maxn 200
#define Minnum -9999999999LL
using namespace std;

int T, n, m, k;
long long d[Maxn][Maxn], f[Maxn][Maxn];

void init()
{
     scanf("%d%d%d", &n, &m, &k);
     for (int i=0; i<n; i++)
       for (int j=0; j<m; j++)
         scanf("%I64d", &d[i][j]);   
     for (int i=1; i<=n+5; i++)
       for (int j=1; j<=m+5; j++)
         f[i][j] = Minnum;
     for (int i=0; i<n; i++) f[i][0] = d[i][0];
     }
void dp()
{
       for (int j=1; j<m; j++)
         for (int i=0; i<n; i++)
         {
            for (int x=0; x<n; x++)
             for (int y=j-1; y>=0; y--)
                {
                   if (k < (i-x)*(i-x)+(j-y)*(j-y)) break;
                   f[i][j] >?= f[x][y] + d[i][j];     
                }              
         }
     long long ans = Minnum;
     for (int i=0; i<n; i++)
       ans >?= f[i][m-1];     
     printf("%I64d\n", ans);
     }
int main()
{
    scanf("%d", &T);
    while (T > 0)
      {
          T--;
          init();
          dp();          
      }

    return 0;
    }
