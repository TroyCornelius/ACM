#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 105;

inline int Max(int x, int y) { return x > y ? x : y; }
int cost[MAXN], seg[MAXN][MAXN], f[MAXN][2];
void Solve(int n)
{
        int i, j, k;
        int oo = -100000000;
        for(i = 0; i <= n; ++i) f[i][0] = f[i][1] = oo;
        f[0][0] = 0;
        for(i = 1; i <= n; ++i)
        {
                f[i][0] = Max(f[i - 1][0], f[i - 1][1]);
                for(j = 0; j < i; ++j)
                {
                        for(k = j + 1; k <= i; ++k)
                        {
                                f[j][0] += seg[k][i];
                        }
                        f[j][0] -= cost[i];
                        f[i][1] = Max(f[i][1], f[j][0]);
                }
        }
        int ans = Max(f[n][0], f[n][1]);
        if(ans < 0) ans = 0;
        printf("%d\n",ans);

}

int main()
{
	int i, n, m, a, b, c, T;
	freopen("data1.in","r",stdin);
	freopen("cmp.out", "w", stdout);
	scanf("%d", &T);
	while(T--)
	{
	        scanf("%d", &n);
	        for(i = 1; i <= n; ++i) scanf("%d", &cost[i]);
	        scanf("%d", &m);
	        memset(seg,0,sizeof seg);
		for(i = 0; i <  m; ++i)
		{
			scanf("%d %d %d", &a, &b, &c);
			seg[a][b] += c;
		}
		Solve(n);
	}
	return 0;
}
