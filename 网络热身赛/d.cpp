#include <iostream>
#include <cstdio>
#define Maxn 100010
using namespace std;

int T, n, ans;
int f[Maxn], d[Maxn];
int main()
{
    cin >>T;
    for (int i=1; i<=T; i++)
    {
        scanf("%d", &n);
        for (int j=1; j<=n; j++) 
        {
            scanf("%d", &d[j]);    
        }
        int s = d[1];
        ans = d[1];
        for (int j=2; j<=n; j++)
        {
            s = s>0?s:0;
            s += d[j];
            ans >?= s;            
        }

        printf("Case %d:\n", i);
        cout <<ans <<endl;
        if (i != n) printf("\n");
        
    }

    return 0;
    }
