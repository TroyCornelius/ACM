#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int ans[15000];
int n;
bool vis[500000];
int main()
{
    int a = 0, tmp;
    ans[0] = 0;
    memset(vis, false, sizeof(vis));
    vis[0] = true;
    for (int i=1; i<=13000; i++)
    {
        if (ans[i-1] > i && !vis[ans[i-1]-i]) ans[i] = ans[i-1] - i;
        else ans[i] = ans[i-1] + i;
        vis[ans[i]] = true;
        
    }
    while (scanf("%d", &n))
    {
       if (n == -1) break;
       printf("%d\n", ans[n]);          
    }
    
    
    return 0;
    }
