#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <windows.h>
using namespace std;

#define INF 0x3fffffff
#define LL long long

int main()
{
    freopen("in.txt", "w", stdout);
    srand(GetTickCount());
    int i, j, t = 10;
    int n, m;
    printf("%d\n", t);
    for(i = 1; i <= t; i++)
    {
        n = 1 + rand() % 100000;
        m = 1 + rand() % 100000;
        printf("%d %d\n", n, m);
        for(j = 1; j <= n; j++)
        {
            int si = 1 + rand() % 1000000000;
            int ti = 1 + rand() % 1000000000;
            if(si <= ti)
                printf("%d %d\n", si, ti);
            else
                j--;
        }
        for(j = 1; j <= m; j++)
        {
            int ti = 1 + rand() % 1000000000;
            printf("%d\n", ti);
        }
    }
    return 0;
}
