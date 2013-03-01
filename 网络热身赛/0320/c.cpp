#include <iostream>
#include <cstdio>
using namespace std;

int f[40], ans;
int n,T, d[40];;


int main()
{
    f[1] = 1; f[2] = 2;
    for (int i=3; i<=30; i++) f[i] = f[i-1] + f[i-2];
    cin >>T;
    for (;T>0;T--)
    {
        scanf("%d", &n);
        memset(d, 0, sizeof(d));
        for (int i=30; i>=1; i--)
        {
            d[i-1] = n / f[i];
            n = n % f[i];            
        }
        ans = 0;
        for (int i=1; i<=30; i++) ans += f[i] * d[i];
        printf("%d\n", ans);   
    }
    system("pause");
    return 0;
    }
