#include <iostream>
#include <cstdio>
#include <cstring>
#define Maxn 100100
using namespace std;

int cash, ni, di, m, ans;
bool f[Maxn];

int main()
{
    while (scanf("%d", &cash) != EOF)
    {
        memset(f, false, sizeof(f));
        ans = 0;  f[0] = true;
        scanf("%d", &m);
        for (int i=0; i<m; i++)
        {
            scanf("%d%d", &ni, &di);
            for (int j=cash; j>=0; j--)
            {
                if (f[j])
                {
                  for (int cnt=ni, k=j+di; cnt>0 && k<=cash;cnt--, k+=di)
                  {
                      f[k] = true;
                      ans = max(ans, k);
                  }
                }
            }
            
        }
        printf("%d\n", ans);       
    }
    return 0;
    }
