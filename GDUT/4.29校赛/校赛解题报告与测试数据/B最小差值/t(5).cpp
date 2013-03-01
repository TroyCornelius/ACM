#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int x, int y) { return x < y; }

int main()
{
        int T, i, n, a, ans, minl;
        //freopen("data5.in", "r", stdin);
        //freopen("data5.out", "w", stdout);
        scanf("%d", &T);
        while(T--)
        {

                scanf("%d", &n);
                scanf("%d", &a);
                minl = a;
                ans = 2000000000;
                for(i = 1; i < n; i++)
                {
                        scanf("%d", &a);
                        if(ans > minl - a) ans = minl - a;
                        if(minl > a) minl = a;
                }
                printf("%d\n", ans);
        }
        return 0;
}
