#include <iostream>
#include <cstdio>
#include <algorithm>
#define Maxn 100100
using namespace std;

int n, k, d[Maxn], ans;
int main()
{
    while (~scanf("%d%d", &n, &k))
    {
        for (int i=0; i<n; i++) scanf("%d", &d[i]);
        sort(d, d+n);
        ans = 0;
        int i = 0, j =0;
        for (; i<n && j<n; i++)
        {
            while (j < n && d[i]+k > d[j]) j++;
            if (j < n && d[j] == d[i] + k) ans++;
        }
        printf("%d\n", ans);        
    }
    return 0;
}
