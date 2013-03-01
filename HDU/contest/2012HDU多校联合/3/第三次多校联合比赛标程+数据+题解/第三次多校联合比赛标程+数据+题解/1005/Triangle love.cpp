#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
#define SIZE 6000
char g[SIZE][SIZE];
int n, rd[SIZE], cd[SIZE];
int main()
{
    freopen("Triangle love.in", "r", stdin);
    freopen("Triangle love.out", "w", stdout);
    int t, ca = 1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        bool flag = false;
        for(int i = 0; i < n; i++) scanf("%s", g[i]);
        for(int i = 0; i < n; i++)
        {
            int leftin = 0, leftout = 0, leftnum = 0;
            for(int j = 0; j < i; j++)
                if (g[i][j] == '1')
                    leftin += rd[j], leftout += cd[j], leftnum++;
            if (leftin != leftout + leftnum * (i - leftnum))
            {
                for(int left = 0; left < i && !flag; left++) if (g[i][left] == '1')
                    for(int right = 0; right < i && !flag; right++) if (g[left][right] == '1' && g[right][i] == '1')
                    {
                        flag = true;
                        goto lable;
                    }
            }
            for(int j = 0; j < i; j++)
            {
                if (g[i][j] == '1') rd[j]++, cd[i]++;
                if (g[j][i] == '1') cd[j]++, rd[i]++;
            }
        }
        lable:
        if (flag) printf("Case #%d: Yes\n", ca++);
        else printf("Case #%d: No\n", ca++);
    }
	return 0;
}
