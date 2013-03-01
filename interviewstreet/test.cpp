#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;


int cnt, a[100];
bool vis[100];
void dfs(int idx, int num)
{
    if (num == 0)
    {
        cnt++;
        for (int i=0; i<idx; i++) cout <<a[i]<<" ";
        cout <<endl;
        return;
    }
    for (int i=1; i<=num; i++)
        if (!vis[i])
        {
            if (num - i < 0) break;
            vis[i] = true; a[idx] = i;
            dfs(idx+1, num-i);
            vis[i] = false;
        }
    return;
}
int main()
{
    int d;
    cnt = 0;
    memset(vis, false, sizeof(vis));
    while (cin >>d) dfs(0, d);
    return 0;
}
