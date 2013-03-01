#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <list>
#include <set>
#include <bitset>
#include <cctype>
#include <cmath>
#include <ctime>
#include <numeric>
#include <utility>
#include <stack>
#include <queue>
#include <deque>
#include <iomanip>
#define pb push_back
#define inf 9999999
using namespace std;
const int Maxn = 1<<22;
int n, s;
int rev[25], c[25];
int f[Maxn];
void init()
{
    int p[3], w, v;
    int dp[10];
    scanf("%d%d", &n, &s);
    for (int i=0; i<n; i++)
    {
        scanf("%d%d%d%d",&p[0], &p[1], &p[2], &rev[i]);
        for (int j=0; j<=7; j++) dp[j] = inf;
        dp[0] = 0;

        for (int t=0; t<3; t++)
        {
            if (t==0) w = 3;
            else
                if (t==1) w = 2;
                else
                    w = 1;
            for (int j=0; j<7; j++)
            {
                v = j+w;
                if (v > 7) v = 7;
                dp[v] = min(dp[v], dp[j] + p[t]);
            }
        }
        c[i] = dp[7];
     //   cout <<c[i] <<endl;
    }   
}
int dfs(int now)
{
    if (f[now] != -1) return f[now];
    if (now == 0) return f[now] = s;

    for (int i=0; i<n; i++)
        if ((1<<i)&now)
        {
            int tmp = dfs(now-(1<<i));
            if (tmp - c[i] > 0)
            {
                if (f[now] == -1) f[now] = tmp - c[i] + rev[i];
                else f[now] = max(f[now], tmp-c[i]+rev[i]);
                if (f[now] != -1 && now == (1<<n)-1) return f[now];
            }
        }
    return f[now];

}
void work()
{
    memset(f, -1, sizeof(f));
    int tar = (1<<n)-1;
    int ans = dfs(tar);
    if (ans <= 0) printf("no\n");
    else printf("%d\n", ans);   
}
int main()
{
    int T;
    scanf("%d", &T);
    for (;T>0;T--)
    {
        init();
        work();
    }
    return 0;
}
